#define MAX_FILE_NUMBER 5

//File Descriptor Table
typedef struct _FileDescriptorTuple {
    int id_file;
    int address_file;
    int size;
} FileDescriptorTuple;

extern FileDescriptorTuple file_descriptor_table[MAX_FILE_NUMBER];


int generate_fd();
void insert_tuple_descrip_table(int fd, int index, int size);
void print_descriptor_table();
