#include<stdio.h>
#include "17_control.h"
/*��̨���̣�
* 1 ң��������̨��  1,2,3,4,5,6������  acceptcontorl
* 2 ���ӽ��ܹ����źŲ���ѡ��һ���źŽ��н����� parse
*	2.1 �����̨���źŽ�����Ƶ������ parseaudio
*	2.2 �����̨�źŽ�����Ƶ������  parsevideo
  3 ��ʾ���̨�Ļ���   display

*/
static int acceptchannel;  //��������ú�������

int main() {

	acceptcontrol();

	return 0;
}