#include <stdio.h>
#include <ctype.h>
#include <string.h>
int str_all_alphabets(const char s[]);
int str_has_alphabet(const char s[]);
size_t str_replace_all(char s[], int oldc, int newc);
int str_replace_first(char s[], int oldc, int newc);
int str_replace_last(char s[], int oldc, int newc);

int main (void){
	char a[] = "hello";
	char b[] = "goodbye";
	char c[] = "world";
	printf("%d\n",str_all_alphabets(a)==1);
	printf("%d\n",str_all_alphabets(b)==1);
	printf("%d\n",str_all_alphabets(c)==1);
	printf("%d\n",str_has_alphabet(a)==1);
	printf("%d\n",str_has_alphabet(b)==1);
	printf("%d\n",str_has_alphabet(c)==1);
	printf("%d\n",str_replace_all(a, 'e', 'q')==1);
	printf("%d\n",str_replace_all(b,'e', 'q')==1);
	printf("%d\n",str_replace_all(c, 'r', 'q')==1);
	printf("%d\n",str_replace_first(a, 'o', 'f')==1);
	printf("%d\n",str_replace_first(b,'o', 'f')==1);
	printf("%d\n",str_replace_first(c, 'o', 'f')==1);
	printf("%d\n",str_replace_last(a, 'l', 'f')==1);
	printf("%d\n",str_replace_last(b, 'o', 'f')==1);
	printf("%d\n",str_replace_last(c, 'd', 'f')==1);
	return 0;
}
/*
	returns 1 if the string s consists entirely of alphabets
*/
int str_all_alphabets(const char s[]){
	size_t i = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(!isalpha((int)s[i])){
			return 0;
		}
	}
	return 1;
}
/*
	returns 1 if the string s contains an alphabet
*/
int str_has_alphabet(const char s[]){
	size_t i =0;
	for(i = 0; s[i] != '\0'; i++){
		if(isalpha((int)s[i])){
			return 1;
		}
	}
	return 0;
}
/*
	replaces all occurences of te character oldc in the string s by the character new c
	returns number of replacements
*/
size_t str_replace_all(char s[], int oldc, int newc){
	size_t i = 0;
	size_t count = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == (char)oldc){
			s[i] =(char)newc;
			count++;
		}
	}
	return count;
}
/*
	replaces only the first ocurrence of oldc in the string with newc
	returns 1 on success
*/
int str_replace_first(char s[], int oldc, int newc){
	size_t i = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == (char)oldc){
			s[i] = (char)newc;
			return 1;
		}
	}
	return 0;
}
/*
	replaces the last ocurrence of oldc in the string s by newc
	returns 1 if a replacement has been made, otherwise returns 0
*/
int str_replace_last(char s[], int oldc, int newc){
	size_t i = 0;
	int index = -1;
	for(i = 0; s[i] != '\0'; i++){
			if(s[i] == (char)oldc){
				index = i;
			}
	}
	
	if(index != -1){
		s[index] = (char)newc;
		return 1;
	}
	return 0;
}
