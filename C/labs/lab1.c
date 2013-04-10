#include <stdio.h>
#define		check(expr) printf("%s... %s\n", (expr)? "Passed":"failed", #expr);


int array_max(const int a[], size_t n);
size_t array_index_of_first_max(const int a[], size_t n);
size_t array_index_of_last_max(const int a[], size_t n);
int array_equal(const int a[], const int b[], size_t n);

int main(void){

	int a[] = {2,5,8,3,1};
	int b[] = {2,5,8,3,1};
	int c[] = {2,6,7,8,2};
	int d[] = {4,5,4,6,3};
	size_t n = 5;
	
	check(array_max(a,n) == 8);
	printf("%d \n", array_max(a,n) == 8);
	printf("%d \n", array_index_of_first_max(a, n) == 2);
	printf("%d \n",array_index_of_last_max(a,n) == 2);
	printf("%d \n",array_equal(a, b,  n) == 1);
	
	printf("%d \n", array_max(b,n) == 8);
	printf("%d \n", array_index_of_first_max(b, n) == 2);
	printf("%d \n",array_index_of_last_max(b,n) == 2);
	printf("%d \n",array_equal(a, b,  n) == 1);
	
	printf("%d \n", array_max(c,n) == 8);
	printf("%d \n", array_index_of_first_max(c, n) == 3);
	printf("%d \n",array_index_of_last_max(c,n) == 3);
	printf("%d \n",array_equal(c, d,  n) == 0);
	
	
	return 0;
}

int array_max(const int a[], size_t n){
	int max = a[0];
	size_t i = 0;
	for(i = 0 ; i < n ; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}
size_t array_index_of_first_max(const int a[], size_t n){
	int max = a[0];
	size_t index = 0;
	size_t i = 0;
	for(i = 0 ; i < n ; i++){
		if(a[i] > max){
			max = a[i];
			index = i;
		}
	}
	return index;
}
size_t array_index_of_last_max(const int a[], size_t n){
	int max = a[0];
	size_t index = 0;
	size_t i = 0;
	for(i = 0 ; i < n ; i++){
		if(a[i] >= max){
			max = a[i];
			index = i;
		}
	}
	return index;
}
int array_equal(const int a[], const int b[], size_t n){
	size_t i = 0;
	for(i = 0 ; i < n ; i++){
		if(a[i] != b[i]){
			return 0;
		}
	}
	return 1;
}