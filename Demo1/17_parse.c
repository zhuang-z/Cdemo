#include<stdio.h>
#include "17_display.h"
extern void parseaudio();
extern void parsevideo();

static int parsedio; //���徲̬ȫ�ֱ�������ֵ��parsechannel��ֵ

void parse(int parsechannel) {
	printf("��%dƵ�����н���\n",parsechannel);
	parsedio = parsechannel;
	parseaudio();
	parsevideo();

	//��ʾ����
	display();
}


//����������ֻ��parse.c�ļ���ʹ�ã�ʹ�þ�̬������ã����������ļ����ʣ��޷����嵽ͷ�ļ����ñ��˵���
static void parseaudio() {
	printf("��%dƵ��������Ƶ����\n", parsedio);
}

static void parsevideo() {
	printf("��%dƵ��������Ƶ����\n", parsedio);
}