#define SCREEN_SIZE 120

extern char primary_mem[RAM_CAPACITY];
extern char secondary_mem[DISK_CAPACITY];
extern char screen_buffer[SCREEN_SIZE];

void print_ComputerStatus();
void print_DiskStatus();
void print_RAMStatus();
void print_directory_table();
void print_descriptor_table();
void set_DiskStatus_on_buffer();
void init_screen();
void update_screen();
