#include"my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main()
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];

	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));
	int pfd[2];
	int ret = pipe(pfd);
	if(ret==-1)
	{
		fprintf(stderr,"create pipe error.reason:[%s]\n",strerror(errno));
		return -1;
	}
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"create pipe error.reason:[%s]\n",strerror(errno));
		return -1;
	}
	else if(pid==0)
	{
		close(pfd[0]);
		int loop = 10;
		while(loop++<10)
		{
			ret = write(pfd[1],a,sizeof(a));
			printf("apid = %d write %d bytes to pipe \n",getpid(),getppid());
		}
		exit(0);
	}
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"create pipe error.reason:[%s]\n",strerror(errno));
		return -1;
	}
	else if(pid==0)
	{
		close(pfd[0]);
		int loop = 10;
		while(loop++<10)
		{
			ret = write(pfd[1],a,sizeof(a));
			printf("apid = %d write %d bytes to pipe \n",getpid(),getppid());
		}
		exit(0);
	}
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"create pipe error.reason:[%s]\n",strerror(errno));
		return -1;
	}
	else if(pid==0)
	{
		close(pfd[0]);
		int loop = 10;
		while(loop++<10)
		{
			ret = write(pfd[1],a,sizeof(a));
			printf("apid = %d write %d bytes to pipe \n",getpid(),getppid());
		}
		exit(0);
	}
	close(pfd[1]);
	sleep(1);
	int fd = open("./test.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	char buf[1024];
	int n = 1;
	while(1)
	{
		ret = read(pfd[0],buf,sizeof(buf));
		if(ret ==0)
			break;
		printf("n=%02d pid=%d read %d_bytes_from_pipe_buf[4095]=%c\n",n++,getpid(),ret,buf[1024]);
		write(fd,buf,ret);
	}

	return 0;
}
