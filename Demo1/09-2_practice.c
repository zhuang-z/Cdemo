#include<stdio.h>

#include "ssebtr1.h"

int main() {
	int age;
	float rate, BPM_high;
	int BPM = 150;
	printf("请输入您的年龄：");
	scanf_s("%d", &age);

	BPM_high = (float)(220 - age);
	playSound(BPM);
	rate = getHeartRate();

	if (rate > BPM_high) {
		printf("请马上停止跑步,否则会有生命危险……");
	}
	else if (rate > (BPM_high * 0.85)) {
		printf("请放慢脚步");
		BPM = BPM - 20;
		playSound(BPM);
	}
	else if (rate > (BPM_high * 0.75)) {
		printf("Come on 请加快节奏！");
		BPM = BPM + 20;
		playSound(BPM);
	}
	else {
		playSound(BPM);
	}


	return 0;
}