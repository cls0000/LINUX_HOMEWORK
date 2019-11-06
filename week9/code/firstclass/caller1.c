#include"my.h"
int main(){
	int ret;
	printf("caller1:pid = %d,ppid = %d",getpid(),getppid());
	ret = system("./test1 123 445 hello world");
	printf("After calling! ret=%d\n",ret);
	sleep(5);
	return 0;
}
