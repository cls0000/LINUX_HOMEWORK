#include"my.h"
void sigfun(int signo){
	switch(signo){
		case 1:
			printf("Catch SIGHUP\n");
			signal(1,SIG_DFL);
			break;
		case 2:
			printf("Catch SIGINT");
		case 3:
			printf("CAtch QUIT");
			break;
	}
}
int main(){
	int i;
	signal(1,sigfun);
	signal(2,sigfun);
	signal(3,sigfun);
	printf("test pid [%d]\n",getpid());
	
	while(1);
	return 0;
}
