#include<stdio.h>

int main() {

	int arr[] = { 213,453,3332,46,32,1,576,345,23,98 };

	//选择排序，先假定第一个索引的值最小，然后跟后面的值依次进行比较，如果后面值小，就交换索引
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {  //总共要进行多少次循环
		int index = i;   //index从i开始
		//第一次循环从arr[0]开始，第二次循环从arr[1]开始 。。。 从arr[i]开始
		for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
			if (arr[j] < arr[index]) {  //当arr[j]的值比arr[index]的值小的时候，交换索引值
				index = j;
			}
		}
		//第一次循环交换arr[0]和arr[index]的值，第二次循环交换arr[1]和arr[index]的值。。。
		if (index != i) {  //当index的值等于i时就无需交换
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}

	}


	for (int a = 0; a < sizeof(arr) / sizeof(int); a++) {
		printf("%d ", arr[a]);
	}



	return 0;
}