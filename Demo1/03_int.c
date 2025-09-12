#include<stdio.h>

int main() {
	/*
		1.整形数据 
		short 2个字节 
		unsigned short  无符号整形 
		int 4个字节
		unsigned int 
		long  4个字节
		long unsigned
 	*/
	

	short a1 = 1000;
	int a2 = 1000;
	long a3 = 1000;  //不用加1000L的标识符，会自动进行数据类型转换

	unsigned int a4 = 4294967295;

	int a5 = 123;   //十进制
	int a6 = 0123;  //八进制
	int a7 = 0x123; //十六进制 0-9 a b c d e f

	int length1 = sizeof(a1);
	int length2 = sizeof(a2);
	int length3 = sizeof(a3);
	/*
	* %d 十进制的整形
	* %u 无符号的十进制整形
	* %o 八进制的(有符号)整形
	* %x 十六进制的(有符号)整形
	* 二进制输出没有特定的
	*/
	printf("%d\n", length1);  //计算数据类型占的字节数 \n换行
	printf("%d\n", length2);
	printf("%d\n", length3);
	printf("%u\n", a4);
	printf("%d\n", a5); //十进制输出
	printf("%o\n", a6); //八进制输出
	printf("%x\n", a7); //十六进制输出

}