/*Colin Wadge Assignment 3 V2*/
#ifndef UTILS_H
#define UTILS_H
int command_line_validation(int argc,char *argv[]);
int arguement_size(char arg[]);
int input_record(record *rec);
void display_records(record_list *list);
int sort_select(int argc,char *argv[],record_list *list);
void to_lower(char *name);
#endif