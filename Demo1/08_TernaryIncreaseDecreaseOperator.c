#include<stdio.h>

int main() {

	int sum = 250;
	/*
	if(sum > 200){
		sum = sum*0.7;
	}
	*/

	//��Ŀ�������
	sum = sum > 200 ? sum * 0.7 : sum;
	printf("%d\n", sum);

	//��������� �� �Ѷ��ź����ֵ��ֵ��ǰ��
	int a = 1;
	a = (a += 2, a * a);
	printf("%d\n", a);



	//�����Լ������ b++ ++b

	int b = 10;
	/*int b1 = b++;
	int b2 = ++b;
	printf("%d %d\n", b1,b2);*/

	int c = 10 + b++; // ++�ں��ȸ�ֵ����b+b��Ȼ��b������
	int d = 10 + ++b; // ++��Ǯ��b���������ٸ�ֵ����b+b
	printf("%d %d", c, d);


	return 0;
}