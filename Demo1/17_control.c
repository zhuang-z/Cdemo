#include <stdio.h>
#include "17_parse.h"
static int globalchannel;
//接收遥控器换台的函数
void acceptcontrol() {
	//用 do while循环    控制台输入能切换到相应频道，输入当前台，不切换
	do{
		int channel = 0;
		printf("请输入频道\n");
		scanf_s("%d", &channel);
		if (globalchannel != channel) {  //当之前频道跟输入不一样时就切换频道
			globalchannel = channel;
			printf("切换至%d频道\n", channel);

			parse(channel);   //对频道进行解析
		}
	
	
	} while (1);

}