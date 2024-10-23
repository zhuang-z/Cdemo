#include<stdio.h>
#include<stdlib.h>
#include<string.h> //字符串处理函数的库
void split(char* str, char *p, char** splitstr);
//告诉编译器，不用检查安全性
//#pragma warning(diasble:4996)  4996是错误码
int main() {
	char* p1 = (char*)malloc(100);
	char* str = "xiaoyouzi";

	// p =str; //str直接赋值给p，str拿到的是字符串的地址，p是指向字符串的，但是p申请的100的内存空间没使用
	//if (!p) return;
	//for(int i = 0; i < 9; i++){
	//	p[i] = str[i]; //警告
	//}

	//printf("%s", p);

	//1.strcpy_s函数：strcpy_s(目标地址，字节数，源地址)
	if (!p1) return;
	strcpy_s(p1, 10, str);  //字符串长度要对应,最后有"\0"
	printf("%s\n", p1);
	//free(p1);

	//2.strlen函数：strlen：返回字符串字符的个数，不包含"\0"
	printf("%zd\n", strlen(p1));   //打印strlen需要用%zd
	free(p1);

	char* p2 = (char*)malloc(100);
	if (!p2) return;
	strcpy_s(p2, strlen(str)+1, str); //strlen不包含"\0",要加1
	printf("%s\n", p2);
	free(p2);

	//3.strncpy_s:复制字符串的前多少个字符
	char* p3 = (char*)malloc(100);
	if (!p3) return;
	strncpy_s(p3,strlen(str)+1,str,4); //最后的参数是多少位,当这个位数超过整个字符串大小时,会以随机数进行填充
	/*for (int i = 0; i < 15; i++){
		printf("%d\n", p3[i]);
	}*/
	printf("%s\n", p3);
	free(p3);

	//4.strcat_s:字符串追加函数，在原有的字符串追加字符串，对于字符串常量，不能使用strcpy和strcat这些方法，不能复制新的字符串来占用已经申请的字符串常量的地方，也不能在字符串后面追加
	char* p4 = (char*)malloc(120);
	if (!p4) return;
	char* str1 = "先生/女士";

	scanf_s("%s", p4, 100);
	strcat_s(p4, 120, str1); //120:附加字符串之后的大小不超过申请的内存空间大小
	printf("%s\n", p4);
	strncat_s(p4, 120, str1, 2); //2表示附加字节的大小
	printf("%s\n", p4);
	free(p4);

	/*char *mystr = "xiaoyouzi"
	  strcat_s(mystr,120,str1);
	  printf("%s",mystr); //会出问题，因为是mystr定义的是字符串常量区，不能更改
	*/

	//5.strcmp strncmp:字符串比较函数
	char* p5 = "abc";
	char* p5_1 = "abd";
	char* p5_2 = "abb";
	char* p5_3 = "abc";
	printf("%d\n",strcmp(p5, p5_1));
	printf("%d\n", strcmp(p5, p5_2));
	printf("%d\n", strcmp(p5, p5_3));
	printf("%d\n", strncmp(p5, p5_1,3));  //比较p5 和 p5_1的前三个字符大小

	//应用：注册账号时，第一次输入密码和第二次输入密码是否一致

	char* p5_4 = (char*)malloc(100);
	char* p5_5 = (char*)malloc(100);
	if (!p5_4 || !p5_5) return;
	scanf_s("%s", p5_4, 100);
	scanf_s("%s", p5_5, 100);
	if (strcmp(p5_4, p5_5) == 0) {
		printf("密码正确\n");
	}
	else {
		printf("两次密码不一致\n");
	}
	free(p5_4);
	free(p5_5);

	//6.strchr strstr strrchr():判断字符是否在字符串中，模糊查找
	char* p6_1 = "xiaoyouzi";
	char* p6_2 = strchr(p6_1, 'i');  //strchr,只会匹配查到的第一个字符
	char* p6_3 = strrchr(p6_1, 'i');
	printf("%p\n", p6_1);
	printf("%p\n", p6_2);
	printf("%d\n", (int)(p6_3 - p6_1));

	char* p6_4[] = { "youzi","yoyo","goudan" };
	char p6_5 = 0;
	
	/*例如在scanf_s("%s", p4, 100);和scanf_s("%s", p5_4, 100);
	以及scanf_s("%s", p5_5, 100);之后，输入缓冲区可能会残留换行符等字符。
	如果下一个输入是scanf_s("%c", &p6_5, 1);，这个换行符可能会被这个输入直接读取，
	导致程序没有等待用户输入新的字符。*/
	int c;
	while ((c = getchar()) != '\n' && c != EOF); //清除输入缓冲区中的残留字符

	printf("请输入你要查找的模糊字符：\n");
	scanf_s("%c", &p6_5, 1);  //strchr只能对字符查找，因此输入的只能是1个字符
	for (int i = 0; i < sizeof(p6_4) / sizeof(char*); i++) {
		if (strchr(p6_4[i], p6_5) !=NULL) {
			printf("%s\n", p6_4[i]);
		}
	}


	while ((c = getchar()) != '\n' && c != EOF); //清除输入缓冲区中的残留字符

	char* p6_6[] = { "youzi","yoyo","goudan","gouzi"};
	char p6_7[100];

	printf("请输入你要查找的模糊字符串：\n");
	scanf_s("%s", &p6_7,100);  //strchr只能对字符查找，因此输入的只能是1个字符

	//对p7_2进行字符串拼接
	strcat_s(p6_7,100, "");
	for (int i = 0; i < sizeof(p6_6) / sizeof(char*); i++) {
		if (strstr(p6_6[i], p6_7) != NULL) {  //strstr不包含'\0',因此要进行字符串的拼接
			printf("%s\n", p6_6[i]);
		}
	}


	//7.strtok:字符串切割 strtok只有两个参数，字符串和分隔符
	//  strtok_s(字符串,分隔符,缓冲区)
	char p7_1[100] = "深圳|坪山|高新园,aaa,ccc"; //不能用char *p7_1 = "深圳|坪山|高新园";指向的字符串常量;
	//在使用strtok_s等函数需要修改字符串内容时，
	//不能使用指向字符串常量的指针，而应该使用字符数组或者动态分配的可修改内存空间。
	char* splitstr[100];

	//char* buf = NULL;  //设定指针再取地址，二级指针
	//splitstr[0] = strtok_s(p7_1, "|", &buf); //切割之后要定义成指针数组来接收,且strtok只能切一次
	////printf("%s\n", splitstr[0]);
	////继续进行切割
	//int i1 = 0;
	//while (splitstr[i1]) {
	//	i1++;
	//	splitstr[i1] = strtok_s(NULL, "|", &buf);//从上一次切割的地方继续切割
	//}

	//用split函数调用；
	split(p7_1, "|,", splitstr);  //strtok对分隔符会自动处理

	//打印
	int m = 0;
	while (splitstr[m]) {
		printf("%s\n", splitstr[m]);
		m++;
	}


	return 0;
}

void split(char *str,char *p,char **splitstr) {  //字符数组用指针接收，字符串也用指针接收，指针数组用二级指针接收
	char* buf = NULL;  //设定指针再取地址，二级指针
	splitstr[0] = strtok_s(str, p, &buf); //切割之后要定义成指针数组来接收,且strtok只能切一次
	//printf("%s\n", splitstr[0]);
	//继续进行切割
	int i = 0;
	while (splitstr[i]) {
		i++;
		splitstr[i] = strtok_s(NULL, p, &buf);//从上一次切割的地方继续切割
	}
}