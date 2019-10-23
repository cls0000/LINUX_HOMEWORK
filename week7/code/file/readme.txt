将输出重定向到文件指令：./demo1->1.txt
(1)demo1.c
/*

那么他的输出应该类似于

write to stdout

printf
*/
(2)demo2.c
/*
而当我们把输出中的换行符去掉时
观察程序在终端中的输出，变成了：

write to stdout

printf

printf

 

可以看到，终端中的输出也出现了两个“printf ”。

 
