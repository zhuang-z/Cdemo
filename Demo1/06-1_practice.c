#include<stdio.h>
#include<math.h>
int main() {

	//����������ϰ
	//1.�ȶϢ���
	/*
	�ȶϢ�����Ҳ�ƶ��ڸ�Ϣ���������ÿ�°���ȵĽ������Ϣ������ÿ�´�����Ϣ���³�ʣ��������㲢���½��塣
	�¾����� = ����� * (������ * (1 + ������)^��������) / ((1 + ������)^�������� - 1)
	����Ϣ = �������� * �¾����� - �����
	����� = �����ܶ� * ���ҳ���*/

	/*
	���뷿�ݵ��ۡ���������ҳ��������������Լ���׼����
	�����ķ����ܶ���ڸ�������ܶ֧����Ϣ�Լ�ÿ����Ҫ������ٸ������ݡ�*/

	/*
	float price, area, ration, year, month, yrate, mrate;
	float total, first, daikuan, huankuan, lixi, yuejun;

	printf("�����뵥�ۣ�Ԫ/ƽ������");
	scanf_s("%f",&price);
	printf("�����������");
	scanf_s("%f", &area);
	printf("�����밴�ҳ�����");
	scanf_s("%f", &ration);
	printf("�����밴��������");
	scanf_s("%f", &year);
	printf("�����뵱ǰ��׼�����ʣ�");
	scanf_s("%f", &yrate);
	printf("============������===========\n");

	mrate = yrate /100 / 12; //������ ������/12
	month = year * 12; //�������� ��������*12

	total = price * area; //�����ܶ� �۸�*���
	first = total * (1 - ration * 0.1); //���ڸ��� �����ܶ�*(1-���ҳ���)
	daikuan = total * ration * 0.1; //�����ܶ� �����ܶ�*���ҳ���
	yuejun = daikuan * mrate * pow((1 + mrate), month) / (pow((1 + mrate), month) - 1); //�¾����� �����*(������*(1+������)^��������)/((1+������)^��������-1)
	lixi = month * yuejun - daikuan; //��Ϣ ��������*�¾�����-�����
	huankuan = daikuan + lixi; //�����ܶ� ��������*�¾�����


	printf("�����ܶ�%.2f\n",total);
	printf("���ڸ���%.2f\n",first);
	printf("�����ܶ�%.2f\n", daikuan);
	printf("�����ܶ�%.2f\n",huankuan);
	printf("֧����Ϣ%.2f\n",lixi);
	printf("�¾�����%.2f\n",yuejun);
	*/

	//2.����5�걾Ϣ��
	int n1 = 5, n2 = 3, n3 = 2;
	float deposite1, deposite2, deposite3;
	float principal = 60000; //����  
	// 14000Ԫ 5���Ϣ�� 94018.54Ԫ
	// 23000Ԫ 5���Ϣ�� 154459.05Ԫ
	// 40000Ԫ 5���Ϣ�� 268624.41Ԫ
	// 50000Ԫ 5���Ϣ�� 335780.50Ԫ  5*5 = 25��Ԫ ���� 85,780.5Ԫ ����34%
	// 60000Ԫ 5���Ϣ�� 402936.60Ԫ  6*5 = 30��Ԫ ���� 102936.6Ԫ ����34%
	float rate1 = 0.0275; //3 5�궨������
	float rate2 = 0.0225; //2������
	float rate3 = 0.0135; //1������
	float raw = principal;
	int year = 5;
	int i = 1;
	while (i <= year) {
		deposite1 = principal * (1 + rate1);
		if (i != year) {
			principal = deposite1 + raw;
		}
		i++;

	}
	//deposite1 = principal * (1 + rate1 * n1); //һ���Զ��ڴ�5�ꣻ
	//deposite2 = principal * (1 + rate1 * n2) * (1 + rate2 * n3); //�ȴ�3�궨�ڣ��ٴ�2�궨��
	//deposite3 = principal * (pow((1 + rate3), n1)); //��1�궨�ڣ��ڶ���ȡ���ٴ�1�꣬��������

	printf("һ���Զ��ڴ�5�걾Ϣ��%.2f %.2f\n", deposite1, principal);
	//printf("�ȴ�3�궨�ڣ��ٴ�2�궨�ڱ�Ϣ��%.2f\n", deposite2);
	//printf("��1�궨�ڣ��ڶ���ȡ���ٴ�1�꣬�������Ʊ�Ϣ��%.2f\n", deposite3);

	printf("%d\n", (1 != 0 && 2 / 1));
	return 0;
}