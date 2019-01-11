#include <stdio.h>
#include <stdlib.h>
const int COLUMNS=16;
int main(int argc, char *argv[]) {
	int i = 0; // index for for loop
	int c = 0; // number of reading from file
	int tline = 1; // each line space count
	int terminal_line = 0; // terminal screen line count
	int line = 0;  // line count for every 16 bytes					
	unsigned char buf[COLUMNS]; // buffer for 16 bytes
	FILE *f = NULL; 
	// command line argument check
	if (argc < 2 || argc > 3) {
		printf("[!] Usage : ./hexdump [file] [lines]\n");
		printf("	lines : optional for pause (Default to 40)\n");
		return 1; 
	}
	if (argc == 3) {
		terminal_line = atoi(argv[2]);
	} else {
		// default pause line
		terminal_line = 40;
	}
	f = fopen(argv[1], "r");
 	if (f == NULL) {
		printf("[-] File not exist or fail to open the file...\n");
		return 1;
	}
	// clear terminal screan	
	system("clear");
	while (1) {
		// read sixteen 1 byte into buf
		c = fread(buf, 1, COLUMNS, f);
		// starting momory address for each line (4 bytes)
		if (c == 0) break;
		printf("%08x   ", line);
		// print bytes on line defends on the reading by fread() 
		for (i = 0; i < c; i++) {
			printf("%02x ", buf[i]);
		}
		// check for line alighment
		if (c < 16) { 
			for (i = c; i < COLUMNS; i++) {
				printf("   ");
			}
		}
		// print ascii code for each line
		printf("  |");
		for (i = 0; i < c; i++) {
			// printable character check
			(buf[i] >= 32 && buf[i] < 127) ? putchar(buf[i]) : putchar('.'); 	
		}
		// check for line alignment	
		if (c < 16) { 
			for (i = c; i < COLUMNS; i++) {
				putchar(' ');
			}
		}	
		printf("|\n");
		line = line + 16;
		tline++; 	
		if (tline == terminal_line) {
			tline = 1;
			printf("[+] Press enter to continue ...");
			getchar();
			system("clear");
		}
		if (feof(f)) break;

	}
	fclose(f);
	return 0;
}
