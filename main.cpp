#include <bits/stdc++.h>
#include "headers/disk.h"
#include "headers/ram.h"
#include "headers/screen.h"

//Directory:
//Convert file_name into directory_entries





// File 
char file1[] = "abaa";




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









