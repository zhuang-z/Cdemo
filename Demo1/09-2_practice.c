#include<stdio.h>

#include "ssebtr1.h"

int main() {
	int age;
	float rate, BPM_high;
	int BPM = 150;
	printf("�������������䣺");
	scanf_s("%d", &age);

	BPM_high = (float)(220 - age);
	playSound(BPM);
	rate = getHeartRate();

	if (rate > BPM_high) {
		printf("������ֹͣ�ܲ�,�����������Σ�ա���");
	}
	else if (rate > (BPM_high * 0.85)) {
		printf("������Ų�");
		BPM = BPM - 20;
		playSound(BPM);
	}
	else if (rate > (BPM_high * 0.75)) {
		printf("Come on ��ӿ���࣡");
		BPM = BPM + 20;
		playSound(BPM);
	}
	else {
		playSound(BPM);
	}


	return 0;
}