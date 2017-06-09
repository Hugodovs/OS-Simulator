


// Disk Info
#define DISK_CAPACITY 20

extern char secondary_mem[DISK_CAPACITY];

void write_onDisk(int mem_address , char *file);
void read_fromDisk(int mem_address);
