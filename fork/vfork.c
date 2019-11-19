 #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
#include <unistd.h>
  #include <fcntl.h>
  #include <sys/types.h>
  
  int main(int argc,char *argv[])
  {
         pid_t pid;
         int fd;
         int i=1;
         int status;
         char *ch1="hello";
         char *ch2="world";
         char *ch3="IN";
         if((fd=open("test.txt",O_RDWR|O_CREAT,0644))==-1)
         {
                 perror("parent open");
                 exit(EXIT_FAILURE);
                 }
         if(write(fd,ch1,strlen(ch1))==-1)
         {
                 perror("parent write");
                 exit(EXIT_FAILURE);
                 }
         if((pid=fork())==-1)
         {
                 perror("fork");                 exit(EXIT_FAILURE);
                 }
         else if(pid==0)
         {
                 i=2;
                 printf("in chile\n");
                 printf("i=%d\n",i);
                 if(write(fd,ch2,strlen(ch2)));
                 perror("chile write");
                 return 0;
                 }         else
         {
                 sleep(1);//等待子进程先执行
                 printf("in parent\n");
                 printf("i=%d\n",i);
                 if(write(fd,ch3,strlen(ch3)));
                 perror("parent write");
                wait(&status);//等待子进程结束
                 return 0;
                 }
         }
