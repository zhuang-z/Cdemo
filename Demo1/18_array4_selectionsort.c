#include<stdio.h>

int main() {

	int arr[] = { 213,453,3332,46,32,1,576,345,23,98 };

	//ѡ�������ȼٶ���һ��������ֵ��С��Ȼ��������ֵ���ν��бȽϣ��������ֵС���ͽ�������
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {  //�ܹ�Ҫ���ж��ٴ�ѭ��
		int index = i;   //index��i��ʼ
		//��һ��ѭ����arr[0]��ʼ���ڶ���ѭ����arr[1]��ʼ ������ ��arr[i]��ʼ
		for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
			if (arr[j] < arr[index]) {  //��arr[j]��ֵ��arr[index]��ֵС��ʱ�򣬽�������ֵ
				index = j;
			}
		}
		//��һ��ѭ������arr[0]��arr[index]��ֵ���ڶ���ѭ������arr[1]��arr[index]��ֵ������
		if (index != i) {  //��index��ֵ����iʱ�����轻��
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