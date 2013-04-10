#include <stdio.h>
#define LINESIZE 	1024
int menu(const char *choices[], const char *prompt);
int main(void){
	const char *choices[] = {"Enter data","Display data", "Quit",0};
	char prompt[] = {"please make a selection"};
	int m = 0;
	m = menu(choices, prompt);
	printf("%d \n",m);
	return 0;
}
int menu(const char *choices[], const char *prompt){
	int i = 0;
	int n = 0;
	char line[LINESIZE];
	while(1){
		for(i = 0; choices[i] != 0; i++){
			printf("%d %s\n",i+1,choices[i]);
		}
		printf("%s\n",prompt);
		if (!fgets(line, LINESIZE, stdin)){ 
			clearerr(stdin);
			return 0;
		}
		if ( sscanf(line, "%d", &n) ==1){
			if(1 <= n && n <= i){
				break;
			}
		}
	}
	return n;
}