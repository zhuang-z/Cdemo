#include<stdio.h>

int main() {
	//switch ��͸ ��if�������������ж��������ʱ����Զ�������Ӧ�ķ�֧�������ͷ��ʼ�ж�
	
	//1.�����·ݣ�������ж����죻
	/*int month;
	scanf_s("%d", &month);
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31��\n");
			break;
		case 2:
			printf("28��\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30��\n");
			break;
		default:
			printf("�·�����\n");
			break;
	}*/


	//2.�ɼ���������� �ɼ�����̫����Ҫ����10�õ���ʮλ����Ϊ����
	int score;
	scanf_s("%d", &score);
	int flag = score / 10;
	switch (flag) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}

	return 0;
}