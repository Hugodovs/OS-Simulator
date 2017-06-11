#include "../headers/ram_file_table.h"
#include "../headers/directory_table.h"
#include "../headers/memory.h"
#include <string.h>
#include <stdio.h>

FILE_RAM_TUPLE files_ram_table[MAX_FILE_NUMBER];

int NUM_FILES_OP = 0;

void insert_tuple_file_ram_table(char* file_name, char* mode, int ram_file_address) {
  int file_id = find_file_id(file_name);
  strcpy(files_ram_table[file_id].mode, mode);
  files_ram_table[file_id].file_id = file_id;
  files_ram_table[file_id].ram_file_address = ram_file_address;
  files_ram_table[file_id].file_ptr = ram_file_address;
  NUM_FILES_OP++;
}


void print_ram_table() {
  FILE_RAM_TUPLE tuple;
  for (int i = 0; i < NUM_FILES_OP; i++) {
    tuple = files_ram_table[i];
    printf("File id: %d, FIle adress on ram:%d, File ptr: %d\n", tuple.file_id, tuple.ram_file_address, tuple.file_ptr);
    print_disk();
  }
  return;
}
