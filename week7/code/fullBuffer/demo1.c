#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
        FILE *fp = NULL;
        // 读写方式打开，文件不存在则创建
        fp = fopen("demo1.txt", "w+");
        if(NULL == fp)  {
        printf("open error\n");
        return 1;

        }
        char *str = "hello demo1\n";

        
                // 缓冲区大小不确定，i的大小只是一个调试值
        fwrite(str, 1, strlen(str), fp);
        // 往文件写内容
        
        while(1);
        // 程序阻塞在这里
        return 0;
}
