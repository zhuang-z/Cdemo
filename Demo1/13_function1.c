#include<stdio.h>

//函数的定义 函数名(){}

multiplication(int n) {//打印9*9乘法表 , n是形式参数，用于接收函数调用的实际参数的值，23,24,25行函数的调用
	//函数内部的变量外部无法访问
	
	for (int i = 1; i <= n; i++) {  //定义n之后，i要相应的小于等于n
		for (int j = 1; j <= i; j++) {  //j<=i -> 1<=1;i+1=2,1<=2,2<=2;
			printf("%d*%d=%d ", j, i, i * j);
		}
		printf("\n");
	}
}

add(int x, int y, int z) {  //参数也可以是多个，实际参数对应写几个，形式参数都能够对应接收到
	int sum = 0;
	sum = x + y + z;
	printf("%d\n", sum);
}


int main() {

	multiplication(8);   //函数的调用

	//需求改成 打印3遍乘法表，第一个打印6*6，第二个打印3*3，第三个打印9*9，要对函数传参(传参数给函数)

	multiplication(6);  //6,3,9都是实参，实际参数，那么函数要有相对应的形式参数进行接受，能够接受到实际参数的值，要定义参数；
	multiplication(3);
	multiplication(9);


	add(10, 20, 30); //调用add
	return 0;
}