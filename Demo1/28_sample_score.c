#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//输入学生人数，输入学生姓名及成绩
//学生姓名用数组指针来存，成绩用一维数组来存
#define NUM 100
//定义保存学生姓名的数据类型,最大值100
typedef char(*PNAME)[NUM];

int main() {
	//输入学生的人数
	int person = 0;
	printf("请输入学生的人数：\n");
	scanf_s("%d", &person);
	//申请姓名的内存空间person*num的字节大小
	PNAME name = (char*)calloc(person, NUM);
	//申请成绩的内存空间,大小：sizeof(int) * person 然后再转换成int *
	int* score = (int *)malloc(sizeof(int) * person);
	if (name == NULL || score == NULL) return;
	//输入学生的姓名和成绩
	for (int i = 0; i < person; i++) {
		printf("请输入第%d个学生的姓名：\n", i + 1);
		scanf_s("%s", name[i], NUM); //取第i行第0列的地址
		printf("请输入第%d个学生的成绩：\n", i + 1);
		scanf_s("%d", &score[i]);   //score是一维数组，要取到里面的值，score[i]直接取到值了，要再加一个地址符"&"
	}

	//查找学生姓名
	char search[NUM];
	printf("请输入你要查询的学生姓名\n");
	scanf_s("%s", &search, NUM);  //传地址进去
	//拼接'\0'
	strcat_s(search, NUM, "");
	int exist = 1;
	for (int i = 0; i < person; i++) {
		if (strstr(name[i], search) != NULL) {
			printf("学生%s，成绩是%d\n", name[i], score[i]);
		}
		else {
			exist = 0;
		}
	}

	if (!exist) {
		printf("查询的学生不存在\n");
	}

	free(name);
	free(score);
	return 0;
}