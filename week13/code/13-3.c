#include"my.h"

static int sig_cnt[NSIG];
static volatile sig_atomic_t get_SIGINT =0;
void handler(int signo){
	if(signo==SIGINT)
		get_SIGINT = 1;
	else
		sig_cnt[signo]++;
} 

int main(int argc,char *argv[]){
	int i=0;
	sigset_t blockall_mask;
	sigset_t empty_mask;
	printf("%s:PID IS%d\n",argv[0],getpid());
	printf("NSIG=%d\n",NSIG);

	for(i=1;i<NSIG;i++){
		if(i==SIGKILL || i==SIGTOP || i==32 || i==33)
			continue;
		if(signal(i,&handler)==SIGERR){
			fprintf(stderr,"signal for signo(%d) falled(%s)\n",i,strerror(errno));	
		}
	}
	if(argc>1){
		int sleep_time = atoi(argv[1]);
		sigfillset(&blockall_mask);
		if(sigprocmask(SIG_SETMASK,&blockall_mask,NULL)==-1){
			fprintf("stderr","setprocmaks to block all signal failed (%s)\n",strerror(errno));
			return -2;
		}
		printf("I WILL SLEEP %d SECOND\n",sleep_time);
		sleep(sleep_time);
		sigemptyset(&empty_mask);
		if(sigprocmask(SIG_SETMASK,&empty_mask,NULL)==-1){
                        fprintf("stderr","setprocmaks to release all signal failed (%s)\n",strerror(errno));
                        return -3;
                }

	}
	while(!get_SIGINT)
		continue;
	printf("%-10s%-10s\n","signo","times");
	printf("............................\n");
	for(i=1;i<NSIG;i++){
		if(sig_cnt[i]!=0)
			printf("%-10d%-10d\n",i,sig_cnt[i]);
	}
}
