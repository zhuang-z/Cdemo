#include<stdio.h>

int main() {

	int arr[] = { 213,453,3332,46,32,1,576,345,23,98 };  //10���� 0-9
	for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++){   //�ܹ�Ҫ���ж��ٴ�ѭ��
		//�����ֵ�����Ƚϣ���Ŀ����³���
		//i���±����ʱ��a[10]>a[11],����a[11]��0�����Ե�һ��i<sizeof(arr)/sizeof(int)-1-0(i)���ڶ�����-1-1(i)����������-1-1-1(i) .. ��i�ξ���-1-i
		for (int j = 0; j < sizeof(arr) / sizeof(int) - 1 -i; j++) {  
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		//{213 453 46 32 1 576 345 23 98 3332}  ��һ���3332���ף��ŵ�����棬�ڶ���ѭ���Ͱ�576���ף��ڶ��ο�����һ�αȽ�
	}



	for (int a = 0; a < sizeof(arr) / sizeof(int); a++) {
		printf("%d ", arr[a]);
	}

	return 0;
}