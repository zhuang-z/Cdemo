#include<stdio.h>
#include<stdlib.h>

int main() {

	//�ڶ������棬��������Ŀռ��С��̬�����ڴ棬�����ڴ���˷�
	//malloc�������ص��ǿ�ָ�����ͣ���Ҫ��������ת�����Լ���Ҫ��
	//calloc�������ص�Ҳ�ǿ�ָ�����ͣ�calloc(count,size) ��count��size��������
	//relloc�������ڷ�����ڴ治��ʱ����ԭ���Ļ����ϼ��ڴ�
	int number = 0;
	printf("������༶������\n");
	scanf_s("%d", &number);
	//Ϊ�༶���������ڴ�ռ�
	int* p = (int *)malloc(sizeof(int) * number); 
	//Ϊ�༶���������ڴ�ռ� {"xiaoyou","tiechui","goudan"}
	char(*name)[100] = (char(*)[100])calloc(number, 100);  //ʹ������ָ��������
	

	if (!p) return;  //��p��name����null��ʱ��ֱ����ͣ��������ִ�У�����û�пռ䵼�³���
	if (!name) return;

	//����ѧ��������
	for (int a = 0; a < number; a++) {
		scanf_s("%s", *(name + a),100);
	}
	
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &p[i]);   //����ѧ���ĳɼ���ȡ��ַ
	}

	for (int j = 0; j < number; j++) {
		printf("��%d��ѧ��%s�ĳɼ�:%d\n", j + 1, name[j], p[j]);
	}

	free(p);  //ʹ����֮���ͷſռ䣬�����ͷ����Σ������
	free(name);

	//relloc
	
	int* arr1 = (int *)malloc(12);
	if (!arr1) return;  //�ж��ڴ�ռ��Ƿ�Ϊ��
	arr1[0] = 100;
	arr1[1] = 200;
	arr1[2] = 300;
	
	// printf("%d\n", arr1[3]);   //arr[3] ����arr[0-2]�ķ�Χ
	
	int* arr2 = (int *)realloc(arr1,16);  //��arr1�϶����ռ䣬��ԭ���Ļ����ϼ�4
	if (!arr2) return;  //�ж��ڴ�ռ��Ƿ�Ϊ��
	arr2[3] = 400;
	printf("%d\n", arr2[3]);  //���Ҫ�µ���arr2������ᱨ��

	free(arr1);  //��free�Ļ��ᵼ���ڴ�й©
	free(arr2);

	return 0;
}