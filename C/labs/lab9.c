#include <stdio.h>
int *arr_last_max(const int *a,size_t n);
size_t str_replace_all(char *s,int oldc,int newc);
char *str_find_last(const char *s, int c);
int main(void){
	int *m;
	size_t n = 5,j=0;
	int a[]={3,2,2,3,2};
	char x[]={"hello"};
	char *b;
	
	m=arr_last_max(a,n);
	j=str_replace_all(x,'l','f');
	b=str_find_last(x,'o');
	
	printf("%d\n",*m);
	printf("%d\n",j);
	printf("%c\n",*b);
	return 0;
}
int *arr_last_max(const int *a,size_t n){
	const int *p;
	const int *max=a; 
	for(p=a;p<a+n;p++){
		if(*p>=*max){
			max=p;
		}
	}
	return (int *)max;
}
size_t str_replace_all(char *s,int oldc,int newc){
	char *p;
	size_t i =0;
	for(p=s;*p!='\0';p++){
		if(*p==oldc){
			*p=newc;
			i++;
		}
	}
	return i;
}
char *str_find_last(const char *s, int c){
	const char *p;
	const char *last = 0;
	for(p=s;*p!='\0';p++){
		if(*p==c){
			last=p;
		}
	}
	return (char *)last;
}