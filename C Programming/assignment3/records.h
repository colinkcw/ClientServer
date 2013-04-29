/*Colin Wadge Assignment 3 V2*/
#ifndef RECORD_H
#define	NAMESIZE	20
#include <stdio.h>
typedef	struct name name;
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
#endif