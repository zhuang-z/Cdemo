#include <stdio.h>
#include "17_parse.h"
static int globalchannel;
//����ң������̨�ĺ���
void acceptcontrol() {
	//�� do whileѭ��    ����̨�������л�����ӦƵ�������뵱ǰ̨�����л�
	do{
		int channel = 0;
		printf("������Ƶ��\n");
		scanf_s("%d", &channel);
		if (globalchannel != channel) {  //��֮ǰƵ�������벻һ��ʱ���л�Ƶ��
			globalchannel = channel;
			printf("�л���%dƵ��\n", channel);

			parse(channel);   //��Ƶ�����н���
		}
	
	
	} while (1);

}