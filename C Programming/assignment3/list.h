/*Colin Wadge Assignment 3 V2*/
#ifndef LIST_H
#define LIST_H
void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list, const record *rec);
#endif