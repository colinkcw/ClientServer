
/*
 this exercise was to show how input and output
 using structures and array of structures would be achieved 
*/
#include <stdio.h>
#include <string.h>
#define	NAMESIZE	20
#define LINESIZE	1024
typedef struct name name;
struct name{
	char last[NAMESIZE];
	char first[NAMESIZE];
};
typedef struct record record;
struct record{
	name name;
	int score;
}; 
int input_record(record *rec);
void print_records(const record a[],size_t n); 
int main(void){
	size_t i = 0,n=10;
	int m = 0;
	record rec[10],*r,r1;
	for(i=0;i<n;){
		r=&r1;
		m=input_record(r);
		if(m==1)
			rec[i++]=r1;
		if(m==0)
			break;
	}
	print_records(rec,i);
	return 0;
}
int input_record(record *rec){
	char line[LINESIZE],firstName[LINESIZE],lastName[LINESIZE];
	int mark=0;
	printf("enter record\n");
	if(!fgets(line,LINESIZE,stdin)){
		perror("fgets");
		return 0;
	}
	if(sscanf(line,"%[a-zA-Z] %[a-zA-z] %d",firstName,lastName,&mark)==3){
		if(strlen(firstName)>NAMESIZE||strlen(lastName)>NAMESIZE){
			return -1;
		}
		if(mark>100||mark<0){
			return -1;
		}
		strcpy(rec->name.last,lastName);
		strcpy(rec->name.first,firstName);
		rec->score=mark;
		return 1;
	}
	return -1;
}
void print_records(const record a[],size_t n){
	size_t i = 0;
	printf("printing\n");
	for(i=0;i<n;i++){
		printf("%s %s %d\n",a[i].name.first,a[i].name.last,a[i].score);
	}
}