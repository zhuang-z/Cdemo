#include<stdio.h>

//void swap(int *a,int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

int * swap1(int a, int b) { //��һ�����Σ�����ֻ��������������һ��һά����
	int temp = a;
	a = b;
	b = temp;

	int arr[] = {a,b};
	return arr;
}

int* swap2(int a, int b) { //��һ�����Σ�����ֻ��������������һ��һά����
	int temp = a;
	a = b;
	b = temp;

	int arr[] = { a,b };
	return arr;
}

void bubblesort(int *arr,int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1 -i; j++) {   //arr[j]��arr[0]��arr[1]�����Ƚϣ�һֱ�ȵ�arr[length]��������ð�ݣ��ڶ������һ�������Բ��ȣ�����arr[length-1]
			if (arr[j]>arr[j+1]) {
				//swap(&arr[j], &arr[j + 1]);  //swap������ָ�룬ֻ�ܴ������ֵ�ĵ�ַ
				//ʹ��һ��ָ�����
				int* arr1 = swap1(arr[j],arr[j+1]);  //����arr[j]��arr[j+1]֮��ֱ�����ǽ��и�ֵ
				arr[j] = arr1[0];
				arr[j+1] = arr1[1];
			}
		}
	}
}

void selectionsort(int* arr, int length) {  
	for (int i = 0; i < length; i++) {
		int index = i;
		for (int j = i; j < length; j++) {   //�ٶ���һ����С��j��i��ʼ��arr[j]��arr[index]�Ƚϣ�arr[j]��arr[index]С,index��ֵ��j������
			if (arr[j] < arr[index]) {
				//swap(&arr[j], &arr[j + 1]);  //swap������ָ�룬ֻ�ܴ������ֵ�ĵ�ַ
				index = j;
			}
		}

		if (index != i) {
			int *arr2 = swap2(arr[index], arr[i]);
			arr[index] = arr2[0];
			arr[i] = arr2[1];
		}

	}

}


int main() {
	//���������������������   ð�ݻ���ѡ���������
	int arr[] = { 100,29,58,79,2,30,17 };
	
	bubblesort(arr, sizeof(arr) / sizeof(int));  //sizeofֱ�Ӵ��ݻ�������д��ε�ʱ��Ҫ����һ������ֵ��ȥ

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	selectionsort(arr, sizeof(arr) / sizeof(int));

	for (int j = 0; j < sizeof(arr) / sizeof(int); j++) {
		printf("%d ", arr[j]);
	}


	return 0;
}