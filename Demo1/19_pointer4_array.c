#include<stdio.h>

int main() {

	//ָ������
	char* str1 = "xiaoyou";
	char* str2 = "goudan";
	char* str3 = "tiechui";

	//��*str1 *str2 *str3�����嵽ָ����������
	//char *ch[3]={str1,str2,str3};
	char *ch[3] = { "xiaoyou","goudan","tiechui"};

	for (int i = 0; i < sizeof(ch) / sizeof(char*); i++) {
		printf("%p\n", ch[i]);
		printf("%s\n", ch[i]);
	}

	//int* a[3] = {11,22,33};    //���ᱨ��
	//printf("%p\n", a);
	//printf("%d\n", *a[1]);     //����ָ���ӡȡ���������ֵ

	int arr1[3] = { 10,20,30 };
	int arr2[3] = { 40,50,60 };
	int arr3[3] = { 70,80,90 };
	int* arr[3] = {arr1,arr2,arr3};
	for (int i = 0; i < 3; i++) {
		printf("%p\n", arr[i]);
		printf("%d\n", *arr[i]);
		/*
		printf("%p\n", arr[i][0]); //��ӡarr1,arr2,arr3�ĵ�һ��Ԫ�صĵ�ַ
		printf("%d\n", *(arr[i]+1)); //��ӡarr1,arr2,arr3�ĵڶ���Ԫ�صĵ�ַ
		*/
	}

	//int* arr[3] = { arr1,arr2,arr3 };  ָ������ʹ��ָ����д�ӡ
	int* p = &arr;
	printf("%p\n", p);  //��ӡ����arr1�ĵ�ַ
	//printf("%d\n", *p);  //�޷���ӡarr1�����ֵ����Ϊarr1Ҳ�Ǹ���ַ����Ҫ�����ٴζ�λ���ܷ���arr1�����ֵ

	//int* p1 = &arr;   int *p1 = arr1;�ܷ���arr1�ĵ�ַ�������Ҫ����arr���arr1�ĵ�ַ����Ҫ�ټ�һ��*��int **p1 =arr;
	int** p1 = &arr;	//arr���arr1,arr2,arr3�ĵ�ַ��*arr�����ҵ�arr1��ֵ,arr2��ֵ,arr3��ֵ
						//*p1�ҵ�arr���ֵ������arr1��arr2��arr3�ĵ�ַ��**p1����arr1��arr2��arr3��ֵ��

	printf("%d\n", **p1); //��ӡarr1�ĵ�1��ֵ��Ҳ����printf("%d\n",p1[0][0]); ���Ǵ�ӡarr�ĵ�1��ֵ������arr1�ĵ�1��ֵ��10
	printf("%d\n", p1[2][1]);//��ӡarr3�ĵ�2��ֵ
	printf("%d\n", **(p1+1)); //��ӡarr2�ĵ�1��ֵ arr�ĵ�ַ��1
	printf("%d\n", *(*(p1+2)+1)); //��ӡarr3�ĵ�2��ֵ arr�ĵ�ַ��2����arr3�ĵ�2��ֵ


	return 0;
}