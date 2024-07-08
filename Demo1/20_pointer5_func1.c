#include<stdio.h>

//*arr 与 arr[] 等价
void func1(int *arr) {
	*(arr+1) = 100;
}

void func2(char **str) {
	*str = "youzi";  //函数只能传递地址，指向地址之后，要取到该地址(指针)的值，就需要用指针的指针来接收参数，*str就相当于str的值
}

void func3(int *arr) {
	*(arr+1) = 100;
}

void func4(int (*arr)[2]) {  //二维数组要用数组指针来接收参数
	*(*(arr + 1) + 1) = 100;
}

void func5(int **arr) {   //指针数组可以用二级指针接收
	*(*(arr + 1) + 2) = 100;
}

int main() {
	/*
	//数组名和指针变量的异同
	int a[5] = { 1,2,3,4,5 };

	int* p = a;

	//1.a是常量，p是变量
	//2.对a取地址，和对p取地址结果不同
	//a是数组的名字，对a取地址结果为数组指针
	//p是指针变量，对p取地址为指针的指针

	*/

	//指针给函数传值
	int arr1[] = { 1,2,3,4,5 };
	func1(arr1);
	printf("%d\n", arr1[1]);

	//传字符串
	char* str = "xiaoyou";  //存放在常量区，如果要修改的话只能修改变量，只能修改地址
	func2(&str);  //函数只能传递地址，指向地址之后，要取到该地址(指针)的值，就需要用指针的指针来接收参数，*str就相当于str的值
	printf("%s\n", str);

	//传数组
	int arr2[] = { 11,22,33 };
	func3(arr2);
	printf("%d\n", *(arr2+1));

	int arr3[2][2] = { 
		{44,55},
		{66,77}
	};
	func4(arr3);
	printf("%d\n", arr3[1][1]);


	//传指针数组
	int arr4[] = {10,20,30};
	int arr5[] = { 40,50,60 };
	int *arr6[] = { arr4,arr5 };   //指针数组指向arr2和arr3的地址
	printf("%d\n", arr6[1][2]);
	func5(arr6);

	printf("%d\n", arr6[1][2]);

	return 0;
}