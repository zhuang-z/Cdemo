#include<stdio.h>

//1.把数组的值交换封装成一个函数
//2.把排序for循环封装成一个函数

//第一步封装交换数组的值
void swap(int *a,int *b) { //两个形参接收传递的实参的地址 a,b表示地址，*a和*b表示a,b地址的值 
	int temp = *a;
	*a = *b;
	*b = temp;
}


//封装冒泡排序
void bubble(int *arr,int length) {  //如果arr是指针，接收的是数组，int *arr,int arr[]都可以，不越界即可
	for (int i = 0; i < length - 1; i++) {   //总共要进行多少次循环
		//数组的值两两比较，大的靠后，下沉；
		//i的下标最大时，a[10]>a[11],但是a[11]是0，所以第一次i<s1izeof(arr)/sizeof(int)-1-0(i)，第二次是-1-1(i)，第三次是-1-1-1(i) .. 第i次就是-1-i
		for (int j = 0; j < length - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				/*int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;*/
				swap(&arr[j], &arr[j + 1]);//实参传递arr[j]和arr[j+1]的地址到swap中
			}
		}
		//{213 453 46 32 1 576 345 23 98 3332}  第一遍把3332沉底，放到最后面，第二次循环就把576沉底，第二次可以少一次比较
	}
}


int main() {

	int arr[] = { 213,453,3332,46,32,1,576,345,23,98 };  //10个数 0-9
	

	bubble(arr,sizeof(arr)/sizeof(int));  
	/*
	1.传递数组的地址过去，数组的地址是10位，
	会出现一个问题，数组在传递过程中只会传递数组地址的大小，不会传递整个占的字节大小
	如果使用sizeof(arr)的话会直接得到10，所以sizeof(arr)/sizeof(int)的值在函数里面会出异常，
	在实参中直接计算是正常的
	
	2.所以需要在传递实参时，传两个参数，一个是数组的地址，arr，
	另外一个是数组的长度 sizeof(arr)/sizeof(int)
	*/

	for (int a = 0; a < sizeof(arr) / sizeof(int); a++) {
		printf("%d ", arr[a]);
	}

	/*
		printf("%p",arr);
		printf("%p",&arr);
		printf("%p",&arr[0]); //取的数组第0个元素的地址，取下一个元素加4个字节
		printf("%p",&arr[1]);
	*/

	return 0;
}