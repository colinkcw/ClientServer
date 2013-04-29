#include <stdio.h>
#include <ctype.h>
void func_one(FILE* fp);
void func_two(FILE* fp);
int main(void){
	FILE* fp;
	if((fp=fopen("file.txt", "rb"))==0){
		perror("fopen");
	}
	func_one(fp);
	printf("\n\n");
	func_two(fp);
	return 0;
}
/*
 dumps contents of a file in hexadecimal format
*/
void func_one(FILE* fp){
	int c;
	int charcount = 0;
	while((c=fgetc(fp))!=EOF){
		if((charcount%16)==0){
			fprintf(stderr,"\n%07x  ",charcount);
		}
		fprintf(stderr,"%02x  ",c);
		charcount++;
	}
	fprintf(stderr,"\n%07x",charcount);
}
/*
	dumps contents of a file in octal
*/
void func_two(FILE* fp){
	int c;
	int charcount = 0;
	rewind(fp);
	while((c=fgetc(fp))!=EOF){
		if((charcount%16)==0){
			fprintf(stderr,"\n%07x  ",charcount);
		}
		fprintf(stderr,"%03o  ",c);
		charcount++;
	}
	fprintf(stderr,"\n%07x",charcount);
}