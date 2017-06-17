#define MAX_INSTRUCTION_NUMBER 100

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/workflow.h"
#include "../headers/memory.h"
#include "../headers/screen.h"
#include "../headers/directory_table.h"
#include "../headers/descriptor_table.h"
#include "../headers/ram_file_table.h"





void get_next_Instruction() {
	char instruction[100];
	//const char delimiters[] = " .,;:!-";
	const char delimiter[] = " ";  // only using the space delimiter for now


	fgets(instruction, 100, stdin);
	if (instruction[0]=='\n') {
			printf("Uh oh... it looks like you did not use our I/O simulator properly =(\n");
	}
	else {
		char *instruction_word = (char *) malloc (101*sizeof(char));
		char *instruction_copy = (char *) malloc (101*sizeof(char));
		strcpy(instruction_copy,strtok(instruction, "\n"));
		instruction_word = strseparator(&instruction_copy,delimiter);
		if (strcmp(instruction_word, "open")==0) {
			// Will read some file
			instruction_word = strseparator(&instruction_copy,delimiter);
			if (instruction_word==NULL || strcmp(" ",instruction_word)==0)
				printf("Uh oh... it looks like you did not use our I/O simulator properly =(\n");
			else {
				printf("The user would like to 'open' the file (%s)\n", instruction_word);
				execute_open_Operation(instruction_word);
			}

		}

		else if (strcmp(instruction_word, "write")==0) {
			// Will write some data to an already read file
			char data[100]; data[0] = '\0';
			int words_numbers = 0;
			char instruction_words_line[MAX_INSTRUCTION_NUMBER][50];
			int k = 0;
			while(1) {
				instruction_word = strseparator(&instruction_copy,delimiter);
				if(instruction_word==NULL)
					break; // All line is read
				else {
					strcpy(instruction_words_line[words_numbers], instruction_word);
					words_numbers++;
				}
			}

			while(1) {
				if(!(strcmp(instruction_words_line[k], "in")==0)) {
 					strcat(data, instruction_words_line[k++]);
 					strcat(data, " ");
				}
				else {
					data[strlen(data)-1] = '\0'; // Deleting extra space from previous condition
					break;
				}
			}
			write_on_file(instruction_words_line[k+1], data);
			//printf("The user would like to 'write' the following data (%s) to the address (%d)\n", data, destination_address);

		}

		else if (strcmp(instruction_word, "read")==0) {
			instruction_word = strseparator(&instruction_copy,delimiter);  // FileName
			int size = atoi(strseparator(&instruction_copy,delimiter));
			printf("The user would like to 'read' the file (%s), with size (%d)\n", instruction_word, size);
			read_from_file(instruction_word, size);
		}

		else if (strcmp(instruction_word, "close")==0) {
			instruction_word = strseparator(&instruction_copy,delimiter);  // FileName
			printf("The user would like to 'close' the following file (%s)\n", instruction_word);
			close_file(instruction_word);
		}

		else {
			printf("Uh oh... it looks like you did not use our I/O simulator properly =(\n");
		}

		/*puts("oi antes do free");
		free(instruction_word);
		puts("depois antes primeiro do free");
		free(instruction_copy);
		puts("depois antes do free");*/
	}


}



char* strseparator(char** stringp, const char* delim) {
  char* start = *stringp;
  char* p;

  p = (start != NULL) ? strpbrk(start, delim) : NULL;

  if (p == NULL)
  {
    *stringp = NULL;
  }
  else
  {
    *p = '\0';
    *stringp = p + 1;
  }

  return start;
}

void execute_open_Operation (char *fileName) {
	open_file(fileName, "r");
	//If there is anything else interesting to report...
}

void execute_write_Operation (char *fileName) {
	//(fileName);
	//If there is anything else interesting to report...
}

void execute_read_Operation (char *fileName) {
	//open_file(fileName);
	//If there is anything else interesting to report...
}

void execute_close_Operation (char *fileName) {
	//open_file(fileName);
	//If there is anything else interesting to report...
}
