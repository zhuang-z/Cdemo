#include<stdio.h>
#include<stdlib.h>

int main() {

	//memset:(字符数组,初始化的值,重置的大小)在一段内存中可以把数据快速清零

	char* p1 = (char*)malloc(100);  //malloc不会初始化值
	char* p2 = (char*)calloc(25, 4); //calloc初始化值是0
	if (!p1) return;
	if (!p2) return;
	memset(p1, 2, 100);
	memset(p2, -1, 100);
	for (int i = 0; i < 100; i++) {
		printf("%d\n", p1[i]);
	}
	for (int i = 0; i < 100; i++) {
		printf("%d\n", p2[i]);
	}

	char p3[] = "xiaoyouzi";
	memset(p3, 1, 9);
	for (int i = 0; i < 9; i++) {
		printf("%d\n", p3[i]);
	}

	int* p4 = (int*)malloc(100); //int占4个字节
	if (!p4) return;
	memset(p4, -1, 100); //初始化只能是0或者-1
	for (int i = 0; i < 100/sizeof(int); i++) {  //大小要除以sizeof(int)
		printf("%d\n", p4[i]);
	}


	return 0;
}