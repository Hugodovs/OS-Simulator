#include "../headers/memory.h"
#include "../headers/directory_table.h"
#include "../headers/descriptor_table.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <unistd.h>

//120 col 30 row
#define SCREEN_SIZE 4800
#define ROW_NUMBER 40
#define COL_NUMBER 120

char screen_buffer[4801] =  "+======================================================================================================================+"
							"|                                                                                                                      |"
							"|                                                                                                                      |"
							"|                                                                                                                      |"
							"|                                                                                                                      |"
							"|                                                                                                                      |"
							"|                                                                                                                      |"
							"+=========================================+=========================+==================================================+"
							"|                                         |                         |                                                  |"
							"|           FILE RAM TABLE                |       RAM MEMORY        |            HARD DRIVE MEMORY                     |"
							"|                                         |                         |                                                  |"
							"|  SIZE        ADDRESS         PATH       | 0: > [   ]  10: > [   ] |   0: [   ]  10: [   ]  20: [   ]  30 [   ]       |"
							"| +===+        +====+      +============+ | 1:   [   ]  11:   [   ] |   1: [   ]  11: [   ]  21: [   ]  31 [   ]       |"
							"| |   |        |    |      |            | | 2:   [   ]  12:   [   ] |   2: [   ]  12: [   ]  22: [   ]  32 [   ]       |"
							"| +===+        +====+      +============+ | 3:   [   ]  13:   [   ] |   3: [   ]  13: [   ]  23: [   ]  33 [   ]       |"
							"| |   |        |    |      |            | | 4:   [   ]  14: > [   ] |   4: [   ]  14: [   ]  24: [   ]  34 [   ]       |"
							"| +===+        +====+      +============+ | 5:   [   ]  15:   [   ] |   5: [   ]  15: [   ]  25: [   ]  35 [   ]       |"
							"| |   |        |    |      |            | | 6:   [   ]  16:   [   ] |   6: [   ]  16: [   ]  26: [   ]  36 [   ]       |"
							"| +===+        +====+      +============+ | 7:   [   ]  17:   [   ] |   7: [   ]  17: [   ]  27: [   ]  37 [   ]       |"
							"| |   |        |    |      |            | | 8:   [   ]  18:   [   ] |   8: [   ]  18: [   ]  28: [   ]  38 [   ]       |"
							"| +===+        +====+      +============+ | 9:   [   ]  19: > [   ] |   9: [   ]  19: [   ]  29: [   ]  39 [   ]       |"
							"| |   |        |    |      |            | |                         |                                                  |"
							"| +===+        +====+      +============+ +=========================+==================================================+"
							"| |   |        |    |      |            | |                                                                            |"
							"| +===+        +====+      +============+ |                                   LOG                                      |"
							"| |   |        |    |      |            | | +========================================================================+ |"
							"| +===+        +====+      +============+ | | >>>                                                                    | |"
							"| |   |        |    |      |            | | | >>>                                                                    | |"
							"| +===+        +====+      +============+ | | >>>                                                                    | |"
							"| |   |        |    |      |            | | | >>>                                                                    | |"
							"| +===+        +====+      +============+ | | >>>                                                                    | |"
							"| |   |        |    |      |            | | | >>>                                                                    | |"
							"| +===+        +====+      +============+ | | >>>                                                                    | |"
							"|                                         | +========================================================================+ |"
							"|                                         | | >>>                                                                    | |"
							"|                                         | +========================================================================+ |"
							"|                                         |                                                                            |"
							"+======================================================================================================================+"
							"|  INPUT: >>>                                                                                                          |"
							"+======================================================================================================================+";

//Buffers:
char file_table_size_buffer[10];
char file_table_address_buffer[20];
char file_table_path_buffer[100];
char ram_memory_buffer[20];
char hard_drive_buffer[40];
char log_buffer[520]; //65 per line

void restart_file_table_size_buffer(){
	for(int i = 0; i < 10; i++){
		file_table_size_buffer[i] = ' ';
	}
}

void restart_file_table_address_buffer(){
	for(int i = 0; i < 20; i++){
		file_table_address_buffer[i] = ' ';
	}
}

void restart_file_table_path_buffer(){
	for(int i = 0; i < 100; i++){
		file_table_path_buffer[i] = ' ';
	}
}

void restart_ram_memory_buffer(){
	for(int i = 0; i < 20; i++){
		ram_memory_buffer[i] = ' ';
	}
}

void restart_hard_drive_buffer(){
	for(int i = 0; i < 40; i++){
		hard_drive_buffer[i] = ' ';
	}
}

void restart_log_buffer(){
	for(int i = 0; i < 520; i++){
		log_buffer[i] = ' ';
	}
}

void init_screen()
{
	#ifdef WINDOWS
	    std::system("MODE 40, 120");
	#else
	    std::system("resize -s 40 120 >/dev/null");
	#endif

	restart_file_table_size_buffer();
	restart_file_table_address_buffer();
	restart_file_table_path_buffer();
	restart_ram_memory_buffer();
	restart_hard_drive_buffer();
	restart_log_buffer();
}


void update_screen(){
	#ifdef WINDOWS
	    std::system("cls");
	#else
		std::system ("clear");
	#endif
	setbuf(stdout, NULL);

	printf("%s", screen_buffer);
	//sleep(1);
}

void update_file_table_size_buffer(){
	for(int i = 0; i < 10; i++){
		file_table_size_buffer[i] = 's';//files_ram_table[i].file_size;
	}

	//Atualiza screen buffer
	int j = 0;
	for(int i = 1685-120; i < 1685 + 120*1; i+=120){
		screen_buffer[i] = file_table_size_buffer[j];
		j++;
	}
}

void update_file_table_address_buffer(){
	for(int i = 0; i < MAX_FILE_NUMBER; i++){
		file_table_size_buffer[i] = inode_table[i].address_file;
	}

	//Atualiza screen buffer
}

void update_file_table_path_buffer(){
	for(int i = 0; i < MAX_FILE_NUMBER; i++){
		for(int j = 0; j < 10; j++){
			file_table_size_buffer[i] = *(directory_table[i].filename)+j;
		}
	}

	//Atualiza screen buffer	
}

void update_ram_memory_buffer(){
	for (int i = 0; i <  RAM_CAPACITY; i++) {
		ram_memory_buffer[i] = primary_mem[i];
	}

	//Atualiza screen buffer
}

void update_hard_drive_buffer(){
	for (int i = 0; i <  DISK_CAPACITY; i++) {
		hard_drive_buffer[i] = secondary_mem[i];
	}
	
	//Atualiza screen buffer
}
















void update_log_buffer(char* new_line){
	sleep(1);
	for(int i = 0; i < 65; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65; i < 65*2; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65*2; i < 65*3; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65*3; i < 65*4; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65*4; i < 65*5; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65*5; i < 65*6; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	for(int i = 65*6; i < 65*7; i++){
		log_buffer[i] = log_buffer[i+65];
	}

	//New string:
	//Reset:
	for(int i = 65*7; i < 65*8; i++){
		log_buffer[i] = ' ';
	}

	int j = 0;
	for(unsigned int i = 65*7; i < 65*7 + strlen(new_line); i++){
		log_buffer[i] = *(new_line + j);
		j++;
	}

	//Atualiza screen buffer
	int k = 3171;
	for (int j = 0; j < 7; j++){
		for(int i = 0; i < 65; i++){
			screen_buffer[k + i] = log_buffer[i + 65*j];
		}
		k += 120;
	}

	k+=120;
	for(int i = 0; i < 65; i++){
		screen_buffer[k + i] = log_buffer[i + 65*7];
	}

	
}




























/*void update_log_buffer(char* log_line){

	//Fourth Line:
	for (int i = 110; i < 220; i++) {
		log_buffer[i-110] = log_buffer[i];
	}
	//Third Line:
	for (int i = 220; i < 330; i++) {
		log_buffer[i-110] = log_buffer[i];
	}
	//Second Line:
	for (int i = 330; i < 440; i++) {
		log_buffer[i-110] = log_buffer[i];
	}

	for (int i = 440; i < 550; i++) {
		log_buffer[i-110] = log_buffer[i];
	}
	//First Line:
	strcpy(log_buffer+440, log_line);

	for (int i = 440+strlen(log_line); i < 550; i++) {
		log_buffer[i] = ' ';
	}

}*/



/*

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
        printf("(ID:%d, size:%d, address:%d)\n", file_descriptor_table[i].id_file, file_descriptor_table[i].size,
    }
    ;
}

void set_log_buffer(){
	int j = 0;
	for (int i = 5042+121; i < 5042+121 + 5*120; i+=120) {
		strncpy(screen_buffer+i, log_buffer+j, 110);
		j += 110;
	}
}*/
