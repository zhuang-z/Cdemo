#include<stdio.h>

int main() {
	//switch 穿透 跟if比最大的优势是有多种情况的时候会自动跳到相应的分支，不会从头开始判断
	
	//1.输入月份，这个月有多少天；
	/*int month;
	scanf_s("%d", &month);
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31天\n");
			break;
		case 2:
			printf("28天\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30天\n");
			break;
		default:
			printf("月份有误\n");
			break;
	}*/


	//2.成绩按区间分类 成绩数字太大，需要除以10得到的十位数作为常量
	int score;
	scanf_s("%d", &score);
	int flag = score / 10;
	switch (flag) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}

	return 0;
}