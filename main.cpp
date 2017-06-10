#include <bits/stdc++.h>
#include "headers/disk.h"
#include "headers/ram.h"
#include "headers/screen.h"
#include "headers/directorytuple.h"
#include "headers/filedescriptortuple.h"


//Directory:
//Convert file_name into directory_entries




// File 
char file1[] = "abaa";







int main (void){
	// Init Enviroment
    DirectoryTuple directory_table[MAX_FILE_NUMBER];
    FileDescriptorTuple file_descriptor_table[MAX_FILE_NUMBER];
    // File
    
    //Write File On Disk:
    //checkDisk se file cabe
    secondary_mem[1] = 'A';
    secondary_mem[5] = 'B';
    int y = check_free_disk(3);
    //Coloca o arquivo no endereço físico do Disco
    //Pega o endereço e cria um id (adiciona no file descriptor table)
    //Pega o path(string) e o id do file descriptor table(adiciona no directory table)

       

    //Read File On Disk
    //Usuário passa o path
    //DirectoryTable transforma o path em um id
    //FileDescriptorTable transforma esse id em um adress
    //Pega esse adress e lê o arquivo no disco





    //Print file
   	//printf("%s\n", file1);
   	// Print Disk
   	//print_ComputerStatus();
    // Write on Disk
    //write_onDisk(0, file1);
    //write_onRAM(1,file1);
    // Print (after Copy)
    print_ComputerStatus();

    printf("check free disk returns %d\n", y);
    return 0;
}









