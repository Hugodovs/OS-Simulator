#include <bits/stdc++.h>
#include "headers/disk.h"
#include "headers/ram.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"


//Directory:
//Convert file_name into directory_entries


// File
char file1[] = "abaa";

// Directory Table


int main (void){
	// Init Enviroment

    //open file
    //OPEN("test.txt")



    //Write File On Disk:
    //checkDisk se file cabe
    int initial_pos_free_space = check_free_disk(3);
    if (initial_pos_free_space == -1)
        printf("Sem espaco suficiente no disco. Chola\n");
    else {
        write_onDisk(initial_pos_free_space, file1); //Coloca o arquivo no endereço físico do Disco
        int fd = generate_fd(); //cria um filedescriptor para o file
        insert_tuple_descrip_table(fd, initial_pos_free_space, strlen(file1));
        //print_descriptor_table(); se quiser ver a descriptor table... só descomentar...
        insert_tuple_direct_table(fd, "file1.txt");
        print_directory_table(); //se quiser ver a directory table... só descomentar...
    }

    //Pega o path(string) e o id do file descriptor table(adiciona no directory table)

    //Printa o Disk

    //Print file
   	printf("%s\n", file1);
   	// Print Disk
   	print_ComputerStatus();
    // Write on Disk
   // write_onDisk(fileDescriptorTable.addressFiles[0], file1);
    //write_onRAM(1,file1);
    // Print (after Copy)
    print_ComputerStatus();

    return 0;
}
