#include<stdio.h>

int main() {

	//1.1-100�� �׳�
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


	//2.1000-2000�����꣬��������������ݼ������,��������8��Ϊһ�д�ӡ
	int a, b, count=0;
	do {
		printf("������XX�굽XX��,ǰ������С�ں������ݣ�\n");
		scanf_s("%d %d", &a, &b);
	} while (a >= b);
	for (int c = a; c <= b; c++) {
		if (c % 400 == 0 || c % 4 == 0 && c % 100 != 0) {
			printf("%d ", c);  //��������꣬��ӡ��count����+1��count�ж�����˼�������8ȡ����������8�ͼӻ��з�
			count++;
			if (count % 8 ==0) {
				printf("\n");
			}
		}
	}

	return 0;
}