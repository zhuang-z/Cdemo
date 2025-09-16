#include<stdio.h>
#include<raylib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

#define WIDTH 800
#define HEIGHT 500

//获取当前时间

// 绘制一个电子时钟
// 先画三个空心圆
// 
// 再画时钟点
// 
// 再画时针 分针  秒针
// 
// 最后加上音效
//

void time_Now() {
	
}

void Clock_InitWindow() {   //初始化窗口
	InitWindow(WIDTH, HEIGHT,"Digi_Clock");
}

void Clock_CloseWindow() {  //关闭窗口
	CloseWindow();
}

//表盘
void Draw_Clock_plate() {
	//三个空心圆
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 180, BLACK);
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 80, BLACK);
	DrawCircleLines(WIDTH / 2, HEIGHT / 2, 1, BLACK);

	//时刻点，0,3,6,9,12点是矩形，其他点是小圆
	//需要计算弧度  圆的弧度是2π，某个点的坐标是 圆心坐标 + 半径 * 角度的正弦/余弦

	int x = WIDTH / 2;
	int y = HEIGHT / 2;

	//把一个圆分成60等份进行遍历
	for (int i = 0; i < 60; i++) {
		x = WIDTH / 2 + 165 * sinf(i * (2 * PI / 60));
		y = HEIGHT / 2 + 165 * cosf(i * (2 * PI / 60));

		if (i % 15 == 0) { // 0 3 6 9 点矩形
			Rectangle Rect = { x - 5,y - 5,8,8 };
			DrawRectangleRec(Rect, BLACK);
		}
		//其他点 124578 10 11是实心点
		else if (i % 5 == 0) {
			DrawCircle(x, y, 2, BLACK);
		}
		else {
			DrawPixel(x, y, BLACK); //每10分钟的地方画一个点
		}
	}
}

//表针
void Draw_Clock_Hand() {
	//先获取当前时间,获取时间戳转换成当前时间
	/*
	struct tm* time_now = NULL;  //tm结构体里面有 时分秒
	time_t data = time(NULL);
	//time_now = localtime(&data); //使用localtime 需要把解决方案属性里面的 常规->SDL检查改成否才能正常运行；
	*/
	struct tm time_now;
	time_t data = time(NULL);
	localtime_s(&time_now, &data);

	//取出时 分 秒
	int hour = time_now.tm_hour;
	int min = time_now.tm_min;
	int sec = time_now.tm_sec;
	/*
	int hour = time_now->tm_hour;
	int min = time_now->tm_min;
	int sec = time_now->tm_sec;
	*/

	//定义弧度和坐标
	double a_hour, a_min, a_sec;
	int x_hour, y_hour, x_min, y_min, x_sec, y_sec;

	//弧度转换成坐标
	//1圈360度，1圈弧度是2*PI，1秒就是6度
	a_sec = sec * 2 * PI / 60; //当前秒数的弧度
	a_min = min * 2 * PI / 60 + a_sec / 60;  // 分钟需要加上 秒的弧度(转换成分钟)
	a_hour = hour * 2 * PI / 12 + a_min / 60; // 小时需要加上 分钟的弧度(转换成小时)

	//秒 时 分 坐标转换
	x_sec = 120 * sinf(a_sec);
	y_sec = 120 * cosf(a_sec);

	x_min = 100 * sinf(a_min);
	y_min = 100 * cosf(a_min);

	x_hour = 70 * sinf(a_hour);
	y_hour = 70 * cosf(a_hour);



	//根据坐标画线
	DrawLine(WIDTH / 2 + x_sec, HEIGHT / 2 - y_sec, WIDTH / 2 - x_sec / 3, HEIGHT / 2 + y_sec / 3, BLACK);
	DrawLine(WIDTH / 2 + x_min, HEIGHT / 2 - y_min, WIDTH / 2 - x_min / 5, HEIGHT / 2 + y_min / 5, BLACK);
	DrawLine(WIDTH / 2 + x_hour, HEIGHT / 2 - y_hour, WIDTH / 2 - x_hour / 7, HEIGHT / 2 + y_hour / 7, BLACK);
}

//1秒钟定时器
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

		//1、表盘
		Draw_Clock_plate();

		//2、表针
		Draw_Clock_Hand();

		EndDrawing();

		//播放音效
		if (Ontimer()) {
			PlaySound(s);
		}
	}
	CloseAudioDevice();
}



int main() {

	Clock_InitWindow();

	//在窗口里绘图
	Clock_Drawing("./res/clock.wav");


	Clock_CloseWindow();
	return 0;
}