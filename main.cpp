#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/memory.h"
#include "headers/screen.h"
#include "headers/directory_table.h"
#include "headers/descriptor_table.h"
#include "headers/ram_file_table.h"
#include "headers/workflow.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

int main (void){
	
	// Init Enviroment
    init_screen();
    init_disk();
    init_ram();

    //Main loop:
    while(1) {

        update_screen();
        gotoxy(39, 15);
        get_next_Instruction();
        update_screen();
      
    }

    return 0;
}
