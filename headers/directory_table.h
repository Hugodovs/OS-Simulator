#define MAX_FILE_NUMBER 10

typedef struct _DirectoryTuple {
    char filename[50];
    int id_file;
} DirectoryTuple;

extern DirectoryTuple directory_table[MAX_FILE_NUMBER];

void insert_tuple_direct_table(int fd, char* filename);
int find_file_id(char* filename);
