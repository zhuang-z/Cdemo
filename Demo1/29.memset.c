#include<stdio.h>
#include<stdlib.h>

int main() {

	//memset:(�ַ�����,��ʼ����ֵ,���õĴ�С)��һ���ڴ��п��԰����ݿ�������

	char* p1 = (char*)malloc(100);  //malloc�����ʼ��ֵ
	char* p2 = (char*)calloc(25, 4); //calloc��ʼ��ֵ��0
	if (!p1) return;
	if (!p2) return;
	memset(p1, 2, 100);
	memset(p2, -1, 100);
	for (int i = 0; i < 100; i++) {
		printf("%d\n", p1[i]);
	}
	for (int i = 0; i < 100; i++) {
		printf("%d\n", p2[i]);
	}

	char p3[] = "xiaoyouzi";
	memset(p3, 1, 9);
	for (int i = 0; i < 9; i++) {
		printf("%d\n", p3[i]);
	}

	int* p4 = (int*)malloc(100); //intռ4���ֽ�
	if (!p4) return;
	memset(p4, -1, 100); //��ʼ��ֻ����0����-1
	for (int i = 0; i < 100/sizeof(int); i++) {  //��СҪ����sizeof(int)
		printf("%d\n", p4[i]);
	}


	return 0;
}