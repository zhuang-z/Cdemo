#include<stdio.h>
#define F(n) 2*n

#define NL '\n' //换行符


int main() {
	// 计算 10+20
	/*
	%d 占位符，占了位置，需要一个值来填充 10+20填充到%d

	10 20常量  int关键字，赋值变量 int a = 10；int b = 20；

	变量命名：
	1.不能以数字开头；
	2.不能以特殊字符开头，_除外；
	3.不能使用关键字(标识符)作为变量；

	*/
	int a, b, c;
	a = 10;
	b = 20;
	c = 30;

	printf("price %d\n", a + b + c);

	//宏定义转换
	printf("%d\n", F(3 + 2)); //F(3 + 2) = 2 * 3 + 2 = 6 + 2 = 8

	printf("You NL"); //NL只会当成普通字符
	printf("You%c", NL); //NL会被替换成换行符
}