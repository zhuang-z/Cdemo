#include<stdio.h>
#include<stdbool.h>

int main() {

	//��ϵ����� > < == >= <= !=
	int a = 28;
	if (a>=28) {  //()����������ϣ�ִ��{}������
		printf("��������\n");
	}

	//�������� C89û��bool����  C99�żӽ���  ������#include<stdbool.h>
	bool isMatch = true; // true:1 false:0
	printf("%d\n", isMatch);


	/*
		�߼������
			&&���룬ͬ��Ϊ�棬һ����٣�
			||����һ�����棬ͬ��Ϊ�٣�
			�����ǣ�ȡ����
	*/

	printf("%d\n", 1 > 2 && 3 > 4);
	printf("%d\n", 1 > 2 || 3 > 4);
	printf("%d\n", !(1 > 2));  //�ǵ����ȼ��ȹ�ϵ�����Ҫ��

	/*
		�̳� ��ĩ���ҵ���250Ԫ��7�ۣ�
	*/
	int day = 6;  //��������������ܴ���
	int type = 1; //0��ʳƷ  1���ҵ� 2������Ʒ
	int price = 300;

	if (price > 250 && type == 1 && !(day == 6 || day == 7)) {
		price *= 0.7;
		printf("%d\n", price);
	}

	//&&��·

	int gender = 0; //0��ʾŮ��1��ʾ��
	if (gender == 0) {
		printf("Ů\n");
	}
	//&&��·д����ǰ������Ż���к���Ĵ�ӡ���
	gender == 1 && printf("��\n");

	return 0;
}