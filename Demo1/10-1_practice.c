#include<stdio.h>
#include<stdbool.h>

// 
// �������㣺����ʽ�� + - * / ������
int main() {
	printf("������ʽ�� : ");
	float a, b;
	float result = 0;
	char c;
	// ������Ϊ %c ָ����������С
	scanf_s("%f %c %f", &a, &c, 1, &b); // ���ַ���ص���Ҫȷ����������С������char�Ĵ�С
	bool invaild = false;
	
	switch (c) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b != 0) {
			result = a / b;
			break;
		}
		else {
			invaild = true;
			break;
		}
	}
	if (invaild) {
		printf("��������Ϊ��");
	}
	else {
		printf("����� : %.2f\n", result);
	}

	return 0;
}