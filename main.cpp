
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/disk.h"
#include "headers/ram.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"


//Directory:
//Convert file_name into directory_entries


// File
char file1[] = "hugo";
char file2[] = "joao_burro";
// Directory Table


int main (void){
	// Init Enviroment

    //open file
    //OPEN("test.txt")



    //Write File On Disk:
    //checkDisk se file cabe
	

    //Pega o path(string) e o id do file descriptor table(adiciona no directory table)

    //Printa o Disk

    //Print file
   	printf("%s\n", file1);
   	// Print Disk
   	print_ComputerStatus();
    write_onDisk(file1, "file1.txt");  // precisa de if aqui... com o int retornado
   	write_onDisk(file2, "file2.txt");

    char fileOut[100]; 
    read_fromDisk("file1.txt", fileOut);
    printf("\nFileOut: %s\n", fileOut);
    read_fromDisk("file2.txt", fileOut);
	printf("\nFileOut: %s\n", fileOut);

    // Print (after Copy)
    print_ComputerStatus();

    return 0;
}
