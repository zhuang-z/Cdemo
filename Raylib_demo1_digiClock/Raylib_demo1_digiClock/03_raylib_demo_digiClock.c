#include<stdio.h>
#include<raylib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

#define WIDTH 800
#define HEIGHT 500

//��ȡ��ǰʱ��

// ����һ������ʱ��
// �Ȼ���������Բ
// 
// �ٻ�ʱ�ӵ�
// 
// �ٻ�ʱ�� ����  ����
// 
// ��������Ч
//

void time_Now() {
	
}

void Clock_InitWindow() {   //��ʼ������
	InitWindow(WIDTH, HEIGHT,"Digi_Clock");
}

void Clock_CloseWindow() {  //�رմ���
	CloseWindow();
}

//����
void Draw_Clock_plate() {
	//��������Բ
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 180, BLACK);
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 80, BLACK);
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 1, BLACK);

	//ʱ�̵㣬0,3,6,9,12���Ǿ��Σ���������СԲ
	//��Ҫ���㻡��  Բ�Ļ�����2�У�ĳ����������� Բ������ + �뾶 * �Ƕȵ�����/����

	int x = WIDTH / 2;
	int y = HEIGHT / 2;

	//��һ��Բ�ֳ�60�ȷݽ��б���
	for (int i = 0; i < 60; i++) {
		x = WIDTH / 2 + 165 * sinf(i * (2 * PI / 60));
		y = HEIGHT / 2 + 165 * cosf(i * (2 * PI / 60));

		if (i % 15 == 0) { // 0 3 6 9 �����
			Rectangle Rect = { x - 5,y - 5,8,8 };
			DrawRectangleRec(Rect, BLACK);
		}
		//������ 124578 10 11��ʵ�ĵ�
		else if (i % 5 == 0) {
			DrawCircle(x, y, 2, BLACK);
		}
		else {
			DrawPixel(x, y, BLACK); //ÿ10���ӵĵط���һ����
		}
	}
}

//����
void Draw_Clock_Hand() {
	//�Ȼ�ȡ��ǰʱ��,��ȡʱ���ת���ɵ�ǰʱ��
	/*
	struct tm* time_now = NULL;  //tm�ṹ�������� ʱ����
	time_t data = time(NULL);
	//time_now = localtime(&data); //ʹ��localtime ��Ҫ�ѽ��������������� ����->SDL���ĳɷ�����������У�
	*/
	struct tm time_now;
	time_t data = time(NULL);
	localtime_s(&time_now, &data);

	//ȡ��ʱ �� ��
	int hour = time_now.tm_hour;
	int min = time_now.tm_min;
	int sec = time_now.tm_sec;
	/*
	int hour = time_now->tm_hour;
	int min = time_now->tm_min;
	int sec = time_now->tm_sec;
	*/

	//���廡�Ⱥ�����
	double a_hour, a_min, a_sec;
	int x_hour, y_hour, x_min, y_min, x_sec, y_sec;

	//����ת��������
	//1Ȧ360�ȣ�1Ȧ������2*PI��1�����6��
	a_sec = sec * 2 * PI / 60; //��ǰ�����Ļ���
	a_min = min * 2 * PI / 60 + a_sec / 60;  // ������Ҫ���� ��Ļ���(ת���ɷ���)
	a_hour = hour * 2 * PI / 12 + a_min / 60; // Сʱ��Ҫ���� ���ӵĻ���(ת����Сʱ)

	//�� ʱ �� ����ת��
	x_sec = 120 * sinf(a_sec);
	y_sec = 120 * cosf(a_sec);

	x_min = 100 * sinf(a_min);
	y_min = 100 * cosf(a_min);

	x_hour = 70 * sinf(a_hour);
	y_hour = 70 * cosf(a_hour);



	//�������껭��
	DrawLine(WIDTH / 2 + x_sec, HEIGHT / 2 - y_sec, WIDTH / 2 - x_sec / 3, HEIGHT / 2 + y_sec / 3, BLACK);
	DrawLine(WIDTH / 2 + x_min, HEIGHT / 2 - y_min, WIDTH / 2 - x_min / 5, HEIGHT / 2 + y_min / 5, BLACK);
	DrawLine(WIDTH / 2 + x_hour, HEIGHT / 2 - y_hour, WIDTH / 2 - x_hour / 7, HEIGHT / 2 + y_hour / 7, BLACK);
}

//1���Ӷ�ʱ��
bool Ontimer() {
	static int start;
	if (start == 0) {
		start = clock();
	}
	int end = clock();
	if (end - start == 1000) { //1000 ms
		start = end;
		return true;
	}
	return false;
}

void Clock_Drawing(char *filename) {

	InitAudioDevice();
	Sound s = LoadSound(filename);

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);

		//1������
		Draw_Clock_plate();

		//2������
		Draw_Clock_Hand();

		EndDrawing();

		//������Ч
		if (Ontimer()) {
			PlaySound(s);
		}
	}
	CloseAudioDevice();
}



int main() {

	Clock_InitWindow();

	//�ڴ������ͼ
	Clock_Drawing("./res/clock.wav");


	Clock_CloseWindow();
	return 0;
}