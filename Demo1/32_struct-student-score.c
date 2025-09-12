#include<stdio.h>

typedef struct student {
	int age;
	int score;
	char name[100];  
	//不能使用char *name;录入的方式不能用指针，用指针的话只能用malloc分配内存之后用for循环赋值
}STU;

int main() {

	STU student1;
	printf("请输入年龄\n");
	scanf_s("%d", &student1.age);   //整形记得取地址符
	printf("请输入成绩\n");
	scanf_s("%d", &student1.score);
	printf("请输入姓名\n");
	scanf_s("%s", student1.name , 100); //要有字符的长度限制，避免超过
	printf("%d岁的%s的成绩是%d\n", student1.age, student1.name, student1.score);

	/*也可以整体录入
	printf("请输入姓名，年龄，成绩\n");
	scanf_s("%s%d%d", student1.name, 100, &student1.age, &student1.score);
	printf("%s,%d,%d\n", student1.name, student1.age, student1.score);
	*/

	return 0;
}