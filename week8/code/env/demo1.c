#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[],char *env[])

{

extern char **environ;

int i = 0;
for(;env[i];i++){
printf("%s\n",env[i]);

}
printf("------------------------------------------------------------------------");
for(; environ[i];i++)

{

printf("%s\n",environ[i]);
}
printf("------------------------------------------------------------------------");
printf("%s\n",getenv("PATH"));

return 0;

}
