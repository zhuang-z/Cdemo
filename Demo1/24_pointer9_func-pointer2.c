#include<stdio.h>


void myvideo(int* videodata);  //��myvideo��������
//gstreamer��������ݽ���
void gstreamer(int *videodata, void(*p)(int* showvideo)) {
	for(int i = 0; i < 3; i++ ){  //����videodata���ݣ���100
		videodata[i] += 100;
	}
	p(videodata);  //�Դ�����videodata���ݽ��лص�

}

void video(int *video) {
	gstreamer(video, myvideo);
}

//�Լ���װһ���������лص�
void myvideo(int *videodata) {
  	for (int i = 0; i < 3; i++) {
		printf("%d\n", videodata[i]);
	}
}


int main(){

	/*�ص�����
	* 1.ʹ��һ������A ���÷�װ�õķ���B��
	* 2.����B���β�Ҫ����һ��ԭʼ����data���Լ�һ������ָ��void (*p)(int *a)
	* 3.����B����ԭʼ����data��ʹ�ú���ָ�� p(a);���лص�,����C���н��գ�
	* video����arrֵ������gstreamer������д���������֮����лص����ص�ʹ��myvideo���н��գ�������
	*/
	int arr[] = { 11,22,33 };
	video(arr);


	return 0;
}