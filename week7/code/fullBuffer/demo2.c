#include <stdio.h>
#include <string.h> 
int main(int argc, char *argv[]){
	FILE *fp = NULL;	
	// 读写方式打开，文件不存在则创建	
	fp = fopen("demo2.txt", "w+");
	if(NULL == fp)	{
	printf("open error\n");		

	return 1;
	}
	char *str = "hello demo2\n";	

	int i = 0;
	while(i <= 512){	// 缓冲区大小不确定，i的大小只是一个调试值	
	fwrite(str, 1, strlen(str), fp);
	// 往文件写内容		
	i++;	}
	while(1);
	// 程序阻塞在这里 
	return 0;
}

