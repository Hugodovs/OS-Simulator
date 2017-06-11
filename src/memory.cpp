#include "../headers/memory.h"
#include "../headers/descriptor_table.h"
#include "../headers/directory_table.h"
#include "../headers/ram_file_table.h"
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
    for(unsigned int i = 0; i < RAM_CAPACITY; i++) {
        primary_mem[i] = ' ';
    }
}

int write_onDisk(char *file, char *fileName) {

    //printf("Tentando escrever um arquivo no disk!");

    int disk_address = check_free_disk(strlen(file));
    if (disk_address == -1)
        return disk_address;
    else {
        for (unsigned int i = 0; i < strlen(file); ++i) {
            secondary_mem[i+disk_address] = file[i];
        }
        int fd = generate_fd(); //cria um filedescriptor para o file
        insert_tuple_descrip_table(fd, disk_address, strlen(file));
        insert_tuple_direct_table(fd, fileName);
        return 1;
    }
}


int check_free_disk(int size) {

    int index = -1;
    int empty_spaces;
    for (int i = 0; i <= DISK_CAPACITY - size; i++) {
        if (secondary_mem[i] == ' ') {
            empty_spaces = 0;
            for (int j = i; j < i + size; j++) {
                if (secondary_mem[j] != ' ') break; //se encontrou algum espaço não vazio
                else if (++empty_spaces == size) return i;
            }
        }

    }
    return index;
}


int read_fromDisk(char *requestedfile, char requestedfile_content[100]) {
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

    return file_address_and_size[1];

}

void delete_fromDisk(char *file){
    int id_reqfile = find_file_id(file);
    int file_address_and_size[2];
    get_address_size_from_id(id_reqfile, file_address_and_size);

    for (int i = file_address_and_size[0]; i < file_address_and_size[0] + file_address_and_size[1]; i++) {
        secondary_mem[i] = '\0';
    }

}



void open_file(char* file_name, char* mode){
    //DMA:
    //Vai no HD e pega o conteúdo desse arquivo:
    char file_content[30];
    int file_size = read_fromDisk(file_name, file_content);
    //Vê se tem espaço na RAM pra colocar esse arquivo:
    //Se tiver, coloca o arquivo na ram
    int ram_file_address = write_on_ram(file_content);

    insert_tuple_file_ram_table(file_name, mode, ram_file_address, file_size);

}

int check_free_ram(int size) {

    int index = -1;
    int empty_spaces;
    for (int i = 0; i <= RAM_CAPACITY - size; i++) {
        if (primary_mem[i] == ' ') {
            empty_spaces = 0;
            for (int j = i; j < i + size; j++) {
                if (primary_mem[j] != ' ') break; //se encontrou algum espaço não vazio
                else if (++empty_spaces == size) return i;
            }
        }

    }
    return index;
}

int write_on_file(char* file_name, char* input) {
  int file_id = find_file_id(file_name);
  printf("%d\n", files_ram_table[file_id].file_ptr);
  for (unsigned int i = 0; i < strlen(input); i++) {
    primary_mem[files_ram_table[file_id].file_ptr] = input[i];
    files_ram_table[file_id].file_ptr++;
    print_ram_table();
  }

  files_ram_table[file_id].file_size = files_ram_table[file_id].file_ptr;

  return 1;

}

//copia o arquivo da memoria RAM para o HD e apaga da RAM
void close_file(char* file_name) {
  int file_id = find_file_id(file_name);
  int ram_file_address = files_ram_table[file_id].ram_file_address;
  int file_hd_address_size[2];
  get_address_size_from_id(file_id, file_hd_address_size);
  int file_ram_size = files_ram_table[file_id].file_size;

  int a = file_hd_address_size[0];
  int b = ram_file_address;

  int aux;
  for (int i = 0; i < file_ram_size; i++) {
    aux = primary_mem[b];
    primary_mem[b++] = ' ';
    secondary_mem[a++] = aux;
  }


}

int write_on_ram(char* file_content) {
    //printf("Tentando escrever um arquivo na RAM!\n\n\n");

    printf("Locating free space at the RAM.\n");
    int address_on_ram = check_free_ram(strlen(file_content));
    if (address_on_ram == -1) {
        printf("There isn't enough space at the RAM.\n");
        return address_on_ram;
    }
    else {
        for (unsigned int i = 0; i < strlen(file_content); ++i) {
            primary_mem[i+address_on_ram] = file_content[i];
        }
        printf("File content copied to the RAM.\n");
        return address_on_ram;
    }
    //printf("ERROR in write_on_ram");
}

void print_disk() {
  puts("\n---------DISK STATUS-------\n");
  for (int i = 0; i < DISK_CAPACITY; i++)
    printf("[%c] ", secondary_mem[i]);
}

void print_ram() {
  puts("\n---------RAM STATUS-------\n");
  for (int i = 0; i < RAM_CAPACITY; i++)
    printf("[%c] ", primary_mem[i]);
}
