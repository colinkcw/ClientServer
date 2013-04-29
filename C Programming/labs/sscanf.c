#include <stdio.h>
#define LINESIZE	1024
int get_last_first(FILE *fp);
int get_first_last(FILE *fp);
int main(void){
	get_last_first(stdin);
	get_first_last(stdin);
	return 0;
}
/*
	function used for user name input where the user must eneter,
	a last name then a first name
*/
int get_last_first(FILE *fp){
	char line[LINESIZE];
	char first[LINESIZE], last[LINESIZE];
		printf("Enter an name: ");
		if (!fgets(line, LINESIZE,fp)){ 
			clearerr(stdin);
			return 0;
		}
		if (sscanf(line," %[A-Za-z] , %[A-Za-z-] ",first,last) ==2) {
			printf("%s %s \n",first,last);
			return 1;
		}
	return -1;
}
/*
	function used for entering a user name first then last 
*/
int get_first_last(FILE *fp){
	char line[LINESIZE];
	char first[LINESIZE], last[LINESIZE];
		printf("Enter an name: ");
		if (!fgets(line, LINESIZE,fp)){ 
			clearerr(stdin);
			return 0;
		}
		if (sscanf(line," %[A-Za-z] %[A-Za-z-] ",first,last) ==2) {
			printf("%s %s",first,last);
			return 1;
		}
	return -1;
}
