

#define MAX_FILE_NUMBER 5

//File Descriptor Table
typedef struct _DirectoryTuple {
    char path_file[50];
    int id_file;
} DirectoryTuple;

extern DirectoryTuple directory_table[MAX_FILE_NUMBER];