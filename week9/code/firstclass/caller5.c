#include"my.h"
int main(){
	char *arg[] = {"./test1","123","hello","world",NULL};
	printf("caller3 pid = %d,ppid = %d\n",getpid(),getppid());
	execlp("test1","./test1","123","hello","world",NULL);
//	execv("home/liaozhiwen/gitspace/week9/code/firstclass/test1",arg);
	printf("execl after calling!\n");
	return 0;
}
