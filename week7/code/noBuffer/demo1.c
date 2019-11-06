#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

	char *str = "hello demo1";
	//有没有\n，缓冲区有没有填满，都没关系
	write(1,str,strlen(str));//往标准输出写内容
	while(1);
	return 0;

}



