#include "../headers/descriptor_table.h"
#include <stdio.h>

int last_fd = 0;
FileDescriptorTuple file_descriptor_table[MAX_FILE_NUMBER];

int generate_fd() {
    return last_fd++;
}


void insert_tuple_descrip_table(int fd, int index, int size) {
    FileDescriptorTuple tuple;
    tuple.id_file = fd;
    tuple.size = size;
    tuple.address_file = index;
    file_descriptor_table[fd] = tuple;
}

void print_descriptor_table() {
    for (int i = 0; i < MAX_FILE_NUMBER; i++)
        printf("(ID:%d, size:%d, address:%d)\n", file_descriptor_table[i].id_file, file_descriptor_table[i].size,
    file_descriptor_table[i].address_file);
}
