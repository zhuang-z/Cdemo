#include<stdio.h>
#include<raylib.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int x = 10;
	int y = 10;
	InitWindow(800, 500, "Test_Raylib");   //width height title
	SetTargetFPS(60);  //�޶�60֡��д��ѭ������

	while (!WindowShouldClose()) { // ������ڲ��ر�

		//��ͼ
		//��ʼ��ͼ
		BeginDrawing();
		
		//Color color = { 128,0,255 }; //�Զ�����ɫ
		//ClearBackground(WHITE); //ˢ�±�����ɫ ˢ�»ᵼ����갴���¼�ÿ�ζ�ˢ��
		// 
		// ������ͼ����
		// ������� DrawPixels  ����� ��stdlib.h�У�Ҫ��ʱ����ʹ��

#if 0
		srand((unsigned int)time(NULL)); //�������������
		int x = 0,y = 0;
		for (int i = 0; i < 800; i++) {
			x = rand() % 800; // 0-799 �����Ҫ��ʾһ�����Ǵ�0��ʼ�����ֵ�ģ�����˵����Ҫ����һ��0-99֮�������� int num = rand() % 100��
			y = rand() % 500; //0-499
			DrawPixel(x, y, RED); //����
		}
#endif

		// ��Բ
		DrawCircle(100, 100, 10, RED);	// X ,Y,�뾶,��ɫ
		DrawCircle(x, y, 10, ORANGE); //��x,y���껭Բ

		// ������
		DrawRectangle(200, 200, 100, 100, BLUE);	// X,Y,��,��,��ɫ

		//����¼� �������Բ �Ҽ�������
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			//��ȡ��ǰ������ x y
			int x1, y1;
			x1 = GetMouseX();
			y1 = GetMouseY();
			DrawCircle(x1, y1, 10, PINK);
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
			int x2, y2;
			x2 = GetMouseX();
			y2 = GetMouseY();
			DrawRectangle(x2 - 5, y2 - 5, 20, 20, PURPLE);
		}

		//������ͼ
		EndDrawing();

		//�¼������簴���ȣ���ͼ���¼���Ҫ�߻�ͼ�ߴ����¼����Ῠ��
		//���̰����¼� ��������    �����FPS���ƣ��ᵼ��ͼ���ƶ��úܿ죬��Ҫ��FPS��ˢ��������
		//SetTargetFPS(60);  //�޶�60֡��д��ѭ������
		if (IsKeyDown(KEY_LEFT)) {
			x -= 1;
		}
		if (IsKeyDown(KEY_RIGHT)) {
			x += 1;
		}
		if (IsKeyDown(KEY_DOWN)) {
			y += 1;
		}
		if (IsKeyDown(KEY_UP)) {
			y -= 1;
		}
		if (IsKeyDown(KEY_ESCAPE)) {
			break;
		}

	}

	CloseWindow();

	return 0;
}