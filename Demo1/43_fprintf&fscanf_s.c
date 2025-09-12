#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[100];
	int score;
}STU;

int main() {
	int num = 0;
	printf("请输入要录入学生的人数\n");
	scanf_s("%d", &num);
	STU* student = (STU *)malloc(num * sizeof(STU));
	if (!student) return; //判断内存是否分配成功

	for (int i = 0; i < num; i++) {
		printf("请输入录入的第%d个学生的姓名和成绩\n", i + 1);
		scanf_s("%s%d",student[i].name,100,&student[i].score);
	}

	FILE* fp1;

	int error1 = fopen_s(&fp1,"Youzi.txt","w+"); //w+ 可读可写的方式打开文件
	if (error1 != 0) {
		printf("open failed!\n");
		return;
	}

	fwrite(student, sizeof(STU), num, fp1); //将student结构体数组的数据写入文件，写入文件的数据字符串可以正常显示，但是写入的成绩数据是乱码(二进制，安全考虑)
	fclose(fp1);

	FILE* fp2;
	int error2 = fopen_s(&fp2, "Youzi1.txt", "w+");
	if (error2 != 0) {
		printf("open failed!\n");
		return;
	}

	//fprintf函数可以将格式化的数据写入文件,第一个参数是文件指针，第二个参数就和printf写法一致，后面是要写入的数据
	for (int j = 0; j < num; j++) {
		printf("%s,%d\n",(student+j)->name,(student+j)->score); //在终端打印输出
		fprintf(fp2, "%s,%d\n", (student + j)->name, (student + j)->score); //将student结构体数组的数据写入文件，写入的文件数据字符串和成绩数据都能正常显示
	}
	fclose(fp2);

	//fscanf_s,从文件中读取数据，第一个参数是文件指针，第二个参数和scanf_s写法一致，后面是读取数据的变量地址
	int num1 = 100;
	FILE* fp3;
	int error3 = fopen_s(&fp3, "Youzi2.txt", "w+");
	if (error3 != 0) {
		printf("open failed!\n");
		return;
	}

	fprintf(fp3, "%d", num1); //将num1写入文件

	int num2 = 0;
	rewind(fp3); //将文件指针重新指向文件开头
	fscanf_s(fp3,"%d",&num2); //从文件开头中读取整形数据赋值给num2
	printf("%d\n", num2); //会发现打印出来的是0，因为文件指针在写入数据后已经指向文件末尾，只能读取到最后一个结束符0，所以在前面要加rewind函数将文件指针重新指向文件开头

	return 0;
}