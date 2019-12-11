#include "my.h"

void *foo(void *arg){
	printf("thread is running! \n");
	return (void *)0;
}

int main(){
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid,NULL,foo,NULL);
	if(ret){
		perror("thread failed!\n");
		exit(1);
	}
	//ret = pthread_join(tid,NULL);
	pthread_detach(tid);
	printf("Mater done!\n");
	sleep(5);
	return 0;
}
