#include<stdio.h>
#include<raylib.h>
#include<stdlib.h>
#include<time.h>

int main() {

	Image image = LoadImage("./res/1.jpg");

	//Texture image = LoadTexture("./res/1.jpg");    //�������ȼ��������ٳ�ʼ���ڣ������
	InitWindow(image.width, image.height, "Load_image");  //����ͼ�񳤿�Ĵ���

	//InitWindow(800, 500, "Test_Raylib");   //width height title

	Texture img = LoadTexture("./res/1.jpg"); //�����������仰��Textureһ�����д���

	//Image image = LoadImage("./res/1.jpg");   //�ȼ��ص�image���ټ�����������ֻ�ܻ�������
	//Texture img = LoadTextureFromImage(image);

	InitAudioDevice();
	Music m = LoadMusicStream("./res/1.mp3");   //������Ƶ�ļ�
	Sound s = LoadSound("./res/3.mp3");       //������Ч�ļ� һ����wav��ʽ����������ص���mp3��ʽ���ֶ��ĺ�׺��Ч����Ҫת����ʽ

	PlayMusicStream(m);   // ��������


	while (!WindowShouldClose()) { // ������ڲ��ر�

		//��ͼ
		//��ʼ��ͼ
		BeginDrawing();
		DrawTexture (img, 0, 0, WHITE);
		
		//DrawTextureEx ������ת������
		//Vector2 vector = { 0,0 }; //x,y ���ĸ����꿪ʼ
		//DrawTextureEx(img, vector, 0, 0.5, WHITE);

		//��ͼ ��ʾͼ�����һ�� DrawTextureRec
		//Rectangle Rec = { 500,500,100,100 }; // x, y ,width , height
		//DrawTextureRec(img, Rec, vector, WHITE);

		//�ڴ�������Ҫˢ��������,���ܲ���
		//UpdateMusicStream(m);


		//���������������Ч
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			PlaySound(s);
		}

		//������ͼ
		EndDrawing();

	}
	UnloadTexture(img);  //�ͷ�Texture
	CloseWindow();
	CloseAudioDevice();

	return 0;
}