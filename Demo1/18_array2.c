#include<stdio.h>

int main() {
	
	//列必须指定
	int a[][3] = {  
		{100,99,98},
		{98,90},
		{88,83,70}
	};

	for (int i = 0; i < sizeof(a) / (sizeof(int) * 3); i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", a[i][j]);
		}
	}


	//列必须指定，可以写大一点
	char str[][100] = { "xiaoyou","tiechui","goudan","尘大师" };

	for (int i = 0; i < sizeof(str) / (sizeof(char) * 100); i++) {  //数据的大小/数据类型的字节数/列数 ==行数
		printf("%s\n", str[i]);   //打印字符串
	}
	printf("%c\n", str[1][3]);  //打印字符

	return 0;
}