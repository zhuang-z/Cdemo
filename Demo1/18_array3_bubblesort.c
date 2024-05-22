#include<stdio.h>

int main() {

	int arr[] = { 213,453,3332,46,32,1,576,345,23,98 };  //10个数 0-9
	for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++){   //总共要进行多少次循环
		//数组的值两两比较，大的靠后，下沉；
		//i的下标最大时，a[10]>a[11],但是a[11]是0，所以第一次i<sizeof(arr)/sizeof(int)-1-0(i)，第二次是-1-1(i)，第三次是-1-1-1(i) .. 第i次就是-1-i
		for (int j = 0; j < sizeof(arr) / sizeof(int) - 1 -i; j++) {  
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		//{213 453 46 32 1 576 345 23 98 3332}  第一遍把3332沉底，放到最后面，第二次循环就把576沉底，第二次可以少一次比较
	}



	for (int a = 0; a < sizeof(arr) / sizeof(int); a++) {
		printf("%d ", arr[a]);
	}

	return 0;
}