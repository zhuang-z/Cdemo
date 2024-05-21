#include<stdio.h>
#include<stdbool.h>

#include "14_function2.h"  //定义的头文件，可以把函数都放进头文件里面，在main.c文件里声明头文件，即可进行调用

//extern void xiaoyou_printf();  //对xiaoyou_printf()进行声明，39行才能调用到函数(49-51)

//函数的返回值，用于下一道工序
//1.如果没有返回值用void定义
//2.函数是相应的函数类型用相应的关键字进行定义 int double char

//int isPrime(int n) {  //判断是不是质数
//	int i;
//	for (i = 2; i <= n / 2; i++) {
//		if (n % i == 0) {
//			/*printf("%d不是质数\n",n);
//			break; //跳出for循环再执行之后的语句 */    
//
//			return false;  //如果不是质数的话，返回一个false，直接中断整个函数，false后面的语句也不会再执行；
//		}
//	}
//
//	/*if (i > n / 2) {
//		printf("%d是质数\n", n);
//	}*/
//	
//	return true;  //如果这个数是质数的话就没进入过if语句，就返回一个true
//}



int main() {

	int a;
	for (a = 300; a < 500; a++) {   //1.判断300-500之间的数是不是质数   2.找出300-500之间的质数
		if (isPrime(a)) {  //调用函数得到返回的值，是true还是false，对这个值进行判断再打印这个数
			printf("%d\n", a);
		};  
	}

	xiaoyou_printf();

	return 0; //main函数的返回值不会再被其他调用，所以就return 0；
}


// 函数在main函数之后，程序按照从上到下执行，如果要在main函数里面能够执行xiaoyou_printf()函数
// 需要在main上面进行函数的声明,或者把函数写在其他.c文件中然后新建一个头文件，头文件对函数进行声明，然后对头文件进行引用，头文件名字可以自定义
// #include "functionY"
// extern void xiaoyou_printf();
//void xiaoyou_printf() {   
//	printf("Hello xiaoyou!");
//}