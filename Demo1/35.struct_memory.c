#include<stdio.h>

/*
	1���ڴ����ԭ��1�����ݻ������͵����ռ�ÿռ������ڴ棬����intռ4���ֽڣ�charռ��1���ֽڣ�����4���ֽڵĲ��������ڴ�ռ䣻
	2���ڴ����ԭ��2��������ֽ����͵Ĵ�С�ı������洢δʹ�õ�����ռ䣬����charռ1���ֽڣ�shortռ2���ֽڣ�intռ4���ֽڣ���������һ��ռ��8���ֽڣ�
					��Ϊ����int����4���ֽ�(0,1,2,3)��charռ1����short���2�ı�����ʼռ�ÿռ䣬ռ��2,3��int��������4���ֽ������洢������һ��8���ֽڣ�
	3������ݶ����˳������ڴ�ռ����룬���綨�� char short int��ռ8����
	���� char int short ռ12������Ϊint�治��charռ�õ��Ǹ��ռ��ˣ���Ҫ�������룬shortҲ����ˣ�
	4�����������Ŀռ䣬Ҳ�������������������ռ���д洢��
		��:char[10],int a; ����int����4��������char��0-8ռ��8���ֽڣ�9��10Ҳ��Ҫ����4���ֽ����洢������һ��16���ֽ�
*/

struct stu1 {
	char a;
	short b;
	int c;
};

struct stu2 {
	char a;
	int c;
	short b;
};

struct stu3 {
	char a[10];
	int b;
};

int main() {

	struct stu1 student1;
	struct stu2 student2;
	struct stu3 student3;

	printf("%lld\n", sizeof(student1));  //8
	printf("%lld\n", sizeof(student2));  //12
	printf("%lld\n", sizeof(student3));  //16

	return 0;
}