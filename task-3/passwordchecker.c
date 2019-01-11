#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
char *passwd=NULL;
int main(int argc, char **argv) {
	int lines=0;
	int i=0;
	size_t buf_len=0;
	char **word_array=NULL;
	char **init_array;
	FILE *file=NULL;
	// check command line argument
	if (argc < 2) {
		printf("[-] Usage : %s [Dictionary-File]\n", argv[0]);
		exit(1);
	}
	// load file
	file = loadFile(argv[1]);
	// caculate the number of lines of dictionary files
	lines=countLines(file);
	// rewind file back to file indicator = 0 and unset EOF
	rewind(file);
	// read file into heap
	word_array=(char**)malloc((lines) * sizeof(char*));
	// copy the word_array to init_array tfor returning
	init_array=word_array;
	// reset the array of char pointer to NULL for getline()
	for(i = 0; i < lines; i++) {
		*word_array = NULL;
		word_array++;
	}
	word_array = init_array;
	// copy the word into array in heap
	for(i = 0; i < lines; i++) {
		// getline() automatically malloc the space for word
		getline(word_array, &buf_len, file);
		word_array++;
	}
	// close 
	fclose(file);
	word_array=init_array;
	// sorting the array for binary search
	qsort(word_array, lines, sizeof(char*), compare);
	word_array = init_array;
	// adjust dictionary length 
	for(i = 0; i < lines; i++) {
		int j = strlen(*word_array);
		(*word_array)[j-2] = '\0';
		word_array++;
	}
	word_array = init_array;
	// Check the password 
	while(1) {
	    readPassword();
	    i = checkPassword(word_array, lines);
	    if (i == 0) {
			break;
		} 
	}
	// clear dynamic memories
	i=0;
	word_array=init_array;
	while(i < lines) {
		free(*word_array);
		word_array++;
		i++;
	}
	free(passwd);
	return 0;	
}

