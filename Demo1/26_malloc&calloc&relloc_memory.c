#include<stdio.h>
#include<stdlib.h>

int main() {

	//在堆区里面，根据申请的空间大小动态分配内存，避免内存的浪费
	//malloc函数返回的是空指针类型，需要进行类型转换成自己需要的
	//calloc函数返回的也是空指针类型，calloc(count,size) 有count和size两个参数
	//relloc函数是在分配的内存不足时，在原来的基础上加内存
	int number = 0;
	printf("请输入班级的人数\n");
	scanf_s("%d", &number);
	//为班级人数申请内存空间
	int* p = (int *)malloc(sizeof(int) * number); 
	//为班级人名申请内存空间 {"xiaoyou","tiechui","goudan"}
	char(*name)[100] = (char(*)[100])calloc(number, 100);  //使用数组指针来接收
	

	if (!p) return;  //当p和name等于null的时候，直接暂停，不继续执行，避免没有空间导致出错
	if (!name) return;

	//输入学生的名字
	for (int a = 0; a < number; a++) {
		scanf_s("%s", *(name + a),100);
	}
	
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &p[i]);   //输入学生的成绩，取地址
	}

	for (int j = 0; j < number; j++) {
		printf("第%d个学生%s的成绩:%d\n", j + 1, name[j], p[j]);
	}

	free(p);  //使用完之后释放空间，不能释放两次，会出错
	free(name);

	//relloc
	
	int* arr1 = (int *)malloc(12);
	if (!arr1) return;  //判断内存空间是否为空
	arr1[0] = 100;
	arr1[1] = 200;
	arr1[2] = 300;
	
	// printf("%d\n", arr1[3]);   //arr[3] 超过arr[0-2]的范围
	
	int* arr2 = (int *)realloc(arr1,16);  //在arr1上多分配空间，在原来的基础上加4
	if (!arr2) return;  //判断内存空间是否为空
	arr2[3] = 400;
	printf("%d\n", arr2[3]);  //最好要新调用arr2，否则会报错

	free(arr1);  //不free的话会导致内存泄漏
	free(arr2);

	return 0;
}