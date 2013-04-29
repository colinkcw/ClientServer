#include <stdio.h>
#include <string.h>
#define LINESIZE	1024
int get_word(const char prompt[],char word[],size_t n);
int get_int(const char prompt[],int min, int max, int *pnum);
int main(void){
	size_t i = 5;
	char word[LINESIZE];
	int n = 0, m = 0, max = 9, min = 1, num = 0; 
	char prompt[] = "enter", prompt2[] = "enter number";
	n = get_word(prompt,word,i);
	m = get_int(prompt2,min,max,&num);
	printf("%d\n%d\n",n,num);
	return 0;
}
/*
	returns 0 on end of file 1 if a word is successfully read and stored in the array word of n characters
*/
int get_word(const char prompt[],char word[],size_t n){
	char line[LINESIZE];
	char text[LINESIZE];
	while(1){
		printf("%s\n",prompt);
		
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			return 0;
		}
		if(sscanf(line,"%s",text)==1){
			if(strlen(text) < n){
				strcpy(word,text);
				return 1;
			}
		}
	}
}
/*
	returns 0 on end of file 1 if an integer between min and max is successfully read and stored through the pointer pnum
*/
int get_int(const char prompt[],int min, int max, int *pnum){
	char line[LINESIZE];
	int num = 0; 
	while(1){
		printf("%s\n",prompt);
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			return 0;
		}
		if(sscanf(line,"%d",&num) == 1){
			if(num >= min && num <= max){
				*pnum = num; /*storing num into destination(pnum)*/
				return 1;
			}
		}
	}
}