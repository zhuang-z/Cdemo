#include<stdio.h>
#include<math.h>

int main() {
	//�� 1^2 + 2^3 + 3^4 + 4^5 + 5^6 ��ֵ
	double a = 1, b = 2, c = 3, d = 4, e = 5;
	printf("%.0lf\n", (pow(a, b) + pow(b, c) + pow(c, d) + pow(d, e))); //pow������math.h�еĺ���������ֵΪdouble����


	//�ằ���Ĺ���
	//���̵ĵ� 1 ��� 1 ������ 2 ��� 2 ����������� 4 �����Ժ�ÿһ�񶼱�ǰһ������һ�������˷������� 64 ��
	int i;
	unsigned long long int sum = 0;

	for (i = 0; i < 64; i++) {
		unsigned long long int temp = pow(2, i);
		sum = sum + temp;
	}
	unsigned long long int weight = sum / 25000;

	printf("�ằ��Ӧ�ø��������%llu������\n", sum);
	printf("Լ��%.0llu����\n", weight);

	return 0;
}