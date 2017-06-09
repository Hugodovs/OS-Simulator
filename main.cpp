#include <bits/stdc++.h>


//Directory:
//Convert file_name into directory_entries


// Disk Info
#define DISK_CAPACITY 20
char secondary_mem[DISK_CAPACITY];
void write_onDisk(int mem_address , char *file);
void read_fromDisk(int mem_address);
void print_DiskStatus();


// File 
char file_1[] = "abaa";

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
typedef _DirectoryTable {
	int idFiles[MaxFileNUMBER];
	char pathFiles[MaxFileNUMBER][50];


} DirectoryTable;

typedef _FileDescriptorTable {
	int idFiles[MaxFileNUMBER];
	int addressFiles[MaxFileNUMBER];


} FileDescriptorTable;


int main (void){
	// Init Enviroment
    FileDescriptorTable fileDescriptorTable;

    fileDescriptorTable.idFiles[0] = 0;
    fileDescriptorTable.addressFiles[0] = 4;


    //Print file
   	printf("%s\n", file_1);
   	// Print Disk
   	print_ComputerStatus();
    // Write on Disk
    write_onDisk(fileDescriptorTable.addressFiles[0], file_1);
    write_onRAM(1,file_1);
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


void write_onDisk(int mem_address, char *file) {
	for (int i = 0; i < strlen(file); ++i) {
		secondary_mem[i+mem_address] = file[i];
	}
}

void write_onRAM(int mem_address , int idFile) {
	for (int i = 0; i < strlen(file); ++i) {
		primary_mem[i+mem_address] = file[i];
	}
}

void read_fromRAM(int mem_address) {

}
