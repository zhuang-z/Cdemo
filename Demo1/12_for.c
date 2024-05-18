#include<stdio.h>

int main() {

	//1.1-100和 阶乘
	int sum1 = 0;
	int sum2 = 1;
	for (int i = 1; i <= 100; i++) {
		sum1 += i;
	}
	printf("%d\n", sum1);

	int j;
	scanf_s("%d", &j);
	for (j; j >= 1; j--) {
		sum2 *= j;
	}
	printf("%d\n", sum2);


	//2.1000-2000的闰年，或者输入两个年份间的闰年,输出结果以8个为一行打印
	int a, b, count=0;
	do {
		printf("请输入XX年到XX年,前面的年份小于后面的年份：\n");
		scanf_s("%d %d", &a, &b);
	} while (a >= b);
	for (int c = a; c <= b; c++) {
		if (c % 400 == 0 || c % 4 == 0 && c % 100 != 0) {
			printf("%d ", c);  //如果是闰年，打印，count计数+1，count判断输出了几个，对8取余数，整除8就加换行符
			count++;
			if (count % 8 ==0) {
				printf("\n");
			}
		}
	}

	return 0;
}