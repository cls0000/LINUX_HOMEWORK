#include <stdio.h>
#include <string.h> 
int main(int argc, char *argv[]){
	FILE *fp = NULL;	
	// 读写方式打开，文件不存在则创建	
	fp = fopen("demo3.txt", "w+");	
	if(NULL == fp)
	{	
	printf("open error\n");	
	return 1;	
	}	
	char *str = "hello,demo3\n";	
	fwrite(str, 1, strlen(str), fp);
	// 往文件写内容
	fclose(fp);	
	// 人为关闭文件，就算缓冲区没有填满，内容也会写进文件	
	while(1);	// 程序阻塞在这里 	
	return 0;
}

