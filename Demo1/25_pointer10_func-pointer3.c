#include<stdio.h>

//ѹ���ļ�
void compress(char *file_name,void (*p)(int a,int b)) {
	printf("��ʼѹ���ļ�\n");
	p(50, 120);
	printf("�ļ�ѹ������");
}

//�Լ���װһ�������ص�
void file_compress(int a,int b) {
	printf("ѹ������%d %d\n", a, b);
}


int main() {

	//ѹ���ļ�,�ص�����
	compress("xiaoyouzi.png", file_compress);  //compress��������file_name "xiaoyouzi.png",�ص��������ص��ĺ�����Ҫ�Լ���װ

	return 0;
}