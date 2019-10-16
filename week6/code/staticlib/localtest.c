#include<stdio.h>
#include"staticlib.h"
void initarray(int *a,int n);
void showarray(int *a,int n);
 int main(){
     	int a[5];
	initarray(a,5);
	printf("max = %4d\n",max(a,5));
	printf("sum = %4d\n",sum(a,5));
 	showarray(a,5);
}

