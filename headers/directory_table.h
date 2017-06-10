#define MAX_FILE_NUMBER 5

typedef struct _DirectoryTuple {
    char filename[50];
    int id_file;
} DirectoryTuple;



void insert_tuple_direct_table(int fd, char* filename);



int find_file_id(char* filename);
void print_directory_table();
