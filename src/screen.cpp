#include "../headers/disk.h"
#include "../headers/directory_table.h"
#include "../headers/descriptor_table.h"
#include <string.h>
#include <stdio.h>


// Screen


void print_DiskStatus() {
	for (int i = 0; i < DISK_CAPACITY; ++i) {
		printf("[%c]", *(secondary_mem+i));
	}
	printf("\n");
}

void print_RAMStatus() {
	for (int i = 0; i < RAM_CAPACITY; ++i) {
		printf("[%c]", *(primary_mem+i));
	}
	printf("\n");
}

void print_ComputerStatus(){
	printf("---------------------------------------------------\n");
	printf("Disk status:\n");
	print_DiskStatus();
	printf("---------------------------------------------------\n");
	printf("RAM status:\n");
	print_RAMStatus();
	printf("---------------------------------------------------\n\n");
}

void print_directory_table() {
    for(int i = 0; i < MAX_FILE_NUMBER; i++) {
        printf("(Filename: %s, ID: %d)\n", directory_table[i].filename, directory_table[i].id_file);
    }
}

void print_descriptor_table() {
    for (int i = 0; i < MAX_FILE_NUMBER; i++)
        printf("(ID:%d, size:%d, address:%d)\n", file_descriptor_table[i].id_file, file_descriptor_table[i].size,
    file_descriptor_table[i].address_file);
}
