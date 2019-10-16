#include<stdio.h>
void showarray(int *a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
    printf("%4d ：%4d\n",i,a[i]);
}
void initarray(int *a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
  a[i]=rand()%100;
   
}
