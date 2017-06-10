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


void get_address_size_from_id(int id_file, int address_and_size[2]) {
	

	for (int i = 0; i < MAX_FILE_NUMBER; i++) {
		if(file_descriptor_table[i].id_file==id_file) {
			address_and_size[0] = file_descriptor_table[i].address_file;
			address_and_size[1] = file_descriptor_table[i].size;
			break;	
		}
	}
}
