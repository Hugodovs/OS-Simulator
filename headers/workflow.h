
extern char secondary_mem[DISK_CAPACITY];
extern char primary_mem[RAM_CAPACITY];

void get_next_Instruction();
void execute_open_Operation(char *file);
void execute_read_Operation(char *file);
void execute_write_Operation(char *file);
void execute_close_Operation(char *file);
char* strseparator(char** stringp, const char* delim);