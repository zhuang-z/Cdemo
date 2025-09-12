#include<stdio.h>

/*
	1、内存分配原则1：根据基本类型的最大占用空间申请内存，比如int占4个字节，char占用1个字节，会以4个字节的步进申请内存空间；
	2、内存分配原则2：会根据字节类型的大小的倍数来存储未使用的申请空间，比如char占1个字节，short占2个字节，int占4个字节，三个类型一共占用8个字节；
					因为根据int申请4个字节(0,1,2,3)，char占1个，short会从2的倍数开始占用空间，占用2,3，int重新申请4个字节用来存储，所以一共8个字节；
	3、会根据定义的顺序进行内存空间申请，比如定义 char short int，占8个；
	定义 char int short 占12个，因为int存不下char占用的那个空间了，需要重新申请，short也是如此；
	4、数组多出来的空间，也会根据最大基本类型申请空间进行存储；
		例:char[10],int a; 根据int申请4个步进，char的0-8占用8个字节，9和10也需要申请4个字节来存储，所以一起16个字节
*/

struct stu1 {
	char a;
	short b;
	int c;
};

struct stu2 {
	char a;
	int c;
	short b;
};

struct stu3 {
	char a[10];
	int b;
};

int main() {

	struct stu1 student1;
	struct stu2 student2;
	struct stu3 student3;

	printf("%lld\n", sizeof(student1));  //8
	printf("%lld\n", sizeof(student2));  //12
	printf("%lld\n", sizeof(student3));  //16

	return 0;
}