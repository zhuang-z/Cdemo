#include<stdio.h>


void myvideo(int* videodata);  //对myvideo进行声明
//gstreamer库进行数据解析
void gstreamer(int *videodata, void(*p)(int* showvideo)) {
	for(int i = 0; i < 3; i++ ){  //处理videodata数据，加100
		videodata[i] += 100;
	}
	p(videodata);  //对处理后的videodata数据进行回调

}

void video(int *video) {
	gstreamer(video, myvideo);
}

//自己封装一个函数进行回调
void myvideo(int *videodata) {
  	for (int i = 0; i < 3; i++) {
		printf("%d\n", videodata[i]);
	}
}


int main(){

	/*回调函数
	* 1.使用一个函数A 调用封装好的方法B；
	* 2.方法B的形参要传入一个原始数据data，以及一个函数指针void (*p)(int *a)
	* 3.方法B处理原始数据data，使用函数指针 p(a);进行回调,函数C进行接收；
	* video接收arr值，传到gstreamer里面进行处理，处理完之后进行回调，回调使用myvideo进行接收，最后输出
	*/
	int arr[] = { 11,22,33 };
	video(arr);


	return 0;
}