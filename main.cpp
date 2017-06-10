
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
//char file2[] = "joao_burro";



int main (void){
	// Init Enviroment
    //OPEN("test.txt")

    print_ComputerStatus();
    

    while(1){
        espera o comando do usuário:

        switch:
            - open file1.txt:
                print("Vai do HD para a ram")
            - write in file1.txt
                print("Escreve no endereço do arquivo na RAM e tem que atualizar...")
            - read file1.txt:
                print("Salvo o conteúdo do file em uma variável")

    }
    

   /* //Print file
   	printf("%s\n", file1);
   	// Print Disk
   	print_ComputerStatus();
    write_onDisk(file1, "file1.txt");  // precisa de if aqui... com o int retornado
   	//write_onDisk(file2, "file2.txt");
    print_ComputerStatus();
    char fileOut[100]; 
    read_fromDisk("file1.txt", fileOut);
    printf("\nFileOut: %s\n", fileOut);
    //read_fromDisk("file2.txt", fileOut);
	//printf("\nFileOut: %s\n", fileOut);

    delete_fromDisk("file1.txt");

    // Print (after Copy)
    print_ComputerStatus();
*/
    return 0;
}
