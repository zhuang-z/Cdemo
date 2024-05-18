#include<stdio.h>

int main() {
	int num;
	scanf_s("%d", &num);

	/*1.判断奇数偶数
	*	数学：能整除2的是偶数，否则是奇数；
		代码：
			% 2 = 0，偶数
			% 2 = 1，奇数
	*/

	if (num % 2 == 0) {
		printf("num是偶数\n");
	}
	else {
		printf("num是奇数\n");
	}


	/*2.按成绩分区间
	*	A:100-90
	*	B:89-80
	*	C:79-70
	*	D:69-60
	*	E:60以下
	*/
	double score;
	scanf_s("%lf", &score);
	if (score <= 100 && score >= 90) {
		printf("A\n");
	}
	else if (score < 90 && score >= 80) {
		printf("B\n");
	}
	else if (score < 80 && score >= 70) {
		printf("C\n");
	}
	else if (score < 70 && score >= 60) {
		printf("D\n");
	}
	else{
		printf("E\n");
	}


	/*3.判断一个年份是闰年,四年一闰，百年不闰，四百年再闰；
	* 世纪闰年：year % 400 == 0 
	* 普通闰年：year % 4 == 0 && year % 100 != 0；；
	*/

	int year;
	scanf_s("%d", &year);
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		printf("闰年\n");
	}
	else {
		printf("平年\n");
	}

	return 0;
}