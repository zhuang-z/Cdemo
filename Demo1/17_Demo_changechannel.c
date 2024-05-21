#include<stdio.h>
#include "17_control.h"
/*切台流程：
* 1 遥控器输入台号  1,2,3,4,5,6。。。  acceptcontorl
* 2 电视接受广电的信号波，选择一个信号进行解析； parse
*	2.1 对这个台的信号进行音频解析； parseaudio
*	2.2 对这个台信号进行视频解析；  parsevideo
  3 显示这个台的画面   display

*/
static int acceptchannel;  //定义参数让函数接受

int main() {

	acceptcontrol();

	return 0;
}