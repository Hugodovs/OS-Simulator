#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/memory.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"

// Files
char file1[] = "hugo";
//char file2[] = "joao_burro";



int main (void){
	// Init Enviroment
    //OPEN("test.txt")

    print_ComputerStatus();
    
    switch:

        - open file.txt

        - write aiueahiueahea in int(adress)

        - read int(adress) int(size)

        - close int(andress_init) 

    //Print file
   	//printf("%s\n", file1);
   	write_onDisk(file1, "file1.txt");  // precisa de if aqui... com o int retornado
   	//read_fromDisk("file1.txt", fileOut);
    //delete_fromDisk("file1.txt");
    //write_onDisk(file2, "file2.txt");
    print_ComputerStatus();

    open_file("file1.txt");
    print_ComputerStatus();
    //char fileOut[100]; 
    
    //printf("\nFileOut: %s\n", fileOut);
    //read_fromDisk("file2.txt", fileOut);
	//printf("\nFileOut: %s\n", fileOut);

    

    // Print (after Copy)
    //print_ComputerStatus();
    return 0;
}
