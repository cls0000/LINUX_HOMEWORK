#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){	
	 FILE *fp = NULL;	
	 // 读写方式打开，文件不存在则创建
	 fp = fopen("demo4.txt", "w+");
	 if(NULL == fp)	{	
		 printf("open error\n");	
		 return 1;
	 }	
	 char *str = "hello demo4\n";
	 fwrite(str, 1, strlen(str), fp);
	 // 往文件写内容	
	 return 0;	
	 // 程序正常结束，就算缓冲区没有填满，没有关闭文件，内容也会写进文件。
 }

