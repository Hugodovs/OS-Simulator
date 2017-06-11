#include "../headers/memory.h"
#include "../headers/directory_table.h"
#include "../headers/descriptor_table.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

//120 col 30 row
#define SCREEN_SIZE 3600
//#define DISK_CAPACITY 20

char screen_buffer[SCREEN_SIZE];

void set_DiskStatus_on_buffer() {
	int j = 0;
	for (int i = 20; i < DISK_CAPACITY*120; i+=120) {
		//printf("%d ", i);
		screen_buffer[i] = *(secondary_mem+j);
		j++;
	}
	for (int i = 19; i < DISK_CAPACITY*120; i+=120) {
		screen_buffer[i] = '[';
		screen_buffer[i+2] = ']';
	}
}

void update_screen(){
	#ifdef WINDOWS
	    std::system("cls");
	#else
		std::system ("clear");
	#endif
	setbuf(stdout, NULL);

	//Put Disk:
	set_DiskStatus_on_buffer();

	printf("%s", screen_buffer);
}

void init_screen()
{
	#ifdef WINDOWS
	    std::system("MODE 2, 120");
	#else
	    std::system("resize -s 30 120 >/dev/null");
	#endif

    for(unsigned int i = 0; i < SCREEN_SIZE; i++){
		screen_buffer[i] = ' ';
	}
}



void set_RAMStatus_on_buffer() {
	for (int i = 0; i < RAM_CAPACITY; ++i) {
		//printf("[%c]", *(primary_mem+i));
	}
	//printf("\n");
}

void print_ComputerStatus(){
	//set_DiskStatus_on_buffer();
	printf("%s", screen_buffer);
	
	sleep(1);
}

void print_directory_table() {
    for(int i = 0; i < MAX_FILE_NUMBER; i++) {
        //printf("(Filename: %s, ID: %d)\n", directory_table[i].filename, directory_table[i].id_file);
    }
}

void print_descriptor_table() {
    for (int i = 0; i < MAX_FILE_NUMBER; i++){}
        /*printf("(ID:%d, size:%d, address:%d)\n", file_descriptor_table[i].id_file, file_descriptor_table[i].size,
    }
    file_descriptor_table[i].address_file);*/
}
