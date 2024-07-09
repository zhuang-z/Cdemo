#include<stdio.h>

//void swap(int *a,int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

int * swap(int a, int b) { //做一个变形，交换只交换常量，返回一个一维数组
	int temp = a;
	a = b;
	b = temp;

	int arr[] = {a,b};
	return arr;
}

void sort(int *arr,int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1 -i; j++) {   //arr[j]从arr[0]与arr[1]两两比较，一直比到arr[length]，大的向后冒泡，第二轮最后一个数可以不比，即到arr[length-1]
			if (arr[j]>arr[j+1]) {
				//swap(&arr[j], &arr[j + 1]);  //swap函数是指针，只能传数组该值的地址
				//使用一级指针接收
				int* arr1 = swap(arr[j],arr[j+1]);  //交换arr[j]和arr[j+1]之后分别对他们进行赋值
				arr[j] = arr1[0];
				arr[j+1] = arr1[1];
			}
		}
	}
}

int main() {
	//对数组里面的数进行排序   冒泡或者选择排序均可
	int arr[] = { 100,29,58,79,2,30,17 };
	
	sort(arr, sizeof(arr) / sizeof(int));  //sizeof直接传递会出错，进行传参的时候要传递一个长度值过去

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}