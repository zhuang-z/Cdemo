#include<stdio.h>

//void swap(int *a,int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

int * swap(int a, int b) { //��һ�����Σ�����ֻ��������������һ��һά����
	int temp = a;
	a = b;
	b = temp;

	int arr[] = {a,b};
	return arr;
}

void sort(int *arr,int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1 -i; j++) {   //arr[j]��arr[0]��arr[1]�����Ƚϣ�һֱ�ȵ�arr[length]��������ð�ݣ��ڶ������һ�������Բ��ȣ�����arr[length-1]
			if (arr[j]>arr[j+1]) {
				//swap(&arr[j], &arr[j + 1]);  //swap������ָ�룬ֻ�ܴ������ֵ�ĵ�ַ
				//ʹ��һ��ָ�����
				int* arr1 = swap(arr[j],arr[j+1]);  //����arr[j]��arr[j+1]֮��ֱ�����ǽ��и�ֵ
				arr[j] = arr1[0];
				arr[j+1] = arr1[1];
			}
		}
	}
}

int main() {
	//���������������������   ð�ݻ���ѡ���������
	int arr[] = { 100,29,58,79,2,30,17 };
	
	sort(arr, sizeof(arr) / sizeof(int));  //sizeofֱ�Ӵ��ݻ�������д��ε�ʱ��Ҫ����һ������ֵ��ȥ

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}