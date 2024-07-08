#include<stdio.h>
typedef int(*youzi)[2];


int * func1() {  //返回的是指针，定义的函数也是指针类型
	static int a = 100; //会报警告：返回局部变量或临时变量的地址: a，要加static变成静态，重新调用会使用上一次的值
	             //是因为函数的形参在调用完之后会销毁，可能导致下一次调用时返回的指针成为“野指针”
	int* p = &a;
	return p;    
}

int* func2() {
	static int arr[] = { 1,2,3,4,5 };
	return arr;
}

int(* func3())[2] { 
	/*二维数组要使用数组指针来接收，但是写法会有所不同
	int (*func3())[2]{}

	也可以使用typedef定义一个新的表示方法
	*/
	static int arr[][2] = {
		{11,22},
		{33,44}
	};
	
	return arr;
}

youzi func4() {
	static int arr[][2] = {
		{11,22},
		{33,44}
	};
	
	return arr;
}

int** func5() {
	int arr1[] = {10,20};
	int arr2[] = {30,40};
	static int *arr[2]; //要定义好大小
	arr[0] = arr1;     //不能写int arr[] = {arr1,arr2};因为每次要对arr赋值，不能保证static调用之前的都是一样的
	arr[1] = arr2;

	return arr;
}

int main() {
	
	//函数的返回值是指针
	//1.返回常量指针  用一级指针接收
	//2.返回一维数组  用一级指针接收
	//3.返回二维数组  用数组指针接收形参
	//4.返回指针数组  用二级指针接收形参

	int * p1 = func1();  //返回常量指针
	printf("%d\n", *p1);

	int* p2 = func2();
	printf("%d\n", *(p2 + 1));

	int(*p3)[2] = func3();  //用数组指针来接收返回值
	printf("%d\n", *(*(p3 + 1) + 1));

	int(*p4)[2] = func4();
	printf("%d\n", *(*(p4)+1));

	int** p5 = func5();
	printf("%d\n", *(*(p5)+1));

	return 0;
}