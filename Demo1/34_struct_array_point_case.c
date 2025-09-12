#include<stdio.h>
#include<stdlib.h>


typedef struct student {
	char name[100];
	int score;
}STU;

int main() {
	int num = 0;  //对num初始化，否则录入会产生缓冲区溢出
	printf("请输入要录入学生的人数\n");
	scanf_s("%d",&num);

	STU* stup = (STU*)malloc(num * sizeof(STU));  //(STU*)强制转换成这个结构体的指针类型
	for (int i = 0; i < num; i++) {
		int a = i + 1;
		printf("请录入第%d个同学的姓名和成绩\n", a);
		scanf_s("%s%d", stup[i].name,100, &stup[i].score);
	}

	for (int k = 0; k < num; k++) {
		int b = k + 1;
		printf("第%d个同学%s的成绩是%d\n", b, (stup + k)->name, (stup + k)->score);  //转换成"->"打印同学的成绩
	}

	float sum = 0;
	for (int j = 0; j < num; j++) {
		sum += stup[j].score;
		//sum += (stup+j)->score;
	}

	printf("同学的平均分是%f分。\n", (sum/num));

	return 0;
}