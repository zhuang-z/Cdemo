#include<stdio.h>
#include<raylib.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int x = 10;
	int y = 10;
	InitWindow(800, 500, "Test_Raylib");   //width height title
	SetTargetFPS(60);  //限定60帧，写在循环外面

	while (!WindowShouldClose()) { // 如果窗口不关闭

		//绘图
		//开始绘图
		BeginDrawing();
		
		//Color color = { 128,0,255 }; //自定义颜色
		//ClearBackground(WHITE); //刷新背景颜色 刷新会导致鼠标按键事件每次都刷新
		// 
		// 基本绘图函数
		// 画随机点 DrawPixels  随机数 在stdlib.h中，要与时间结合使用

#if 0
		srand((unsigned int)time(NULL)); //设置随机数种子
		int x = 0,y = 0;
		for (int i = 0; i < 800; i++) {
			x = rand() % 800; // 0-799 如果想要表示一个数是从0开始到最大值的，比如说，想要产生一个0-99之间的随机数 int num = rand() % 100；
			y = rand() % 500; //0-499
			DrawPixel(x, y, RED); //画点
		}
#endif

		// 画圆
		DrawCircle(100, 100, 10, RED);	// X ,Y,半径,颜色
		DrawCircle(x, y, 10, ORANGE); //以x,y坐标画圆

		// 画矩形
		DrawRectangle(200, 200, 100, 100, BLUE);	// X,Y,宽,高,颜色

		//鼠标事件 按左键画圆 右键画矩形
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			//获取当前鼠标光标的 x y
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

		//结束绘图
		EndDrawing();

		//事件，比如按键等，绘图和事件不要边绘图边处理事件，会卡顿
		//键盘按键事件 ↑↓←→    不添加FPS限制，会导致图形移动得很快，需要加FPS，刷新率限制
		//SetTargetFPS(60);  //限定60帧，写在循环外面
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