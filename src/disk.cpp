#include "../headers/disk.h"
#include "../headers/descriptor_table.h"
#include "../headers/directory_table.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char secondary_mem[DISK_CAPACITY];
char primary_mem[RAM_CAPACITY];


int write_onDisk(char *file, char *fileName) {

    printf("Tentando escrever um arquivo");
        
    int mem_address = check_free_disk(strlen(file));
    if (mem_address == -1)
        return mem_address;
    else {
        for (unsigned int i = 0; i < strlen(file); ++i) {
            secondary_mem[i+mem_address] = file[i];
        }
        int fd = generate_fd(); //cria um filedescriptor para o file
        insert_tuple_descrip_table(fd, mem_address, strlen(file));
        insert_tuple_direct_table(fd, fileName);
        return 1;
    }
}


int check_free_disk(int size) {

    int index = -1;
    int empty_spaces;
    for (int i = 0; i <= DISK_CAPACITY - size; i++) {
        if (secondary_mem[i] == '\0') {
            empty_spaces = 0;
            for (int j = i; j < i + size; j++) {
                if (secondary_mem[j] != '\0') break; //se encontrou algum espaço não vazio
                else if (++empty_spaces == size) return i;
            }
        }

    }
    return index;
}


void read_fromDisk(char *requestedfile, char requestedfile_content[100]) {
    int id_reqfile = find_file_id(requestedfile);
    int file_address_and_size[2];
    get_address_size_from_id(id_reqfile, file_address_and_size);
    
    for (int i = 0; i < file_address_and_size[1]; i++) {
        requestedfile_content[i] = secondary_mem[file_address_and_size[0]+i];   
    }
    requestedfile_content[file_address_and_size[1]] = '\0';
    
}

void delete_fromDisk(char *file){
    int id_reqfile = find_file_id(file);
    int file_address_and_size[2];
    get_address_size_from_id(id_reqfile, file_address_and_size);

    for (int i = file_address_and_size[0]; i < file_address_and_size[0] + file_address_and_size[1]; i++) {
        secondary_mem[i] = '\0';   
    }

}