#include<stdio.h>

int main() {

	int a[] = { 1,2,3,4,5 };

	char b[] = "xiaoyou";

	char c[] = { 'x','i','a','o','y','o','u','\0' };  //���鶼��'\0'�����������������ĳ��ȱ��ַ�����С�Ļ�����������쳣

	for (int i = 0; i < 5; i++) {   //ѭ��������ӡ����
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("%s", b);   // ��ӡ�ַ���

	printf("\n");

	for (int i = 0; i < sizeof(c)/sizeof(char); i++) {   // sizeof(c)/sizeof(char)  == ���ݳ���/�������͵ĳ��� = ����
		printf("%c", b[i]);
	}
	printf("\n");

	return 0;
}