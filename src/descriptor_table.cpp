#include "../headers/descriptor_table.h"
#include <stdio.h>

int last_fd = 0;
InodeTuple inode_table[MAX_FILE_NUMBER];

int generate_fd() {
    return last_fd++;
}


void insert_tuple_inode_table(int fd, int index, int size) {
    InodeTuple tuple;
    tuple.id_file = fd;
    tuple.size = size;
    tuple.address_file = index;
    inode_table[fd] = tuple;
}


void get_address_size_from_id(int id_file, int address_and_size[2]) {


	for (int i = 0; i < MAX_FILE_NUMBER; i++) {
		if(inode_table[i].id_file==id_file) {
			address_and_size[0] = inode_table[i].address_file;
			address_and_size[1] = inode_table[i].size;
			break;
		}
	}
}

void print_inode_table() {
  for (int i = 0; i < MAX_FILE_NUMBER; i++) {
      if (inode_table[i].size > 0)
        printf("Id: %d Address: %d  Size: %d\n", inode_table[i].id_file, inode_table[i].address_file, inode_table[i].size);
  }
}
