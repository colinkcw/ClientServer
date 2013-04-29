/*Colin Wadge Assignment 3 V2*/
#include "records.h"
#include <stdio.h>
#include <stdlib.h>
void list_init(record_list *list){/*intilize record list and zero variables*/
	list->data=0;
	list->nalloc=0;
	list->nused=0;
}
void list_destroy(record_list *list){/*free allocated memory and zero variables*/
	free(list->data);
	#ifdef DEBUG
		fprintf(stderr,"@\n");
	#endif
	list->data=0;
	list->nalloc=0;
	list->nused=0;
}
int list_insert(record_list *list, const record *rec){/*insert the record into the list*/
	record *temp;/*temporary record to ensure no loss of data*/
	size_t nalloc,nused;/*number of allocated records and number of used records*/
	nalloc = list->nalloc;
	nused = list->nused;
	if(nalloc==0){/*if nalloc equals 0 allocate enough memory for one record*/
		temp=realloc(list->data,sizeof(record));
		if(temp==0){
			return 0;
		}
		#ifdef DEBUG
			fprintf(stderr, "#\n");
		#endif
		nalloc++;/*increment the number of allocated records by one*/
		list->data=temp;
		list->nalloc=nalloc;
	}else if(nalloc==nused){/*if number allocated is equal to number used*/
		temp=realloc(list->data,(2*nalloc)*sizeof(record));/*allocate two times as much memory*/
		if(temp==0){
			return 0;
		}
		#ifdef DEBUG
			fprintf(stderr, "#\n");
		#endif
		list->data=temp;
		nalloc*=2;
		list->nalloc=nalloc;
	}
	list->data[nused]=*rec;
	nused++;
	list->nused=nused;
	return 1;
}
