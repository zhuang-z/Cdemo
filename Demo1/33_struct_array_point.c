#include<stdio.h>

typedef struct student1 {
	char name1[100];
	int age1;
}STU1;

typedef struct student2 {
	char name2[100];
	int age2;
}STU2;
int main() {

	STU1 student1[3]; //����ṹ������
	for (int i = 0; i < 3; i++) { //ͨ��ѭ����������ֵ
		scanf_s("%s%d", student1[i].name1, 100, &student1[i].age1);
	}

	for (int j = 0; j < 3; j++) {
		printf("ѧ��%s��������%d�ꡣ\n", student1[j].name1, student1[j].age1);
	}

	STU2 student2[3] = {
		{"Youzi",20},
		{"tiechui",23},
		{"xiaoming",25}
	};

	STU2* p = student2; //����ṹ��ָ��
	for (int a = 0; a < 3; a++) {
		printf("ѧ��%s��������%d�ꡣ\n", p[a].name2, p[a].age2);
	}

	printf("%s , %d\n", p[0].name2, p[0].age2); //ָ��ֱ�Ӷ�ȡ�������ַ��ֵ��Ҳ����������ĸ�ʽ
	printf("%s , %d\n", p->name2, p->age2);
	printf("%s , %d\n", p[1].name2, p[1].age2);
	printf("%s , %d\n", (p+1)->name2, (p+1)->age2);

	/*
	����ǲ�����ָ���ȡֵ�Ļ������Բο�ָ��ȡ���ε�ֵ��ȡ����ָ��ȡ�����ֵ��ȡ��
	int a = 100;
	int *p = &a;
	printf("%d",*p);

	int a[100];
	int *p = a;
	printf("%d",p[0]);
	printf("%d",*p);
	*/
	return 0;
}