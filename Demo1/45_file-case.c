#include<stdio.h>
#include<stdlib.h>
int main() {
	//文件应用：读取文件内容，打印到终端
	//文件大小在不确定的情况下如何获取，并按大小分配内存

	FILE* fp;
	int error = fopen_s(&fp, "file.txt", "rb+"); //使用fread方法读取文件，最后也还是有乱码，原因是ftell在遇到换行时会出问题，需要在打开文件方式时以2进制方式打开 "rb+"
	if (error != 0) {
		return;
	}

	//可以fseek定位后文件的末尾，然后用ftell获取文件指针当前位置距离文件开头的字节数，这样就可以得到文件的大小
	fseek(fp, 0, SEEK_END); //将文件指针定位到文件末尾
	int length = ftell(fp); //获取文件指针当前位置距离文件开头的字节数

	char *str = (char *)malloc(length + 1); //按文件大小分配内存，+1是为了存放字符串结束符
	if (!str) return;

	rewind(fp); //将文件指针重新指向文件开头,fseek已经指向了文件末尾，需要重新指向文件开头
	//fgets(str, length + 1, fp); //1、读取文件内容到str中 ，使用fgets方法读取到换行就会结束，需换成fread方法
	fread(str, length+1, 1, fp); //2、读取文件内容到str中,length+1的大小，1块
	str[length] = '\0'; //2、需要手动添加字符串结束符，补完结束符后还会出现乱码，是因为ftell在遇到换行时会处问题，需要在打开文件方式时以2进制方式打开

	printf("%s\n", str); //直接打印会乱码，终端是以GBK编码显示中文字符的，需要将“file.txt”使用记事本方式另存为，转换成ANSI编码格式

	fclose(fp);
	free(str);

	return 0;
}