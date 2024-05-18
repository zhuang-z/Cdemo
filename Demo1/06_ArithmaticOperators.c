#include<stdio.h>

int main() {

	//算数运算符 + - * / % += -= *= /= %=
	//双目运算符 + - * / %   单目运算符 += -= *= /= %=
	//三目运算符 int x = a>b?10:20;

	int a1, b1;
	a1 = 10, b1 = 3;
	printf("%d %d %d %d %d\n", a1 + b1, a1 - b1, a1 * b1, a1 / b1, a1 % b1);
	int c1=10, c2=10, c3=10, c4=10, c5=10;
	c1 += 3, c2 -= 3, c3 *= 3, c4 /= 3, c5 %= 3;
	printf("%d %d %d %d %d\n", c1,c2,c3,c4,c5);

	//多少分钟换算成多少个小时多少分钟 1000分钟

	int d,d1,d2;
	scanf_s("%d",&d); //微软认为scanf不安全添加了scanf_s这个方法
	d1 = d / 60; 
	d2 = d % 60;
	printf("%d分钟是%d小时%d分钟\n", d, d1, d2);


	return 0;
}