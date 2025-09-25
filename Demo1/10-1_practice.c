#include<stdio.h>
#include<stdbool.h>

// 
// 四则运算：输入式子 + - * / 输出结果
int main() {
	printf("请输入式子 : ");
	float a, b;
	float result = 0;
	char c;
	// 修正：为 %c 指定缓冲区大小
	scanf_s("%f %c %f", &a, &c, 1, &b); // 跟字符相关的需要确定缓冲区大小，定义char的大小
	bool invaild = false;
	
	switch (c) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b != 0) {
			result = a / b;
			break;
		}
		else {
			invaild = true;
			break;
		}
	}
	if (invaild) {
		printf("除数不能为零");
	}
	else {
		printf("结果是 : %.2f\n", result);
	}

	return 0;
}