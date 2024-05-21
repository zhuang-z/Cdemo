#include<stdio.h>

int main() {

	int a[] = { 1,2,3,4,5 };

	char b[] = "xiaoyou";

	char c[] = { 'x','i','a','o','y','o','u','\0' };  //数组都以'\0'结束，如果定义数组的长度比字符长度小的话，输出会有异常

	for (int i = 0; i < 5; i++) {   //循环遍历打印数组
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("%s", b);   // 打印字符串

	printf("\n");

	for (int i = 0; i < sizeof(c)/sizeof(char); i++) {   // sizeof(c)/sizeof(char)  == 数据长度/数据类型的长度 = 长度
		printf("%c", b[i]);
	}
	printf("\n");

	return 0;
}