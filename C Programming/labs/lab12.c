#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NLINES	256
#define LINESIZE	1028
int cmp(const void *p, const void *q);
int cmp2(const void *p, const void *q);
int main(int argc, char *argv[]){
	size_t i = 0,j;
	char buffer[LINESIZE];
	char lines[NLINES][LINESIZE];
	char *data[NLINES];
	while(i<257){
		if(!fgets(buffer,LINESIZE,stdin)){
			clearerr(stdin);
			break;
		}
		if(strlen(buffer)<128){
			strcpy(lines[i],buffer);
			i++;
		}
	}
	for(j=0;j<i;j++){
		data[j] = lines[j];
	}
	qsort(lines,i,sizeof(lines[0]),cmp);
	qsort(data,i,sizeof(data[0]),cmp2);
	for(j=0;j<i;j++){
		printf("%s",lines[j]);
	}
	printf("\n\n");
	for(j=0;j<i;j++){
		printf("%s",data[j]);
	}	
	return 0;
}
int cmp(const void *p, const void *q){
	const char *pp = (const char *)p;
	const char *qq = (const char *)q;
	return strcmp(pp,qq);
}
int cmp2(const void *p, const void *q){
	const char **pp = (const char **)p;
	const char **qq = (const char **)q;
	return strcmp(*pp,*qq);
}