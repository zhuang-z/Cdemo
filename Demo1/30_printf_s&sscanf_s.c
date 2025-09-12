#include<stdio.h>


int main() {

	//sprintf_s：把字符串拼接打印到内存中
	char str[100];
	sprintf_s(str, 100, "尊敬的%s先生/女士", "xiaoyou");
	printf("%s\n", str);

	char time[100];
	sprintf_s(time, 100, "%d时 %d分 %d秒", 22, 10, 40);
	printf("%s\n", time);

	//sscanf_s:字符串分割
	char* address = "辽宁 大连 沈阳";
	char straddress[3][100]; //使用二维数组来接收
	sscanf_s(address,"%s %s %s",straddress[0],100, straddress[1],100, straddress[2],100); //100代表不能超过的定义的最大值,以空格来分割；
	printf("%s\n", straddress[1]);

	char* address1 = "辽宁|大连|沈阳";
	char straddress1[3][100];
	sscanf_s(address1, "%[^|]|%[^|]|%[^|]", straddress1[0], 100, straddress1[1], 100, straddress1[2], 100);  //%s %s %s 分割的话会把address1全部写进straddress1[0]中，剩下的两个都是乱码
	printf("%s\n", straddress1[0]);

	//sscanf_s:其他用法
	/*
	* 1、跳过数据 %*s %*d 
	  2、指定宽度 %8s:输出前8个字节
	  3、集合操作 %[a-z]:遇到第一个不在a-z之间的就不输出了
				 %[abc]:%[Youzi] 精确匹配字符串，打乱顺序也可以匹配
				 %[^abc]: ^表示非，遇到第一个在里面的就不输出了
	*/

	char* address2 = "辽宁 大连 沈阳收拾收拾";
	char straddress2[2][100]; //%*s跳过第一个数据之后，只需要用到二维数组来接收既可；
	sscanf_s(address2, "%*s %s %8s", straddress2[0], 100, straddress2[1], 100);
	printf("%s\n", straddress2[1]);

	char* name = "ouYzi 1999";
	char buf1[100];
	char buf2[100];
	char buf3[100];
	sscanf_s(name, "%[a-z]", buf1, 100); //%[a-z]:遇到第一个不在a-z之间的就不输出了
	sscanf_s(name, "%[Youzi ]", buf2, 100); //% [abc]:%[Youzi] 精确匹配字符串，打乱顺序也可以匹配
	sscanf_s(name, "%[^9]", buf3, 100);//%[^abc]:^ 表示非，不在abc里面的字符就输出，遇到第一个在abc里面的就不输出了
	printf("%s\n", buf1);
	printf("%s\n", buf2);
	printf("%s\n", buf3);

	char* address3 = "辽宁|大连|沈阳";
	char straddress3[3][100];
	sscanf_s(address3, "%[^|]|%[^|]|%[^|]", straddress3[0], 100, straddress3[1], 100, straddress3[2], 100);  //%s %s %s 分割的话会把address1全部写进straddress1[0]中，剩下的两个都是乱码
	//上面这一行就使用到 ^ 非这个动作，辽宁不是"丨"输出，然后丨在里面不输出，"丨"进行分隔，然后逐步匹配大连，沈阳，类比
	printf("%s\n", straddress3[0]);



	return 0;
}