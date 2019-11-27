#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<wait.h>
#include<time.h>
#include<signal.h>
#include<fcntl.h>
#include<string.h>

void sighandler(int);
