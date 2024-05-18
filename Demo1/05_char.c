#include<stdio.h>

int main() {
	/* 字符常量 */

	printf("欢迎xiaoyou回家！\n");  //字符串常量

	char a = 'K';  //单引号，里面只能放1个字符

	printf("字符是%d\n",a);  //%d 会把K以ASCII码的形式输出，A-Z 65-90 a-z 97-122
	printf("字符是%c\n",a);  //%c 才会输出K
	
	//单引号只能放1个字符；
	// 双引号能放两个字符 K和 \0结束符；
	char b = "K";  //识别不了，只能用单引号
	char c = "我"; //放单引号，因为汉字占两个字节，识别不了，用双引号，因为两个字节+\0占3个字节，识别不了
	printf("字符b是%c\n",b);
	printf("字符c是%c\n",c);
	
	//存汉字，存多个字符
	char str[] = "xiaoyou";    //单引号不行，字符串必须要用双引号

	printf("字符串是%s\n", str); //%s作为占位符
}