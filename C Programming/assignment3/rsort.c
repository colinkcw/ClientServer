/*Colin Wadge Assignment 3 V2*/
#include <stdio.h>
#include <stdlib.h>
#include "records.h"
#include "utils.h"
#include "list.h"
#include "sort.h"
int main(int argc,char *argv[]){
	record_list list;
	record r;
	int n;
	if(command_line_validation(argc,argv)==0){/*validate command line arguements*/
		#ifndef	DEBUG
			printf("program invoked incorrectly");/*print out error meesage if program is not invoked correctly*/
		#endif
		#ifdef DEBUG
			fprintf(stderr,"program invoked incorrectly");
		#endif
		return 1;/*if invalid return 1 and end program*/
	}/*if arguements are valid intillize list and start record input*/
	list_init(&list);/*initilize the list*/
	while((n = input_record(&r))!=0){/*while there is a record to input*/
		if(n==1){
			if(!list_insert(&list,&r)){/*if list insert fails break */
				break;
			}
		}
	}
	sort_select(argc,argv,&list);/*sort the records specified by command line arguements*/
	display_records(&list);/*display the records within the list*/
	list_destroy(&list);/*destroy the list and free the memory*/
	return 0;
}