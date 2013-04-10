#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMESIZE	20
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
typedef struct record_list record_list;
struct record_list{
	record *data;/*dynamic array*/
	size_t nalloc;
	size_t nused;
};
void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list, const record *rec);
int input_record(record *rec);
int main(void){
	record_list list;
	record r;
	int n;
	list_init(&list);
	while((n = input_record(&r))!=0){
		if(n==1){
			if(!list_insert(&list,&r)){
				break;
			}
		}
	}
	printf("1\n");
	list_destroy(&list);
	return 0;
}
void list_init(record_list *list){
	list->data=0;
	list->nalloc=0;
	list->nused=0;
}
void list_destroy(record_list *list){
	free(list->data);
	list->data=0;
	list->nalloc=0;
	list->nused=0;
}
int list_insert(record_list *list, const record *rec){
	record *temp;
	size_t nalloc,nused;
	nalloc = list->nalloc;
	nused = list->nused;
	if(nalloc==0){
		temp=realloc(list->data,sizeof(record));
		if(temp==0){
			return 0;
		}
		nalloc++;
		list->data=temp;
		list->nalloc=nalloc;
	}else if(nalloc==nused){
		temp=realloc(list->data,(2*nalloc)*sizeof(record));
		if(temp==0){
			return 0;
		}
		list->data=temp;
		nalloc*=2;
		list->nalloc=nalloc;
	}
	list->data[nused]=*rec;
	nused++;
	list->nused=nused;
	return 1;
}
int input_record(record *rec){
	char line[LINESIZE],firstName[LINESIZE],lastName[LINESIZE];
	int mark=0;
	printf("enter record\n");
	if(!fgets(line,LINESIZE,stdin)){
		clearerr(stdin);
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