#define DISK_CAPACITY 40
#define RAM_CAPACITY 20

extern char secondary_mem[DISK_CAPACITY];
extern char primary_mem[RAM_CAPACITY];

//Disk:
void init_disk();
int write_onDisk(char *file, char *fileName);
int read_fromDisk(char *requestedfile, char requestedfile_content[100]);
int check_free_disk(int tam);
void delete_fromDisk(char *file);

//Ram:
void init_ram();
void open_file(char* file_name, char* mode);
void read_from_file(char* requestedfile, int num_bytes);
void close_file(char* file_name);
void delete_file(char* file_name);
int write_on_file(char* file_name, char* input);
int check_free_ram(int size);
int write_on_ram(char* file_content);
void print_disk();
void print_ram();
