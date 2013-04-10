#include <stdio.h>
#include <string.h>
#define LINESIZE 1024

int is_permutation(unsigned long n1, unsigned long n2);
int is_staggering(unsigned long n);
int is_permutation_nostring(unsigned long n1, unsigned long n2);

int main(void){
	int n = 0, m = 0, f = 0;
	int i = 0;
	unsigned long number1 = 4778, number2 = 8477;
	n = is_permutation(number1,number2);
	for(i = 100; i < 1000000 ; i++){
		if(is_staggering(i) == 0){
			m++;
		}
	}
	f = is_permutation_nostring(number1,number2);
	printf("%d\n%d\n%d\n",n,m,f);
	return 0;
}
int is_permutation(unsigned long n1, unsigned long n2){
	int count[] = {0,0,0,0,0,0,0,0,0,0,0};
	size_t i = 0;
	int m = 0;
	char num1[LINESIZE],num2[LINESIZE];
	sprintf(num1,"%lu",n1);
	sprintf(num2,"%lu",n2);
	for(i = 0; num1[i] != '\0' ; i++){
		m = num1[i] - '0';
		count[m]++;
	}
	for(i = 0; num1[i] != '\0'; i++){
		m = num2[i] - '0';
		count[m]--;
	}
	for(i = 0; count[i] != '\0'; i++){
		if(count[i] != 0){
			return 0;
		}
	}
	return 1;
}
int is_permutation_nostring(unsigned long n1, unsigned long n2){
	size_t i = 0;
	int m = 0,n = 0;
	int count[] = {0,0,0,0,0,0,0,0,0,0,0};
	do{
		m = n1 % 10;
		count[m]++;
		m /= 10;
		
	}while(m!=0);
	do{
		n = n2 % 10;
		count[n]--;
		n/=10;
	}while(n!=0);
	for(i = 0; count[i] != '\0'; i++){
		if(count[i] != 0){
			return 0;
		}
	}
	return 1;
}
int is_staggering(unsigned long n){
	size_t i = 0, less = 0, increase = 0;
	char num[LINESIZE];
	int prev = -1;
	sprintf(num,"%lu",n);
	for(i = 1; num[i] != '\0'; i++){
		if(num[i] > num[i-1]){
			increase=1;
		}
		if(num[i] < num[i-1]){
			less=1;
		}
	}
	return increase && less; 
		
}