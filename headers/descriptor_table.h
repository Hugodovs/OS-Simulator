#define MAX_FILE_NUMBER 10

typedef struct _InodeTuple {
    int id_file;
    int address_file;
    int size;
} InodeTuple;

extern InodeTuple inode_table[MAX_FILE_NUMBER];

int generate_fd();
void insert_tuple_inode_table(int fd, int index, int size);
void print_inode_table();
int get_address_from_id(int id_file);
void get_address_size_from_id(int id_file, int address_and_size[2]);
