#include "../headers/ram.h"
#include "../headers/disk.h"
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