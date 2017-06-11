#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/memory.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"
#include "headers/workflow.h"


// Files
char file1[] = "hugo";
//char file2[] = "joao_burro";


int main (void){
	// Init Enviroment
	
    init_screen();
    init_disk();
    init_ram();
    update_screen(); 
    write_onDisk(file1, "file1.txt");

    //update_file_table_id_buffer();
    update_screen(); 
    /*update_log_buffer("Schulz eh um viadinho");
    update_screen();

    update_log_buffer("Joao tambem eh");
    update_screen();

    update_log_buffer("Eles foram dormir");
    update_screen();

    update_log_buffer("E me deixaram aqui");
    update_screen();

    update_log_buffer("Fazendo essa merda");
    update_screen();

    update_log_buffer("DE TRABALHO DE MERDA iuaheuiahea");
    update_screen();*/
    //update_log_buffer("asdasd");
    //update_screen();
    //write_onDisk(file1, "file1.txt");
	//open_file("file1.txt");    
    //print_ComputerStatus();

    //Print file
   	//printf("%s\n", file1);
   	//write_onDisk(file1, "file1.txt");  // precisa de if aqui... com o int retornado
   	//read_fromDisk("file1.txt", fileOut);
    //delete_fromDisk("file1.txt");
    //write_onDisk(file2, "file2.txt");
    //print_ComputerStatus();
    //print_ComputerStatus();
    //open_file("file1.txt");
    //print_ComputerStatus();
    //clearScreen();
    //print_ComputerStatus();
    //char fileOut[100]; 
    //printf("\nFileOut: %s\n", fileOut);
    //read_fromDisk("file2.txt", fileOut);
	//printf("\nFileOut: %s\n", fileOut);
    
    while(1);
    // Print (after Copy)
    //print_ComputerStatus();
    return 0;
}
