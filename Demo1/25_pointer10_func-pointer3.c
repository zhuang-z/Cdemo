#include<stdio.h>

//压缩文件
void compress(char *file_name,void (*p)(int a,int b)) {
	printf("开始压缩文件\n");
	p(50, 120);
	printf("文件压缩结束");
}

//自己封装一个函数回调
void file_compress(int a,int b) {
	printf("压缩进度%d %d\n", a, b);
}


int main() {

	//压缩文件,回调函数
	compress("xiaoyouzi.png", file_compress);  //compress函数传入file_name "xiaoyouzi.png",回调函数，回调的函数需要自己封装

	return 0;
}