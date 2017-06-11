#include "../headers/memory.h"
#include "../headers/directory_table.h"
#include "../headers/descriptor_table.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <unistd.h>

//120 col 30 row
#define SCREEN_SIZE 6120
#define ROW_NUMBER 51
#define COL_NUMBER 120

//Static Text on Screen:
const char text_computer_specs[27] 	= "COMPUTER SPECS";
const char text_file_table[11] 		= "FILE TABLE";
const char text_hard_drive[11]		= "HARD DRIVE";
const char text_id[3] 				= "ID";
const char text_adress[8] 			= "ADDRESS";
const char text_path[5] 			= "PATH";
const char text_ram[4] 				= "RAM MEMORY";
const char text_log[4] 				= "HARD DRIVE MEMORY";
const char text_input[6] 			= "LOG";
const char text_input[6] 			= "LAST ACTION: >>>"
const char text_input[6] 			= "INPUT: >>>"


char screen_buffer[SCREEN_SIZE];
char log_buffer[550];

void put_divisors_on_screen();
void update_screen();

void init_screen()
{
	#ifdef WINDOWS
	    std::system("MODE 51, 120");
	#else
	    std::system("resize -s 51 120 >/dev/null");
	#endif

    for(unsigned int i = 0; i < SCREEN_SIZE; i++){
		screen_buffer[i] = ' ';
	}

	for(unsigned int i = 0; i < 550; i++){
		log_buffer[i] = ' ';
	}
	/*for(unsigned int i = 0; i < 5; i++){
		log_buffer[i*110] = 'A';
	}*/

	put_divisors_on_screen();
	//FILL COMPUTER SPECS BOX:
	strncpy(screen_buffer+165, text_computer_specs, 26);

	//FILL FILE TABLE BOX:
	strncpy(screen_buffer+1335, text_file_table, 10);
	strncpy(screen_buffer+1443, text_id, 2);
	strncpy(screen_buffer+1456, text_adress, 7);
	strncpy(screen_buffer+1474, text_path, 4);

	//FILL RAM BOM:
	strncpy(screen_buffer+1372, text_ram, 3);

	//FILL HARD DRIVE BOX:
	strncpy(screen_buffer+1411, text_hard_drive, 10);

	//FILL LOG BOX:
	strncpy(screen_buffer+4922, text_log, 3);

	//FILL INPUT BOX:
	strncpy(screen_buffer+5882, text_input, 5);

}

void put_divisors_on_screen(){

	char text_divide_horizontal_screen[121];
	for (unsigned int i = 0; i < COL_NUMBER; i++){
		text_divide_horizontal_screen[i] = '-';
	}
	strncpy(screen_buffer+1080, text_divide_horizontal_screen, 120);
	strncpy(screen_buffer+4680, text_divide_horizontal_screen, 120);
	strncpy(screen_buffer+5042, text_divide_horizontal_screen, 112);
	//strncpy(screen_buffer+5642, text_divide_horizontal_screen, 118);

	for (int i = 1243; i < 40*120; i+=120) {
		screen_buffer[i] = '|';
	}

	for (int i = 1285; i < 40*120; i+=120) {
		screen_buffer[i] = '|';
	}

	for (int i = 5162; i < 5762-600 + 5*120; i+=120) {
		screen_buffer[i] = '|';
	}

	for (int i = 5162+111; i < 5762-600+111 + 5*120; i+=120) {
		screen_buffer[i] = '|';
	}

}

void set_DiskStatus_on_buffer() {
	for (int i = 1411+240; i < 1411+240 + DISK_CAPACITY*120; i+=120) {
		screen_buffer[i] = '[';
		screen_buffer[i+2] = ']';
	}

	int j = 0;
	for (int i = 1411+240+1; i < 1411+240 + DISK_CAPACITY*120; i+=120) {
		screen_buffer[i] = *(secondary_mem+j);
		j++;
	}
}

void update_log_buffer(char* log_line){
	
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

void set_log_buffer(){
	int j = 0;
	for (int i = 5042+121; i < 5042+121 + 5*120; i+=120) {
		strncpy(screen_buffer+i, log_buffer+j, 110);
		j += 110;
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
	set_log_buffer();
	printf("%s", screen_buffer);
	sleep(1);
}