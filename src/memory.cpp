#include "../headers/screen.h"
#include "../headers/memory.h"
#include "../headers/descriptor_table.h"
#include "../headers/directory_table.h"
#include "../headers/ram_file_table.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DISK_CAPACITY 40
#define RAM_CAPACITY 20

char secondary_mem[DISK_CAPACITY];
char primary_mem[RAM_CAPACITY];

char str[100];


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
        insert_tuple_inode_table(fd, disk_address, strlen(file));
        insert_tuple_direct_table(fd, fileName);

        /*update_log_buffer("Disk Controller: logic address -> inode number.");
        update_screen();
        update_log_buffer("Inode Table inserted Inode number by Controladora.");
        update_screen();*/
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

    update_log_buffer("Attempting to locate file...");
    update_screen();

    int id_reqfile = find_file_id(requestedfile);
    if(id_reqfile==-1) {
<<<<<<< HEAD
        
        update_log_buffer("Failed to located file in the Directory_Table");
=======

        update_log_buffer("Failed to located requestedfile id on the directory_table");
>>>>>>> b24706e0519976c1e1af07ceff0ab7fffbf5584c
        update_screen();
        update_log_buffer("File not found in HD.");
        update_screen();
        update_log_buffer("Let's create it!");
        update_screen();
        update_log_buffer("Creating...");
        update_screen();

        write_onDisk("-", requestedfile);
        requestedfile_content[0] = '-';
        requestedfile_content[1] = '\0';
     } else{

        sprintf(str, "File (%d) exists!", id_reqfile);
        update_log_buffer(str);
        update_screen();

     }

    int file_address_and_size[2];

    sprintf(str, "Now the file exists!", id_reqfile);
    update_log_buffer(str);
    update_screen();

    sprintf(str, "Disk Controller receives inode");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "Disk Controller checks Directory_Table");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "Disk Controller checks Inode_Table");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "- setting file.txt size and physical address");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "Disk Controller requests DMA Controller");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "DMA controller accesses RAM memory");
    update_log_buffer(str);
    update_screen();

    sprintf(str, "file.txt in RAM");
    update_log_buffer(str);
    update_screen();

    get_address_size_from_id(id_reqfile, file_address_and_size);

    for (int i = 0; i < file_address_and_size[1]; i++) {
        requestedfile_content[i] = secondary_mem[file_address_and_size[0]+i];
    }

    requestedfile_content[file_address_and_size[1]] = '\0';

    return file_address_and_size[1];

}

/*void delete_fromDisk(char *file) {
    int id_reqfile = find_file_id(file);
    int file_address_and_size[2];
    get_address_size_from_id(id_reqfile, file_address_and_size);

    for (int i = file_address_and_size[0]; i < file_address_and_size[0] + file_address_and_size[1]; i++) {
        secondary_mem[i] = ' ';
    }

}*/



void open_file(char* file_name, char* mode){
    //DMA:
    //Vai no HD e pega o conteúdo desse arquivo:

    sprintf(str, "Kernel parses \"%s\" to find the corresponding inode", file_name);
    update_log_buffer(str);
    update_screen();

    char file_content[50];
    int file_size = read_fromDisk(file_name, file_content);

    //sprintf(str, "file content: %s, tam: %d", file_content, strlen(file_content));
    //update_log_buffer(str);
    //update_screen();

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

  update_log_buffer("Escreve um conjunto de caracteres no endereço do arquivo na RAM.");
  update_screen();
  update_log_buffer("O processador vai na File_RAM_Table e pega o endereço do arquivo.");
  update_screen();
  update_log_buffer("Tendo o endereço, ele escreve a string a partir do file_pointer.");
  update_screen();
  //printf("File ptr: %d", files_ram_table[file_id].file_ptr);
  for (unsigned int i = 0; i < strlen(input); i++) {
    primary_mem[files_ram_table[file_id].file_ptr] = input[i];
    files_ram_table[file_id].file_ptr++;
    files_ram_table[file_id].file_size++;
//    print_ram_table();
  }


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
  for (int i = 0; i < file_ram_size+1; i++) {
    aux = primary_mem[b];
    primary_mem[b++] = ' ';
    secondary_mem[a++] = aux;
  }
  delete_tuple_ram_table(file_id);

}

int write_on_ram(char* file_content) {
    //printf("Tentando escrever um arquivo na RAM!");

    /*update_log_buffer("Locating free space at the RAM.");
    update_screen();*/

    int address_on_ram = check_free_ram(strlen(file_content));
    if (address_on_ram == -1) {

        /*update_log_buffer("There isn't enough space at the RAM.");
        update_screen();*/

        return address_on_ram;
    }
    else {
        for (unsigned int i = 0; i < strlen(file_content); ++i) {
            primary_mem[i+address_on_ram] = file_content[i];
        }
        /*update_log_buffer("Controladora do disco inseriu o conteúdo do arquivo na RAM diretamente(DMA).");
        update_screen();
        update_log_buffer("File content copied to the RAM.");
        update_screen();*/

        return address_on_ram;
    }
    //printf("ERROR in write_on_ram");
}

void read_from_file(char* requestedfile, int num_bytes) {
  int file_id = find_file_id(requestedfile);
  int ram_file_address = files_ram_table[file_id].ram_file_address;
  for (int i = ram_file_address; i < ram_file_address + num_bytes; i++) {
    printf("Lendo byte no endereço: %d...", i);
  }
}

void delete_file(char* file_name) {
  int file_id = find_file_id(file_name);
  if (file_id == -1) {
    printf("Não foi possível deletar o arquivo %s. Arquivo não encontrado.", file_name);
    return;
  }
  int file_size = files_ram_table[file_id].file_size;
  if (file_size > 0) {//arquivo ta aberto!
    printf("Não foi possível deletar o arquivo %s. Tente fechar o arquivo primeiro.", file_name);
    return;
  } else {
    int hd_file_address = inode_table[file_id].address_file;
    int file_size = inode_table[file_id].size;
    for (int i = hd_file_address; i < hd_file_address + file_size; i++) {
      secondary_mem[i] = ' ';
    }
  }


}

void print_disk() {
  puts("---------DISK STATUS-------");
  for (int i = 0; i < DISK_CAPACITY; i++)
    printf("[%c] ", secondary_mem[i]);
}

void print_ram() {
  puts("---------RAM STATUS-------");
  for (int i = 0; i < RAM_CAPACITY; i++)
    printf("[%c] ", primary_mem[i]);
}
