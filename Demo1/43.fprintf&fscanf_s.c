#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[100];
	int score;
}STU;

int main() {
	int num = 0;
	printf("������Ҫ¼��ѧ��������\n");
	scanf_s("%d", &num);
	STU* student = (STU *)malloc(num * sizeof(STU));
	if (!student) return; //�ж��ڴ��Ƿ����ɹ�

	for (int i = 0; i < num; i++) {
		printf("������¼��ĵ�%d��ѧ���������ͳɼ�\n", i + 1);
		scanf_s("%s%d",student[i].name,100,&student[i].score);
	}

	FILE* fp1;

	int error1 = fopen_s(&fp1,"Youzi.txt","w+"); //w+ �ɶ���д�ķ�ʽ���ļ�
	if (error1 != 0) {
		printf("open failed!\n");
		return;
	}

	fwrite(student, sizeof(STU), num, fp1); //��student�ṹ�����������д���ļ���д���ļ��������ַ�������������ʾ������д��ĳɼ�����������(�����ƣ���ȫ����)
	fclose(fp1);

	FILE* fp2;
	int error2 = fopen_s(&fp2, "Youzi1.txt", "w+");
	if (error2 != 0) {
		printf("open failed!\n");
		return;
	}

	//fprintf�������Խ���ʽ��������д���ļ�,��һ���������ļ�ָ�룬�ڶ��������ͺ�printfд��һ�£�������Ҫд�������
	for (int j = 0; j < num; j++) {
		printf("%s,%d\n",(student+j)->name,(student+j)->score); //���ն˴�ӡ���
		fprintf(fp2, "%s,%d\n", (student + j)->name, (student + j)->score); //��student�ṹ�����������д���ļ���д����ļ������ַ����ͳɼ����ݶ���������ʾ
	}
	fclose(fp2);

	//fscanf_s,���ļ��ж�ȡ���ݣ���һ���������ļ�ָ�룬�ڶ���������scanf_sд��һ�£������Ƕ�ȡ���ݵı�����ַ
	int num1 = 100;
	FILE* fp3;
	int error3 = fopen_s(&fp3, "Youzi2.txt", "w+");
	if (error3 != 0) {
		printf("open failed!\n");
		return;
	}

	fprintf(fp3, "%d", num1); //��num1д���ļ�

	int num2 = 0;
	rewind(fp3); //���ļ�ָ������ָ���ļ���ͷ
	fscanf_s(fp3,"%d",&num2); //���ļ���ͷ�ж�ȡ�������ݸ�ֵ��num2
	printf("%d\n", num2); //�ᷢ�ִ�ӡ��������0����Ϊ�ļ�ָ����д�����ݺ��Ѿ�ָ���ļ�ĩβ��ֻ�ܶ�ȡ�����һ��������0��������ǰ��Ҫ��rewind�������ļ�ָ������ָ���ļ���ͷ

	return 0;
}