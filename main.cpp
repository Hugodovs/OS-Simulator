
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/disk.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"


//Directory:
//Convert file_name into directory_entries


// File
char file1[] = "hugo";
//char file2[] = "joao_burro";



int main (void){
	// Init Enviroment
    //OPEN("test.txt")

    print_ComputerStatus();
    

    //Print file
   	//printf("%s\n", file1);
   	write_onDisk(file1, "file1.txt");  // precisa de if aqui... com o int retornado
   	
    //write_onDisk(file2, "file2.txt");
    print_ComputerStatus();

    //open_fromDisk("file.txt");

    //char fileOut[100]; 
    //read_fromDisk("file1.txt", fileOut);
    //printf("\nFileOut: %s\n", fileOut);
    //read_fromDisk("file2.txt", fileOut);
	//printf("\nFileOut: %s\n", fileOut);

    //delete_fromDisk("file1.txt");

    // Print (after Copy)
    //print_ComputerStatus();
    return 0;
}
