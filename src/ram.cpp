#include "../headers/ram.h"
#include <string.h>
#include <stdio.h>



char primary_mem[RAM_CAPACITY];


void write_onRAM(int mem_address , int idFile) {
	for (int i = 0; i < strlen(file1); ++i) {
		primary_mem[i+mem_address] = file1[i];
	}
}

void read_fromRAM(int mem_address) {

}

