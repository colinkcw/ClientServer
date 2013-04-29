/* Colin Wadge A00688413 Version 1.0*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINESIZE	1024
void start_program(FILE *fp);
int menu(const char *choices[], const char *prompt);
int enter_data(FILE *fp);
void display_data(FILE *fp);
void exit_program(FILE *fp);
void file_entry(const char first[], const char last[],int score,FILE *fp);
char* name_format(char name[]);
int main(void){
	FILE *fp;
	if((fp=fopen("data.txt", "w+"))==0){
		perror("fopen");
	}
	start_program(fp);
	return 0;
}
void start_program(FILE *fp){
	const char *choices[] ={"Enter Data","Display Data","Exit",0};
	char prompt[] = {"Please make a selection<"};
	int number = 0;
	int returned = 1;
	while(1){
		number = menu(choices,prompt);
		if(number == 1){
			while(returned == 1){
				returned = enter_data(fp);
			}
			returned = 1;
		}else if(number == 2){
			display_data(fp);
		}else{
			exit_program(fp);
			break;
		}
	}
}
int menu(const char *choices[], const char *prompt){
	int no = 0;
	int counter = 0;
	char line[LINESIZE];
	while(1){
		for(counter = 0; choices[counter] != 0; counter++){
			printf("%d %s\n",counter+1,choices[counter]);
		}
		printf("%s ",prompt);
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			no = 3;
			break;
		}
		if(sscanf(line," %d ",&no) == 1){
			if(1 <= no && no <= counter){
				break;
			}
		}
	}
	return no;
}
int enter_data(FILE *fp){
	char enter_prompt[] = {"enter first name and last name"}; 
	char enter_score[] = {"enter class score"};
	char line[LINESIZE],first[LINESIZE], last[LINESIZE],extra[LINESIZE];
	char exit[]={"!!"};
	int score = 0;
	while(1){
		printf("%s\n", enter_prompt);
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			return 0;
		}
		if(sscanf(line," %[A-Za-z-] , %s ",last,first) == 2){
			if(sscanf(first,"%[A-Za-z-]%c",first,extra)==1){
				break;
			}
		}
		if(sscanf(line," %[A-Za-z-]  %s ",first,last) == 2){
			if(sscanf(last,"%[A-Za-z-]%c",last,extra)==1){
				break;
			}
		}
		if(sscanf(line," %[!] ",first) == 1){
			if(strcmp(first,exit) == 0){
				return 0;
			}
		}
	}
	while(1){
		printf("%s\n",enter_score);
		if(!fgets(line,LINESIZE,stdin)){
			clearerr(stdin);
			return 0;
		}
		if(sscanf(line,"%d",&score)==1){
			if(0 <= score && score <= 100){
				file_entry(first,last,score,fp);
				break;
			}
		}
	}
	return 1;
}
void display_data(FILE *fp){
	int score = 0;
	int min = 0, max = 0, total = 0, numberOfStudents = 0;
	float avg = 0;
	char firstName[LINESIZE];
	char lastName[LINESIZE];
	printf("display\n");
	rewind(fp);
	while(fscanf(fp," %[a-zA-Z-] %[a-zA-Z-] %d",firstName,lastName,&score) == 3){
		fprintf(stderr,"%s,",name_format(lastName));
		fprintf(stderr," %s:",name_format(firstName));
		fprintf(stderr,"%4d\n",score);
		if(numberOfStudents == 0){
			min = score;
			max = score;
		}else if(score < min){
			min = score;
		}else if(score > max){
			max = score;
		}
		total += score;
		numberOfStudents++;
	}
	avg = (float)total /(float) numberOfStudents;
	fprintf(stderr,"Min: %3d, Max: %3d, Ave: %6.2f\n",min,max,avg);
}
void exit_program(FILE *fp){
	printf("goodbye!\n");
	if(fclose(fp)!= 0){
		perror("fclose");
	}
}
void file_entry(const char first[], const char last[],int score,FILE *fp){
	fprintf(fp,"%s ",first);
	fprintf(fp,"%s ",last);
	fprintf(fp,"%d ",score);
}
char* name_format(char name[]){
	size_t i = 0;
	char* formatted;
	char newname[LINESIZE];
	newname[0] = toupper((int)name[0]);
	for(i = 1; name[i] != '\0'; i++){
		newname[i] = tolower((int)name[i]);
	}
	newname[i] = '\0';
	formatted = newname;
	return formatted;
}