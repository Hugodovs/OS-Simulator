#define DISK_CAPACITY 40
#define RAM_CAPACITY 20


extern char secondary_mem[DISK_CAPACITY];
extern char primary_mem[RAM_CAPACITY];

void get_next_Instruction();
void execute_open_Operation(char *file);
void execute_read_Operation(char *file, int size);
void execute_write_Operation(char *file, char *newdata);
void execute_close_Operation(char *file);
void execute_delete_Operation (char *fileName);
char* strseparator(char** stringp, const char* delim);
