#include<stdio.h>

int main() {

	/*
		fgetc：一个一个获取字符,读到最后一个EOF才结束
		fputc：一个一个字符的写入
		fgets：读取字符串，遇到"\0"或者换行会结束,读取的之前先初始化字符串，大小可以最大的写入
		fputs：写入字符串
		fread：读取字符串，遇到"\0"或者换行不会结束，但是要自己手动初始化字符串或手动补结束符"\0"
		fputs：写入字符串
	*/
	FILE* fp1,* fp2,* fp3;

	int error1 = fopen_s(&fp1, "You.txt", "r");

	if (error1 != 0) {
		printf("open failed!\n");
		return;
	}

	int error2 = fopen_s(&fp2, "You1.txt", "w");

	if (error2 != 0) {
		printf("open failed!\n");
		return;
	}

	int error3 = fopen_s(&fp3, "You2.txt", "w");

	if (error3 != 0) {
		printf("open failed!\n");
		return;
	}

	/*
	char ch;
	while((ch = fgetc(fp1)) != EOF){
		printf("%c",ch);
		//fputc(ch, stdout); //stdout默认在终端中打印
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	*/

	char str[100] = "";  //对字符串进行初始化，方便后续fgets大小不用计算
	char str1[100] = ""; //对字符串进行初始化，方便后续fread大小不用计算
	/*
	fgets(str, 100, fp1); //fgets (str,5,fp1) str是读取的字符串， 5是大小 ，fp1是文件 You的内容是Youzi，如果大小是5的话，只能读到Youz，最后一个是"\0"
	fputs(str, fp2);
	fclose(fp1);
	fclose(fp2);
	*/
	//fread(str1, sizeof(char), 5, fp1); 
	//str1[5] = "\0" //如果没有初始化字符串的话，只能手动补结束符"\0"
	fread(str1, sizeof(char), 100, fp1); //fread(str1, sizeof(char), 100, fp1)  str1读取的字符串。sizeof是数据类型的大小，100是块大小，总的大小 = 数据类型大小*块大小，返回值是实际读到的块数
	fwrite(str1,sizeof(char),100, fp3);  //fwrite(str1,sizeof(char),100, fp3) 也需要这样的格式，数据类型大小和块大小

	fclose(fp1);
	fclose(fp3);

	return 0;
}
