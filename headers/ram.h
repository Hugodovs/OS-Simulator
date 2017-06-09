// RAM
#define RAM_CAPACITY 5


extern char file1[];
extern char primary_mem[RAM_CAPACITY];
void write_onRAM(int mem_address , int idFile);
void read_fromRAM(int mem_address);
