#include<stdio.h>
#include "17_display.h"
extern void parseaudio();
extern void parsevideo();

static int parsedio; //定义静态全局变量，赋值成parsechannel的值

void parse(int parsechannel) {
	printf("对%d频道进行解析\n",parsechannel);
	parsedio = parsechannel;
	parseaudio();
	parsevideo();

	//显示界面
	display();
}


//这两个函数只在parse.c文件中使用，使用静态函数最好，不让其他文件访问，无法定义到头文件中让别人调用
static void parseaudio() {
	printf("对%d频道进行音频解析\n", parsedio);
}

static void parsevideo() {
	printf("对%d频道进行视频解析\n", parsedio);
}