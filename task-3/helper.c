#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// qsort callback function
// s1 and s2 from word_array (char **)
extern char* passwd;
int compare(const void *s1,const void *s2) {
	return strcmp(*(const char **)s1,*(const char **)s2);
}
// read password
void readPassword() {
	if (passwd != NULL) {
		free(passwd);
		passwd = NULL;
	}
	size_t l = 0;
	size_t k = 0;
	printf("[>] Please Enter the Password to check : ");
	k = getline(&passwd, &l, stdin);
	passwd[k-1] = '\0';
}
// accept file
void *loadFile(char *filename) {
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		perror("[-] File can not be open!!!\n");
		exit(1);
	} else {
		return f;
	}
}
// count dictionary file lines
int countLines(FILE *f) {
	int wc = 0; // word count -> line count
	int c = 0;  // character
	char n = 0; // 0 for new line otherwise 0
	do{
		c = fgetc(f);
		if(c == EOF) {
			if(n == 1) {
				break;
			} else {
				wc++;
				break;
			}
		}
		if((unsigned char)c == '\n') {
			wc++;
			n = 1;
			continue;
		}
		n = 0;
	} while(1);
	return wc;
}
// check password strength
int checkPassword(char **wa, int l) {
	if(passwd[0] == '\0') {
		printf("[+] Thanks for using...\n");
		return 0;
	}
	if(bsearch (&passwd, wa, l, sizeof(char*), compare) != NULL) {
		printf("[-] Password is in Dictionary list and not strong...\n");
		return 1;
	}
	if(strlen(passwd) < 8) {
		printf("[-] Password length is less than 7 and not strong...\n");
		return 1;
	} else {
		printf("[+] Strong password...\n");
		return 1;
	}		
}
