#include<stdio.h>

int main() {
	/*
		1.�������� 
		short 2���ֽ� 
		unsigned short  �޷������� 
		int 4���ֽ�
		unsigned int 
		long  4���ֽ�
		long unsigned
 	*/
	

	short a1 = 1000;
	int a2 = 1000;
	long a3 = 1000;  //���ü�1000L�ı�ʶ�������Զ�������������ת��

	unsigned int a4 = 4294967295;

	int a5 = 123;   //ʮ����
	int a6 = 0123;  //�˽���
	int a7 = 0x123; //ʮ������ 0-9 a b c d e f

	int length1 = sizeof(a1);
	int length2 = sizeof(a2);
	int length3 = sizeof(a3);
	/*
	* %d ʮ���Ƶ�����
	* %u �޷��ŵ�ʮ��������
	* %o �˽��Ƶ�(�з���)����
	* %x ʮ�����Ƶ�(�з���)����
	* ���������û���ض���
	*/
	printf("%d\n", length1);  //������������ռ���ֽ��� \n����
	printf("%d\n", length2);
	printf("%d\n", length3);
	printf("%u\n", a4);
	printf("%d\n", a5); //ʮ�������
	printf("%o\n", a6); //�˽������
	printf("%x\n", a7); //ʮ���������

}