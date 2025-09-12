#include<stdio.h>
#pragma warning(disable:4996)
int main() {

	/*
	文件操作：
		文件指针用来标识一个文件，打开文件得到文件指针
		fopen方法：(文件路径，文件打开方式：r w a+)
		使用fopen 需要声明#pragma warning(disable:4996)
		文件路径：相对路径和绝对路径 "\\" 要用2个反斜杠
		文件打开方式：
		r ：read 读 没有文件时不会创建文件
		w ：write 写 没有文件时会创建文件，有文件时会把里面的内容清空
		a ：append 追加 没有文件时会创建文件，有文件时不会把里面的内容清空，在后面追加内容
	*/
	FILE* fp;
	FILE* fp1;
	fp = fopen("You.txt", "r"); //fopen 返回 NULL打开失败，否则打开成功

	if (fp == NULL) {
		perror("fopen"); //perror : 提示文件打开失败的原因
		printf("open failed!\n");
	}
	else {
		printf("open successfully!\n");
	}

	int error = fopen_s(&fp1, "You1.txt", "w"); //fopen_s 第一个参数需要传入二级指针，指针取地址符，返回的值是错误值，如果错误值为1，报错即打开失败，如果错误为0，打开成功

	if (error != 0) {
		printf("open failed!\n");   
		return; //打开失败时，即fp为0，文件不存在，不用关闭
	}
	else {
		printf("open successfully!\n");
	}

	int eclose1 = fclose(fp1); //只有fclose方法 关闭 返回error值，返回0，失败为0即关闭成功，返回1，失败为1即关闭失败
	if (eclose1 == 0) {
		printf("close successfully!\n");
	}
	else {
		printf("close failed!\n");
	}

	return 0;
}