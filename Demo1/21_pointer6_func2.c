#include<stdio.h>
typedef int(*youzi)[2];


int * func1() {  //���ص���ָ�룬����ĺ���Ҳ��ָ������
	static int a = 100; //�ᱨ���棺���ؾֲ���������ʱ�����ĵ�ַ: a��Ҫ��static��ɾ�̬�����µ��û�ʹ����һ�ε�ֵ
	             //����Ϊ�������β��ڵ�����֮������٣����ܵ�����һ�ε���ʱ���ص�ָ���Ϊ��Ұָ�롱
	int* p = &a;
	return p;    
}

int* func2() {
	static int arr[] = { 1,2,3,4,5 };
	return arr;
}

int(* func3())[2] { 
	/*��ά����Ҫʹ������ָ�������գ�����д����������ͬ
	int (*func3())[2]{}

	Ҳ����ʹ��typedef����һ���µı�ʾ����
	*/
	static int arr[][2] = {
		{11,22},
		{33,44}
	};
	
	return arr;
}

youzi func4() {
	static int arr[][2] = {
		{11,22},
		{33,44}
	};
	
	return arr;
}

int** func5() {
	int arr1[] = {10,20};
	int arr2[] = {30,40};
	static int *arr[2]; //Ҫ����ô�С
	arr[0] = arr1;     //����дint arr[] = {arr1,arr2};��Ϊÿ��Ҫ��arr��ֵ�����ܱ�֤static����֮ǰ�Ķ���һ����
	arr[1] = arr2;

	return arr;
}

int main() {
	
	//�����ķ���ֵ��ָ��
	//1.���س���ָ��  ��һ��ָ�����
	//2.����һά����  ��һ��ָ�����
	//3.���ض�ά����  ������ָ������β�
	//4.����ָ������  �ö���ָ������β�

	int * p1 = func1();  //���س���ָ��
	printf("%d\n", *p1);

	int* p2 = func2();
	printf("%d\n", *(p2 + 1));

	int(*p3)[2] = func3();  //������ָ�������շ���ֵ
	printf("%d\n", *(*(p3 + 1) + 1));

	int(*p4)[2] = func4();
	printf("%d\n", *(*(p4)+1));

	int** p5 = func5();
	printf("%d\n", *(*(p5)+1));

	return 0;
}