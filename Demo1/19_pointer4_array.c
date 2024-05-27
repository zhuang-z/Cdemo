#include<stdio.h>

int main() {

	//指针数组
	char* str1 = "xiaoyou";
	char* str2 = "goudan";
	char* str3 = "tiechui";

	//把*str1 *str2 *str3都定义到指针数组里来
	//char *ch[3]={str1,str2,str3};
	char *ch[3] = { "xiaoyou","goudan","tiechui"};

	for (int i = 0; i < sizeof(ch) / sizeof(char*); i++) {
		printf("%p\n", ch[i]);
		printf("%s\n", ch[i]);
	}

	//int* a[3] = {11,22,33};    //不会报错
	//printf("%p\n", a);
	//printf("%d\n", *a[1]);     //但是指针打印取不到里面的值

	int arr1[3] = { 10,20,30 };
	int arr2[3] = { 40,50,60 };
	int arr3[3] = { 70,80,90 };
	int* arr[3] = {arr1,arr2,arr3};
	for (int i = 0; i < 3; i++) {
		printf("%p\n", arr[i]);
		printf("%d\n", *arr[i]);
		/*
		printf("%p\n", arr[i][0]); //打印arr1,arr2,arr3的第一个元素的地址
		printf("%d\n", *(arr[i]+1)); //打印arr1,arr2,arr3的第二个元素的地址
		*/
	}

	//int* arr[3] = { arr1,arr2,arr3 };  指针数组使用指针进行打印
	int* p = &arr;
	printf("%p\n", p);  //打印的是arr1的地址
	//printf("%d\n", *p);  //无法打印arr1里面的值，因为arr1也是个地址，需要进行再次定位才能访问arr1里面的值

	//int* p1 = &arr;   int *p1 = arr1;能访问arr1的地址，如果需要访问arr里的arr1的地址，需要再加一个*，int **p1 =arr;
	int** p1 = &arr;	//arr存放arr1,arr2,arr3的地址，*arr就能找到arr1的值,arr2的值,arr3的值
						//*p1找到arr存的值，就是arr1，arr2，arr3的地址，**p1就是arr1，arr2，arr3的值，

	printf("%d\n", **p1); //打印arr1的第1个值，也可以printf("%d\n",p1[0][0]); 就是打印arr的第1个值，就是arr1的第1个值，10
	printf("%d\n", p1[2][1]);//打印arr3的第2个值
	printf("%d\n", **(p1+1)); //打印arr2的第1个值 arr的地址加1
	printf("%d\n", *(*(p1+2)+1)); //打印arr3的第2个值 arr的地址加2，是arr3的第2个值


	return 0;
}