#include <bits/stdc++.h>
#include "headers/disk.h"

//Directory:
//Convert file_name into directory_entries





// File 
char file1[] = "abaa";

// RAM
#define RAM_CAPACITY 5
char primary_mem[RAM_CAPACITY];
void write_onRAM(int mem_address , int idFile);
void read_fromRAM(int mem_address);
void print_RAMStatus();

// Computer
void print_ComputerStatus();

// Directory
#define MaxFileNUMBER
typedef struct _DirectoryTable {
	int idFiles[MaxFileNUMBER];
	char pathFiles[MaxFileNUMBER][50];
} DirectoryTable;

typedef struct _FileDescriptorTable {
	int idFiles[MaxFileNUMBER];
	int addressFiles[MaxFileNUMBER];

} FileDescriptorTable;


int main (void){
	// Init Enviroment
    FileDescriptorTable fileDescriptorTable;

    fileDescriptorTable.idFiles[0] = 0;
    fileDescriptorTable.addressFiles[0] = 4;


    //Print file
   	printf("%s\n", file1);
   	// Print Disk
   	print_ComputerStatus();
    // Write on Disk
    write_onDisk(fileDescriptorTable.addressFiles[0], file1);
    //write_onRAM(1,file1);
    // Print (after Copy)
    print_ComputerStatus();

    return 0;
}


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




void write_onRAM(int mem_address , int idFile) {
	for (int i = 0; i < strlen(file1); ++i) {
		primary_mem[i+mem_address] = file1[i];
	}
}

void read_fromRAM(int mem_address) {

}
