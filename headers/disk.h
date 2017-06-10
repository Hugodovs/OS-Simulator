


// Disk Info
#define DISK_CAPACITY 20
#define RAM_CAPACITY 5

extern char secondary_mem[DISK_CAPACITY];
extern char primary_mem[RAM_CAPACITY];


int write_onDisk(char *file, char *fileName);
void read_fromDisk(char *requestedfile, char requestedfile_content[100]);
int check_free_disk(int tam);
void delete_fromDisk(char *file);