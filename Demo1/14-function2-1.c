#include<stdio.h>
#include<stdbool.h>
void xiaoyou_printf() {
	printf("Hello xiaoyou!");
}

int isPrime(int n) {  //判断是不是质数
	int i;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			/*printf("%d不是质数\n",n);
			break; //跳出for循环再执行之后的语句 */

			return false;  //如果不是质数的话，返回一个false，直接中断整个函数，false后面的语句也不会再执行；
		}
	}

	/*if (i > n / 2) {
		printf("%d是质数\n", n);
	}*/

	return true;  //如果这个数是质数的话就没进入过if语句，就返回一个true
}