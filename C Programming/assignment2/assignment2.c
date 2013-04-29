/*Colin Wadge A00688413 Assignment 2 V3.0 final*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINESIZE	1024
int display(int b, int c, int C,int skip, int nlength, char filename[]);
void onebyte_octal(int skip,int nlength, FILE* fp);
void onebyte_character(int skip,int nlength, FILE* fp);
void canoical_display(int skip,int nlength, FILE* fp);
void default_display(int skip,int nlength, FILE* fp);
int length_conversion(char sorn[]);
int escape_print(int c);
int main(int argc, char *argv[]){
	size_t i=0,j=0;/*loop counters*/
	int length=0,/*str length*/
		b=0,c=0,C=0,dash=0,invalid=0,valid=0,/*switch flags*/
		ch=0,/*current character*/
		filecounter=0;
		unsigned int s=0,n=0;
		int offset=0,nlength=0;/*store length and offset*/
		char fileName[LINESIZE]={0};/*file name buffer*/
	for(i=1;(int)i<argc;i++){/*loop through arguements*/
		if(argv[i][0]=='-'&&dash==0){/*check for file indicators*/
			length=strlen(argv[i]);
			for(j=1;(int)j<length;j++){/*loop through options*/
				valid=0;
				ch = (int)argv[i][j];
				switch(ch){ /*check for valid options*/
					case 'b':
						b=1; /*if valid option set flag*/
						valid=1;
						break;
					case 'c':
						c=1;
						valid=1;
						break;
					case 'C':
						C=1;
						valid=1;
						break;
					case 's':
						if(valid==0){/*to ensure s is not included with other flags ie no -cs100*/
							if(argv[i][2]=='-'){/*if negative print error message*/
								printf("only non negative numbers\n");
								return 1;
							}else if((sscanf(argv[i],"-s0x%x",&s))==1){ /*check that entered string is valid*/
								offset=(int)s;/*initialize offset to s*/
								j=strlen(argv[i]);/*set j to the end of the string*/
							}else if((sscanf(argv[i],"-s0%o",&s))==1){
								offset=(int)s;
								j=strlen(argv[i]);
							}else if((sscanf(argv[i],"-s0X%x",&s))==1){
								offset=(int)s;
								j=strlen(argv[i]);
							}else if((sscanf(argv[i],"-s%d",&offset))==1){		
								j=strlen(argv[i]);
							}else{
								printf("invalid number");/*if not a number of any kind*/
								return 1;
								invalid=1;
							}
						}else{
							invalid=1;
						}
						break;
					case 'n':
						if(valid==0){
							if(argv[i][2]=='-'){
								printf("only non negative numbers\n");
								return 1;
							}else if((sscanf(argv[i],"-n0x%x",&n))==1){ /*check that entered string is valid*/
								nlength=(int)n;
								j=strlen(argv[i]);
							}else if((sscanf(argv[i],"-n0%o",&n))==1){
								nlength=(int)n;
								j=strlen(argv[i]);
							}else if((sscanf(argv[i],"-n0X%x",&n))==1){
								nlength=(int)n;
								j=strlen(argv[i]);
							}else if((sscanf(argv[i],"-n%d",&nlength))==1){		
								j=strlen(argv[i]);
							}else{
								printf("invalid number can be non negative hex oct or decimal\n");
								return 1;
								invalid=1;
							}
						}else{
							invalid=1;
						}
						break;
					case '-':
						dash=1;
						break;
					default:
							printf("invalid entry please enter a valid entry\n");
							invalid++;				
				}
			}
		}else{
				strcpy(fileName,argv[i]);/*copy file name into usable string*/
				filecounter++;
		}
	}
	if(filecounter > 1){/*for handleing more than one file entered*/
		printf("only one file allowed\n");
		invalid++;
	}
	if(invalid==0){/*if no invalid arguements were entered proceed*/
		if(display(b,c,C,offset,nlength,fileName)==1){
			return 1;
		}
	}
	return 0;
}
int display(int b, int c, int C,int skip,int nlength, char filename[]){
	FILE* fp;
	int size=0;
	if((fp=fopen(filename,"r"))==0){
		perror("fopen");
	}
	fseek(fp,0,SEEK_END);/*check that skip and offset are within file*/
	size=ftell(fp);
	if(skip>size||nlength>size){
		return 1;
	}
	if(size==0){/*if nothing in file do nothing*/
		return 1;
	}
	if(b==1){/*based on flag entered use correct function */
		onebyte_octal(skip,nlength,fp);
	}else if(c==1){
		onebyte_character(skip,nlength,fp);
	}else if(C==1){
		canoical_display(skip,nlength,fp);
	}else{
		default_display(skip,nlength,fp);
	}
	return 0;
}
void onebyte_octal(int skip, int nlength, FILE* fp){
	int c, charcount=skip,ccount=0;
	fseek(fp,skip,SEEK_SET);/*seek to the specified amount*/
	while((c=fgetc(fp))!=EOF){
		if((ccount%16)==0&&ccount!=0){/*if the count is not a zero but is divisable print*/
			printf("\n%07x",charcount);
		}else if(ccount==0){/* first line to be printed no new line*/
			printf("%07x",charcount);
		}
		printf(" %03o",c);
		charcount++;
		ccount++;
		if(ccount==nlength){
			break;
		}
	}
	printf("\n%07x\n",charcount);
}
void onebyte_character(int skip,int nlength, FILE* fp){
	int c, charcount=skip,ccount=0;
	fseek(fp,skip,SEEK_SET);
	while((c=fgetc(fp))!=EOF){
		if((ccount%16)==0&&ccount!=0){
			printf("\n%07x",charcount);
		}else if(ccount==0){
			printf("%07x",charcount);
		}
		if(isprint(c)!=0){
		printf(" %3c",c);
		}else if((escape_print(c))==0){/*if tha character is not an escape character*/
			printf(" %03o",c);/*print the character as an octal */
		}
		charcount++;
		ccount++;
		if(ccount==nlength){
			break;
		}
	}
	printf("\n%07x\n",charcount);
}
void canoical_display(int skip,int nlength, FILE* fp){
	int c, charcount=skip,/*total chracters from start of file*/
	ccount=0,/*characters per line*/
	i=0,linecount=0/*counts number of lines printed*/,
	spaceneeded=0,/*number of space padding for last line*/
	charread=0;/*total characters read since start of function*/
	int line[LINESIZE];
	fseek(fp,skip,SEEK_SET);
	while((c=fgetc(fp))!=EOF){
		if((ccount%16)==0){/*when char count is divisable by 16 start new line*/
			if(linecount>0){/*to ensure nothing is printed at begining of function*/
				printf("  |");
				for(i=0;i<16;i++){/*loop through the 16 charcters*/
					if(isprint(line[i])!=0){
						printf("%c",line[i]);/* if a printable character print it*/
					}else{
						printf(".");
					}
				}
				printf("|");
			}
			if(ccount==0){
				printf("%08x",charcount);/*for the first line*/
			}else{
				printf("\n%08x",charcount);/*all the other lines*/
			}
			linecount++;
			i=0;
			ccount=0;
			
		}
		if((ccount%8)==0){/*if counter is divisable by 8 skip two spaces*/
			printf(" ");
		}
		line[i]=c;
		printf(" %02x",c);
		charcount++;
		ccount++;
		charread++;
		i++;
		if(charread==nlength){/*if characters read is equal to nlength break*/
			break;
		}
	}
	spaceneeded=16-ccount;
	if(spaceneeded >=8){/*print the last line of characters */
		printf(" ");
	}
	for(i=0;i<=spaceneeded-1;i++){
		printf("   ");
	}
	printf("  |");
	for(i=0;i<ccount;i++){
		if(isprint(line[i])!=0){
			printf("%c",line[i]);
		}else{
			printf(".");
		}
	}
	printf("|");
	printf("\n%08x\n",charcount);
}
void default_display(int skip,int nlength, FILE* fp){
	int c, charcount=skip,ccount=0;
	fseek(fp,skip,SEEK_SET);
	while((c=fgetc(fp))!=EOF){
		if((ccount%16)==0&&ccount!=0){
			printf("\n%07x",charcount);
		}else if(ccount==0){
			printf("%07x",charcount);
		}
		printf(" %02x",c);
		charcount++;
		ccount++;
		if(ccount==nlength){
			break;
		}
	}
	printf("\n%07x\n",charcount);
}
int escape_print(int c){/*for dealing with characters that require escape character*/
	int ch = c;
	switch (ch){
		case '\0':
			printf("  \\0");
			return 1;
			break;
		case '\a':
			printf("  \\a");
			return 1;
			break;
		case '\b':
			printf("  \\b");
			return 1;
			break;
		case '\f':
			printf("  \\f");
			return 1;
			break;
		case '\n':
			printf("  \\n");
			return 1;
			break;
		case '\r':
			printf("  \\r");
			return 1;
			break;
		case '\t':
			printf("  \\t");
			return 1;
			break;
		case '\v':
			printf("  \\v");
			return 1;
			break;
		default:
			return 0;
	}
}