#include "../headers/memory.h"
#include "../headers/descriptor_table.h"
#include "../headers/directory_table.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char secondary_mem[DISK_CAPACITY];
char primary_mem[RAM_CAPACITY];

void init_disk(){
    for(unsigned int i = 0; i < DISK_CAPACITY; i++){
        secondary_mem[i] = ' ';
    }
}

void init_ram(){
    for(unsigned int i = 0; i < RAM_CAPACITY; i++){
        primary_mem[i] = ' ';
    }
}

int write_onDisk(char *file, char *fileName) {

    //printf("Tentando escrever um arquivo no disk!");
        
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
    printf("Attempting to locate requestedfile id on the directory_table\n");
    int id_reqfile = find_file_id(requestedfile);
    if(id_reqfile==-1)
        printf("Failed to located requestedfile id on the directory_table\n");
    else
        printf("Found requestedfile id (%d) on the directory_table\n", id_reqfile);
    
    int file_address_and_size[2];

    printf("Attempting to get address size from the id (%d)\n", id_reqfile);
    get_address_size_from_id(id_reqfile, file_address_and_size);
    printf("Found address size from the id (%d)\n", id_reqfile);
        
    for (int i = 0; i < file_address_and_size[1]; i++) {
        requestedfile_content[i] = secondary_mem[file_address_and_size[0]+i];   
    }
    printf("File content and address at the secondary_mem retrieved\n");
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

void open_file(char* file_name){
    //DMA:
    //Vai no HD e pega o conteúdo desse arquivo:
    char file_content[100];
    read_fromDisk(file_name, file_content);
    //Vê se tem espaço na RAM pra colocar esse arquivo:
    //Se tiver, coloca o arquivo na ram
    write_on_ram(file_content);
    
}

int check_free_ram(int size) {

    int index = -1;
    int empty_spaces;
    for (int i = 0; i <= RAM_CAPACITY - size; i++) {
        if (primary_mem[i] == '\0') {
            empty_spaces = 0;
            for (int j = i; j < i + size; j++) {
                if (primary_mem[j] != '\0') break; //se encontrou algum espaço não vazio
                else if (++empty_spaces == size) return i;
            }
        }

    }
    return index;
}

int write_on_ram(char* file_content){
    //printf("Tentando escrever um arquivo na RAM!\n\n\n");
        
    printf("Locating free space at the RAM.\n");    
    int adress_on_ram = check_free_ram(strlen(file_content));
    if (adress_on_ram == -1) {
        printf("There isn't enough space at the RAM.\n");
        return adress_on_ram;
    }
    else {
        for (unsigned int i = 0; i < strlen(file_content); ++i) {
            primary_mem[i+adress_on_ram] = file_content[i];
        }
        printf("File content copied to the RAM.\n");
        return 1;
    }
    //printf("ERROR in write_on_ram");
}