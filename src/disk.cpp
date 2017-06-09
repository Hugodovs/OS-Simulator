#include "disk.h"




void write_onDisk(int mem_address, char *file) {
	for (int i = 0; i < strlen(file); ++i) {
		secondary_mem[i+mem_address] = file[i];
	}
}