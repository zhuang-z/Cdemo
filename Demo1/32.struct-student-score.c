#include<stdio.h>

typedef struct student {
	int age;
	int score;
	char name[100];  
	//����ʹ��char *name;¼��ķ�ʽ������ָ�룬��ָ��Ļ�ֻ����malloc�����ڴ�֮����forѭ����ֵ
}STU;

int main() {

	STU student1;
	printf("����������\n");
	scanf_s("%d", &student1.age);   //���μǵ�ȡ��ַ��
	printf("������ɼ�\n");
	scanf_s("%d", &student1.score);
	printf("����������\n");
	scanf_s("%s", student1.name , 100); //Ҫ���ַ��ĳ������ƣ����ⳬ��
	printf("%d���%s�ĳɼ���%d\n", student1.age, student1.name, student1.score);

	/*Ҳ��������¼��
	printf("���������������䣬�ɼ�\n");
	scanf_s("%s%d%d", student1.name, 100, &student1.age, &student1.score);
	printf("%s,%d,%d\n", student1.name, student1.age, student1.score);
	*/

	return 0;
}