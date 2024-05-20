/*在function3-1.c文件里面 定义全局变量，定义函数*/
#include<stdio.h>
#include "function3.h" //引用头文件，里面有变量和函数的声明

void sum(int x, int y) {
	mysum = x + y;
	printf("%d\n", mysum);
}