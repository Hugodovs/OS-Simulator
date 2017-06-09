#include <bits/stdc++.h>
#include "headers/disk.h"
#include "headers/ram.h"
#include "headers/screen.h"

//Directory:
//Convert file_name into directory_entries




// File 
char file1[] = "abaa";





// Directory Table
#define MAX_FILE_NUMBER 5
typedef struct _DirectoryTuple {
    char path_file[50];
    int id_file;
} DirectoryTuple



//File Descriptor Table
typedef struct _FileDescriptorTuple {
    int id_file;
    int address_file;
} FileDescriptorTable;


int main (void){
	// Init Enviroment
    DirectoryTuple directory_table[MAX_FILE_NUMBER];
    FileDescriptorTuple file_descriptor_table[MAX_FILE_NUMBER];
    // File
    
    //Write File On Disk:
    //checkDisk se file cabe
    //Coloca o arquivo no endereço físico do Disco
    //Pega o endereço e cria um id (adiciona no file descriptor table)
    //Pega o path(string) e o id do file descriptor table(adiciona no directory table)

    //Printa o Disk

        


    
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









