#include<stdio.h>
#include "16_function3.h"; //调用创建的头文件

/*普通全局变量，定义在函数之上的变量就是普通全局变量，因为代码逻辑复杂起来之后，变量很多
所以分别另建一个.c文件定义全局变量和函数，然后新建头文件进行全局变量和函数的声明，然后在main.c里进行调用
头文件即可；
全局变量在程序的运行过程中一直存在，直到程序结束

例子是function3-1.c 和 function3.h

*/

/*
静态全局变量，只能在当前.c文件中能访问，其他文件.c文件都无法访问
static int mysum;

静态局部变量，在函数内部进行调用，程序结束后程序被销毁，
但是能变量能保存下来，下次调用程序能访问到上一次保存的值

静态函数  在其他.c文件中是无法进行调用的，只能在此C文件中使用
*/




int main() {
	printf("%d\n", mysum);
	printf("main函数里的mysum的地址%p\n",&mysum); //  %p &mysum 打印地址

	sum(10, 20);   //直接调用sum函数，sum函数在function3-1.c中定义的，在function3.h中声明的，头文件进行调用之后直接使用
	printf("sum函数里的mysum的地址%p\n", &mysum); //  %p &mysum 打印地址
	return 0;
}