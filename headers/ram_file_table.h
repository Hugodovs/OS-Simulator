#define MAX_FILE_NUMBER 10

typedef struct _FILE_RAM_TUPLE {
  int file_id;
  int ram_file_address;
  int file_size;
  int file_ptr;
  char mode[3];
  char* permissions;
} FILE_RAM_TUPLE;

extern FILE_RAM_TUPLE files_ram_table[MAX_FILE_NUMBER];
extern int NUM_FILES_OP;

void insert_tuple_file_ram_table(char* file_name, char* mode, int ram_file_address, int file_size);
void print_ram_table();
