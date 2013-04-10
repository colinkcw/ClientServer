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
typedef struct node node;
struct node{
	record data;
	node *next;
};
typedef node *record_list;
int input_record(record *rec);
void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list,const record *rec);
void list_print(record_list *list);
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
	list_print(&list);
	list_destroy(&list);
	return 0;
}
void list_init(record_list *list){
	*list=0;
}
void list_destroy(record_list *list){
	node *p,*q;
	for(p=*list;p!=0;p=q){
		q=p->next;
		free(p);
	}
	*list=0;
}
int list_insert(record_list *list,const record *rec){
	node **tracer,*newnode;
	int n = 0;
	newnode=malloc(sizeof(node));
	if(newnode==0)
		return 0;
	newnode->data=*rec;
	for(tracer=list;*tracer!=0;tracer=&(*tracer)->next){
		if((*tracer)->data.score < rec->score){
			break;
		}
		if((*tracer)->data.score == rec->score){
			n = strcmp((*tracer)->data.name.last, rec->name.last); 
			if(n > 0){
				break;
			}
			if(n == 0){
				n = strcmp((*tracer)->data.name.first, rec->name.first); 
			}
			if(n > 0)
				break;
		}
	}
	newnode->next = *tracer;
	*tracer = newnode;
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
void list_print(record_list *list){
	node *p;
	for(p=*list;p!=0;p=p->next){
		printf("%s %s %d\n",p->data.name.first,p->data.name.last,p->data.score);
	}
}
int comp(record *rec1, record *rec2){
	int n;
	n = strcmp(rec1->name.first,rec2->name.first);
	if(n==0){
		n = strcmp(rec1->name.last,rec2->name.last);
	}
	return n;
}
int stop()