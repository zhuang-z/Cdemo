#include<stdio.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int main() {

	//����ָ������
	//����ָ���ܹ����ʺ���������ָ�������ܹ����ʶ������
	//����ָ�룺int (*p)(int,int) = max;  max�Ƕ���ĺ���

	int (*p[])(int,int) = {add,sub,min,max};

	int res1 = (*p)(1, 2);  //Ҫ��*p����������������֤��ִ��
	int res2 = p[1](1, 2);
	int res3 = (*(p + 2))(1, 2);
	int res4 = (*p[3])(1, 2);

	printf("%d\n", res1);
	printf("%d\n", res2);
	printf("%d\n", res3);
	printf("%d\n", res4);


	return 0;
}