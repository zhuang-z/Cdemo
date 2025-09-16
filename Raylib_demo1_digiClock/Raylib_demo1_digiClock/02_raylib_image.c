#include<stdio.h>
#include<raylib.h>
#include<stdlib.h>
#include<time.h>

int main() {

	Image image = LoadImage("./res/1.jpg");

	//Texture image = LoadTexture("./res/1.jpg");    //但不能先加载纹理再初始窗口，会崩溃
	InitWindow(image.width, image.height, "Load_image");  //加载图像长宽的窗口

	//InitWindow(800, 500, "Test_Raylib");   //width height title

	Texture img = LoadTexture("./res/1.jpg"); //等于下面两句话，Texture一定得有窗口

	//Image image = LoadImage("./res/1.jpg");   //先加载到image，再加载纹理，最终只能绘制纹理
	//Texture img = LoadTextureFromImage(image);

	InitAudioDevice();
	Music m = LoadMusicStream("./res/1.mp3");   //加载音频文件
	Sound s = LoadSound("./res/3.mp3");       //加载音效文件 一般是wav格式，但如果下载的是mp3格式，手动改后缀无效，需要转换格式

	PlayMusicStream(m);   // 播放音乐


	while (!WindowShouldClose()) { // 如果窗口不关闭

		//绘图
		//开始绘图
		BeginDrawing();
		DrawTexture (img, 0, 0, WHITE);
		
		//DrawTextureEx 可以旋转，缩放
		//Vector2 vector = { 0,0 }; //x,y 从哪个坐标开始
		//DrawTextureEx(img, vector, 0, 0.5, WHITE);

		//切图 显示图像的哪一块 DrawTextureRec
		//Rectangle Rec = { 500,500,100,100 }; // x, y ,width , height
		//DrawTextureRec(img, Rec, vector, WHITE);

		//在窗口中需要刷新音乐流,才能播放
		//UpdateMusicStream(m);


		//点击鼠标左键播放音效
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			PlaySound(s);
		}

		//结束绘图
		EndDrawing();

	}
	UnloadTexture(img);  //释放Texture
	CloseWindow();
	CloseAudioDevice();

	return 0;
}