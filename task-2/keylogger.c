#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>

#define COUNT 30
// key code event structure
struct event {
	unsigned char keycode;
	struct timeval timestamp;
};

void main(void) {
	int i = 0; // event code count 
	FILE *file = fopen("keylog.txt","w");
	int key; // key event code read from getchar()
	unsigned char keyinfo[16];
	// store 30 key event codes 
	struct event keyevent[COUNT];
	while(i < COUNT) {
		// read key event code
		key=getchar();
		// check space or not
		if(isspace(key)) {
			continue;
		}
		keyevent[i].keycode = (unsigned char) key;
		// event timestamp function from sys/time 
		gettimeofday(&keyevent[i].timestamp, NULL);
		i++;
	}
	for(i = 0; i < COUNT; i++) {
		sprintf(keyinfo, "%c:%lld\n", keyevent[i].keycode,(keyevent[i].timestamp.tv_sec)*1000+(keyevent[i].timestamp.tv_usec)/1000);
		// store the key code:timestamp into keylog.txt
		fputs(keyinfo, file);
	}
	fclose(file);
	// send the file to server:8000
	system("nc localhost 8000 < ./keylog.txt");
}
