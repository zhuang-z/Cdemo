#include<stdio.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int main() {

	//函数指针数组
	//函数指针能够访问函数，函数指针数组能够访问多个函数
	//函数指针：int (*p)(int,int) = max;  max是定义的函数

	int (*p[])(int,int) = {add,sub,min,max};

	int res1 = (*p)(1, 2);  //要把*p用括号括起来，保证能执行
	int res2 = p[1](1, 2);
	int res3 = (*(p + 2))(1, 2);
	int res4 = (*p[3])(1, 2);

	printf("%d\n", res1);
	printf("%d\n", res2);
	printf("%d\n", res3);
	printf("%d\n", res4);


	return 0;
}