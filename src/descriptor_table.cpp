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
