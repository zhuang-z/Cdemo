#include<stdio.h>
#include<stdlib.h>


typedef struct student {
	char name[100];
	int score;
}STU;

int main() {
	int num = 0;  //��num��ʼ��������¼���������������
	printf("������Ҫ¼��ѧ��������\n");
	scanf_s("%d",&num);

	STU* stup = (STU*)malloc(num * sizeof(STU));  //(STU*)ǿ��ת��������ṹ���ָ������
	for (int i = 0; i < num; i++) {
		int a = i + 1;
		printf("��¼���%d��ͬѧ�������ͳɼ�\n", a);
		scanf_s("%s%d", stup[i].name,100, &stup[i].score);
	}

	for (int k = 0; k < num; k++) {
		int b = k + 1;
		printf("��%d��ͬѧ%s�ĳɼ���%d\n", b, (stup + k)->name, (stup + k)->score);  //ת����"->"��ӡͬѧ�ĳɼ�
	}

	float sum = 0;
	for (int j = 0; j < num; j++) {
		sum += stup[j].score;
		//sum += (stup+j)->score;
	}

	printf("ͬѧ��ƽ������%f�֡�\n", (sum/num));

	return 0;
}