#include<stdio.h>

void xiaoyou_scanf(int *p) {  //形参接受实参的地址

	printf("%p\n", p);

	//输入b是1000，int *p接收b的地址，p代表b的地址，*p代表b地址的值

	*p = 1000;
}

int main() {
	
	int a = 100;
	printf("%d\n", a);  //打印a的值
	printf("%p\n", &a);  //%p  &a  是打印a的地址
	// printf("%d\n", &a); 打印地址时用%d,会提示用int *进行定义，
	// 用指针进行定义，指针是存入一个值的内存地址的变量

	int* p = &a;   //int *p用来接收a的地址，*号挨着int或者挨着p都没关系，都是修饰p的，p就是地址，*p就是a的值
	printf("%p\n", p);

	char name[1] = {'xiao'};
	printf("%s\n", name);  
	printf("%p\n", name);  //对于数组而言，数组名就是地址

	//写一个scanf_s类似的函数
	int b;   //输入b，得到b的值
	printf("%p\n",&b);  //地址和函数里的地址一样
	xiaoyou_scanf(&b);  //实参获取b的地址符

	printf("%d\n", b);

	return 0;
}