#include "../headers/directory_table.h"
#include <string.h>
#include <stdio.h>

DirectoryTuple directory_table[MAX_FILE_NUMBER];

int find_file_id(char* filename) {
    for(int i = 0; i < MAX_FILE_NUMBER; i++) {
        if (strcmp(directory_table[i].filename, filename) == 0) // igual a zero significa as strings serem iguais
            return directory_table[i].id_file;
    }

    return -1; // nao encontrou
}


void insert_tuple_direct_table(int id_file, char* filename) {
    DirectoryTuple tuple;
    strcpy(tuple.filename, filename); // como se fosse tuple.filename = filename;
    tuple.id_file = id_file;
    directory_table[id_file++] = tuple;
}


void print_directory_table() {
    for(int i = 0; i < MAX_FILE_NUMBER; i++) {
        printf("(Filename: %s, ID: %d)\n", directory_table[i].filename, directory_table[i].id_file);
    }
}
