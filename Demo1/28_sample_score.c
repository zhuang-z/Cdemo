#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ѧ������������ѧ���������ɼ�
//ѧ������������ָ�����棬�ɼ���һά��������
#define NUM 100
//���屣��ѧ����������������,���ֵ100
typedef char(*PNAME)[NUM];

int main() {
	//����ѧ��������
	int person = 0;
	printf("������ѧ����������\n");
	scanf_s("%d", &person);
	//�����������ڴ�ռ�person*num���ֽڴ�С
	PNAME name = (char*)calloc(person, NUM);
	//����ɼ����ڴ�ռ�,��С��sizeof(int) * person Ȼ����ת����int *
	int* score = (int *)malloc(sizeof(int) * person);
	if (name == NULL || score == NULL) return;
	//����ѧ���������ͳɼ�
	for (int i = 0; i < person; i++) {
		printf("�������%d��ѧ����������\n", i + 1);
		scanf_s("%s", name[i], NUM); //ȡ��i�е�0�еĵ�ַ
		printf("�������%d��ѧ���ĳɼ���\n", i + 1);
		scanf_s("%d", &score[i]);   //score��һά���飬Ҫȡ�������ֵ��score[i]ֱ��ȡ��ֵ�ˣ�Ҫ�ټ�һ����ַ��"&"
	}

	//����ѧ������
	char search[NUM];
	printf("��������Ҫ��ѯ��ѧ������\n");
	scanf_s("%s", &search, NUM);  //����ַ��ȥ
	//ƴ��'\0'
	strcat_s(search, NUM, "");
	int exist = 1;
	for (int i = 0; i < person; i++) {
		if (strstr(name[i], search) != NULL) {
			printf("ѧ��%s���ɼ���%d\n", name[i], score[i]);
		}
		else {
			exist = 0;
		}
	}

	if (!exist) {
		printf("��ѯ��ѧ��������\n");
	}

	free(name);
	free(score);
	return 0;
}