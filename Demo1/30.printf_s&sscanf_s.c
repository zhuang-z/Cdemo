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
	printf("%s", straddress1[0]);
	return 0;
}