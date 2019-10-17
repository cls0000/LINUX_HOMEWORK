动态库链接的第一种方法：程序动态链接：gcc dytestremote.c -o dytestremote ../dynamiclib/libdylib.so -I../dynamiclib/
动态库链接的第二种方法：程序在运行期间导入函数：
gcc -rdynamic -o rttest dytestrt.c -ldl -I../dynamiclib/
如果你的程序中使用dlopen、dlsym、dlclose、dlerror 显示加载动态库，需要设置链接选项 -ldl
