#include "../headers/disk.h"
#include <string.h>
#include <stdio.h>


char secondary_mem[DISK_CAPACITY];



void write_onDisk(int mem_address, char *file) {
	for (int i = 0; i < strlen(file); ++i) {
		secondary_mem[i+mem_address] = file[i];
	}
}


int check_free_disk(int size) {
    
    int index = -1;
    int empty_spaces;
    for (int i = 0; i <= DISK_CAPACITY - size; i++) {
        if (secondary_mem[i] == '\0') {
            empty_spaces = 0;
            for (int j = i; j < i + size; j++) {
                if (secondary_mem[j] != '\0') break; //se encontrou algum espaço não vazio
                else if (++empty_spaces == size) return i;
            }
        }
            
    }
    return index;
}
