#include<stdio.h>

int main() {

	////1. 1-100�ĺ�
	//int a1, sum1;
	//a1 = 1;
	//sum1 = 0;
	///*while (a1<=100) {
	//	sum1 += a1;
	//	a1++;
	//}
	//printf("%d\n", sum1);*/
	//do{                 //do while�����while�Ļ�������ֵ����ѭ��һ�Σ�ִ��ѭ��������֮�����ж������Ƿ�������������Ļ��ͽ���ѭ��
	//	sum1 += a1;
	//	a1++;
	//} while (a1 <= 100);
	//printf("%d\n", sum1);


	////2.�׳�

	//int a2, sum2=1;
	//scanf_s("%d", &a2);
	///*while (a2>=1) {
	//	sum2 *= a2;
	//	a2--;
	//}*/
	//do {
	//	sum2 *= a2;
	//	a2--;
	//} while (a2>=1);

	//printf("%d\n", sum2);


	//3.����ɼ����ж��ȼ����������100�������������룻
	int score = 0;
	do {      //do while�����while�Ļ�������ֵ����ѭ��һ�Σ�ִ��ѭ��������֮�����ж������Ƿ�������������Ļ��ͽ���ѭ��
		printf("������0-100�ĳɼ�\n");
		scanf_s("%d", &score);
	} while (score > 100);

	
	//while (score > 100) {      //��Ϊscore�ĳ�ʼֵΪ0������whileѭ����������������ֱ�ӻ�����whileѭ����ִ�������switch��䣬���ж����Ļ�score>100 || score == 0ʱ����������0�Ļ��ͻ�һֱ��ѭ����
	//	printf("������0-100�ĳɼ�\n");
	//	scanf_s("%d", &score);
	//}
	
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