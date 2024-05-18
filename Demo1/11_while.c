#include<stdio.h>

int main() {

	////1. 1-100的和
	//int a1, sum1;
	//a1 = 1;
	//sum1 = 0;
	///*while (a1<=100) {
	//	sum1 += a1;
	//	a1++;
	//}
	//printf("%d\n", sum1);*/
	//do{                 //do while相较于while的话会先让值进入循环一次，执行循环里的语句之后再判断条件是否成立，不成立的话就结束循环
	//	sum1 += a1;
	//	a1++;
	//} while (a1 <= 100);
	//printf("%d\n", sum1);


	////2.阶乘

	//int a2, sum2=1;
	//scanf_s("%d", &a2);
	///*while (a2>=1) {
	//	sum2 *= a2;
	//	a2--;
	//}*/
	//do {
	//	sum2 *= a2;
	//	a2--;
	//} while (a2>=1);

	//printf("%d\n", sum2);


	//3.输入成绩，判定等级，输入大于100的数就重新输入；
	int score = 0;
	do {      //do while相较于while的话会先让值进入循环一次，执行循环里的语句之后再判断条件是否成立，不成立的话就结束循环
		printf("请输入0-100的成绩\n");
		scanf_s("%d", &score);
	} while (score > 100);

	
	//while (score > 100) {      //因为score的初始值为0，进入while循环的条件不成立，直接会跳过while循环，执行下面的switch语句，加判断语句的话score>100 || score == 0时，假如输入0的话就会一直在循环里
	//	printf("请输入0-100的成绩\n");
	//	scanf_s("%d", &score);
	//}
	
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