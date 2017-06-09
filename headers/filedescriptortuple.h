

#define MAX_FILE_NUMBER 5

//File Descriptor Table
typedef struct _FileDescriptorTuple {
    int id_file;
    int address_file;
} FileDescriptorTuple;

extern FileDescriptorTuple file_descriptor_table[MAX_FILE_NUMBER];