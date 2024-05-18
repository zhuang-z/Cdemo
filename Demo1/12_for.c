#include<stdio.h>
#include<stdbool.h> //bool类型的库

int main() {

	//break  直接打断整个循环，跳出整个循环
	//continue 循环10次，第5次条件成立时遇到continue，不执行此次循环的逻辑代码，直接进行第六次循环判断

	////1.1-100和 阶乘
	//int sum1 = 0;
	//int sum2 = 1;
	//for (int i = 1; i <= 100; i++) {
	//	sum1 += i;
	//}
	//printf("%d\n", sum1);

	//int j;
	//scanf_s("%d", &j);
	//for (j; j >= 1; j--) {
	//	sum2 *= j;
	//}
	//printf("%d\n", sum2);


	////2.1000-2000的闰年，或者输入两个年份间的闰年,输出结果以8个为一行打印
	//int a, b, count=0;
	//do {
	//	printf("请输入XX年到XX年,前面的年份小于后面的年份：\n");
	//	scanf_s("%d %d", &a, &b);
	//} while (a >= b);
	//for (int c = a; c <= b; c++) {
	//	if (c % 400 == 0 || c % 4 == 0 && c % 100 != 0) {
	//		printf("%d ", c);  //如果是闰年，打印，count计数+1，count判断输出了几个，对8取余数，整除8就加换行符
	//		count++;
	//		if (count % 8 ==0) {
	//			printf("\n");
	//		}
	//	}
	//}

	//break  直接打断整个循环，跳出整个循环
	//continue 循环10次，第5次条件成立时遇到continue，不执行此次循环的逻辑代码，直接进行第六次循环判断

	//3.看这个数是不是质数
	int a;
	bool isPrime = true;  //头文件增加#include<stdbool.h> //bool类型的库
	scanf_s("%d", &a);
	//for (int i = 2; i <=a/2; i++) {  // 一个数是不是质数，除这个数本身和1以外，没有数能被整除，当i递增时，超过这个数本身的一半的时候，就不会再有数能被这个数整除了，所以i<=a/2
	//	if (a % i == 0) {
	//		isPrime = false;
	//		break;  //当有数能被整除之后，直接break，跳出循环，不再执行后面的循环，节省时间
	//	}
	//}
	//if (isPrime) {  //isPrime的值是1的话，证明if的条件不成立，没有数能被整除，证明是质数
	//	printf("%d是质数\n",a);
	//}
	//else {
	//	printf("%d不是质数\n",a);
	//}
	
	int i;
	for (i = 2; i <=a/2; i++) {  // 一个数是不是质数，除这个数本身和1以外，没有数能被整除，当i递增时，超过这个数本身的一半的时候，就不会再有数能被这个数整除了，所以i<=a/2
		if (a % i == 0) {
			break;
		}
	}
	if(i<=a/2){   //当i>a/2的时候，证明没有数能被a整除，所以能被整除时i肯定<=a/2,这个时候的i要定义在for的外面
		printf("%d不是质数\n",a);
	}
	else{
		printf("%d是质数\n",a);
	}
	


	//4.打印9X9乘法表,先打印9行9列的*表，再打印三角，第一行打印1个，第二行打印2个。。。,最后更换成数字等式
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {  //j<=i -> 1<=1;i+1=2,1<=2,2<=2;
			printf("%d*%d=%d ",j,i,i*j);
		}
		printf("\n");
	}


	return 0;
}