#include<stdio.h>

int main() {
	int num;
	scanf_s("%d", &num);

	/*1.�ж�����ż��
	*	��ѧ��������2����ż����������������
		���룺
			% 2 = 0��ż��
			% 2 = 1������
	*/

	if (num % 2 == 0) {
		printf("num��ż��\n");
	}
	else {
		printf("num������\n");
	}


	/*2.���ɼ�������
	*	A:100-90
	*	B:89-80
	*	C:79-70
	*	D:69-60
	*	E:60����
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


	/*3.�ж�һ�����������,����һ�򣬰��겻���İ�������
	* �������꣺year % 400 == 0 
	* ��ͨ���꣺year % 4 == 0 && year % 100 != 0����
	*/

	int year;
	scanf_s("%d", &year);
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		printf("����\n");
	}
	else {
		printf("ƽ��\n");
	}

	return 0;
}