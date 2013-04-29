/*Colin Wadge Assignment 3 V2*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "records.h"
#include "sort.h"
#define LINESIZE	1024
int arguement_size(char arg[]){/* checks if the current arguement is of size two*/
	size_t j = 0;/*loop counter*/
	int co=0; /* arguement counter*/
	for(j=0;arg[j]!='\0';j++){/*loop through command line arguement */
		co++;/*count number of characters*/
	}
	if(co == 2){/*if counter is 2 return 1*/
		return 1;
	}
	return 0;
}
int command_line_validation(int argc,char *argv[]){/*validates command line arguements*/
	size_t c1 = 0;/* loop counter */
	int s = 0, n = 0;
	for(c1=1;(int)c1<argc;c1++){/*loop through command line elements*/
		if(arguement_size(argv[c1])==0){/*if 0 is returned arguement size is invalid*/
			return 0;
		}
		switch(argv[c1][0]){/*check the first character*/
			case '+': 
				switch(argv[c1][1]){
					case 's':
						s++;/*increment the flag*/
						break;
					case 'n':
						n++;
						break;
					default:
						return 0;
				}
			break;
			case '-':
				switch(argv[c1][1]){
					case 's':
						s++;
						break;
					case 'n':
						n++;
						break;
					default:
						return 0;
				}
			break;
			default:
				return 0;
		}
	}
	if(n>1||s>1){/* if more than one occurance of s or n return 0*/
		return 0;
	}
	return 1;
}
int sort_select(int argc,char *argv[],record_list *list){/*sort the records specified by command line arguements*/
	if(argc == 1){
		return 0;
	}
	if(strcmp(argv[1],"+s")==0){
		if(argc == 2){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSplus);
			return 1;
		}
		if(strcmp(argv[2],"+n")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSplusNplus);
			return 1;
		}
		if(strcmp(argv[2],"-n")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSplusNminus);
			return 1;
		}
	}
	if(strcmp(argv[1],"-s")==0){
		if(argc == 2){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSminus);
			return 1;
		}
		if(strcmp(argv[2],"+n")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSminusNplus);
			return 1;
		}
		if(strcmp(argv[2],"-n")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpSminusNminus);
			return 1;
		}
	}
	if(strcmp(argv[1],"+n")==0){
		if(argc == 2){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNplus);
			return 1;
		}
		if(strcmp(argv[2],"+s")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNplusSplus);
			return 1;
		}
		if(strcmp(argv[2],"-s")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNplusSminus);
			return 1;
		}
	}
		if(strcmp(argv[1],"-n")==0){
		if(argc == 2){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNminus);
			return 1;
		}
		if(strcmp(argv[2],"+s")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNminusSplus);
			return 1;
		}
		if(strcmp(argv[2],"-s")==0){
			qsort(list->data, list->nused,sizeof(list->data[0]),cmpNminusSminus);
			return 1;
		}
	}
	return 0;	
}
char* to_lower(char name[]){/*set the alphabetical characters to lower case*/
	size_t i = 0;
	char* formatted;
	char newname[LINESIZE];
	for(i = 0; name[i] != '\0'; i++){
		if(isalpha((int)name[i])){
			newname[i] = tolower((int)name[i]);
		}else{
			newname[i] = name[i];
		}
	}
	newname[i] = '\0';
	formatted = newname;
	return formatted;
}
int validate_score(char score[]){/*checks that score is a valid whole number*/
	size_t i;
	for(i=0;score[i]!='\0';i++){
		if(!isdigit((int)score[i])){
			return 1;
		}
	}
	return 0;
}
int input_record(record *rec){/*reads user input and inputs the iformation into a record*/
	char line[LINESIZE],firstName[LINESIZE],lastName[LINESIZE],score[LINESIZE];/*buffers for user input*/
	int mark=0;
	if(!fgets(line,LINESIZE,stdin)){/*read in usre input*/
		clearerr(stdin);
		return 0;
	}
	if(sscanf(line," %[a-zA-Z0-9] %[a-zA-Z0-9] %[0-9.]",firstName,lastName,score)==3){/*validation*/
		if(strlen(firstName)>NAMESIZE||strlen(lastName)>NAMESIZE){
			return -1;
		}
		if(validate_score(score)==1){/*ensure score is of correct format*/
			return -1;
		}
		sscanf(score,"%d",&mark);/*scan score into a usable integer variable*/
		if(mark>100||mark<0){/*ensure that the score is within the acceptable boundries*/
			return -1;
		}
		strcpy(rec->name.last,to_lower(lastName));/*copy the names into there corresponding record positions*/
		strcpy(rec->name.first,to_lower(firstName));
		rec->score=mark;
		return 1;
	}
	return -1;
}
void display_records(record_list *list){/*displays the records*/
	size_t i =0;
	int n = 0,m = 0;
	char score[LINESIZE];/*buffer for the score*/
	for(i=0;i<list->nused;i++){
		n = strcmp(list->data[i].name.last,list->data[i-1].name.last);/*ensure no dublicate scores are entered back to back*/
		if(n==0){
			m = strcmp(list->data[i].name.first,list->data[i-1].name.first);
			if(m == 0 && list->data[i].score == list->data[i-1].score ){
				continue; /*if program reaches this point the current and last record are dublicates and the current record should be descarded*/
			}
		}/*otherwise print the names*/	
		printf("%s %s ",list->data[i].name.last, list->data[i].name.first);
		sprintf(score,"%d",list->data[i].score);/*create a string containing the score*/
		if(strlen(score)==1){/*if the score is only one character there are no leading zeros and print the score*/
			printf("%s\n",score);
		}else{
			printf("%s\n", (score[0] == '0' ? &score[1] : score));/*if the first element of the string is a zero desregard and start from the, */
																/*the second character in the string, continue this until the char is not a zero, then print string*/
		}
	}
}