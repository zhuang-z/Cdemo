#include<stdio.h>
#include<string.h>

int main() {

	//rewind函数将文件指针重新指向文件开头
	/*fseek函数将文件指针重新指向文件的某个位置，有3个参数，第一个参数是文件指针，第二个参数是偏移量，第三个参数是起始位置，
	 起始位置有三个宏定义，SEEK_SET(文件开头) 0，SEEK_CUR(当前位置) 1，SEEK_END(文件末尾) 2*/
	 //ftell函数返回文件指针当前位置距离文件开头的字节数

	 //网站注册 登录，只注册密码，登录时输入密码，与文件或数据库中提取的密码进行对比 验证密码是否正确
	char password[7] = "";
	printf("注册密码：");
	scanf_s("%s", password, 7); //输入注册密码

	//将输入的密码字符串写入文件
	FILE* fp;
	int error = fopen_s(&fp, "password.txt", "w+");
	if (error != 0) {
		printf("open failed!\n");
		return;
	}

	fputs(password, fp); //将密码写入文件

	int length = ftell(fp); //获取文件指针当前位置距离文件开头的字节数
	printf("%d\n", length);
	if(length == 6){
		printf("注册成功\n");
	}
	else {
		printf("注册失败\n");
		return;
	}

	/*
	if (password[0] != '\0') { //判断密码是否越界，越界为空则注册失败，后面都不执行
		printf("注册成功\n");
	}
	else {
		printf("注册失败\n");
		return;
	}*/

	//登录
	printf("登录密码：");
	scanf_s("%s", password, 7); //输入登录密码 直接覆盖password之前的数组空间

	char password_db[7] = "";
	//rewind(fp); //将文件指针重新指向文件开头

	//fseek(fp, 0, SEEK_SET); //也可以用fseek(fp,0,0)将文件指针重新指向文件开头，0表示偏移量为0，0表示从文件开头开始偏移
	fseek(fp, -6, SEEK_CUR); //文件指针此时在末尾 结束符处，如果要从头开始的话，需将偏移量设置为负数，-6表示从当前位置向前偏移6个字节 123456
	//fseek(fp, -5, SEEK_END); //文件指针从末尾 结束符处，-5表示从文件末尾向前偏移5个字节 23456

	fgets(password_db, 7, fp); //从文件中读取密码，因为文件指针在文件末尾，所以读取不到内容
	printf("%s\n", password_db);

	//判断密码是否正确
	int result = strcmp(password, password_db);//strcmp比较两个字符串的ASCII码，前面的大于后面的返回正数，前面的等于后面的返回0，前面的少于后面的返回负数
	if (result == 0) {
		printf("登录成功\n");
	}
	else {
		printf("登录失败 %d\n", result);
	}

	return 0;
}