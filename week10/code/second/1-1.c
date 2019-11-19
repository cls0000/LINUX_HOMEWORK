#include"my.h"
static int __attribute__((constructor)) before_main()
{
	printf("--------running before main!-----------\n");
}
static int __attribute__((destructor)) after_main()
{
	printf("--------running after main!------------\n");
}
void callback1(void)
{
	printf("-------callback1------\n");
}
void callback2(void)
{
	printf("-------callback2------\n");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	char buf[]={"fputs use full buffer!"};
	FILE *fp;
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs!\n");
		return -1;
	}
	printf("----------running in main!--------\n");
	printf("printf use line buffer");
	_exit(0);
}













