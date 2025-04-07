#include<stdio.h>
#include<stdlib.h>
/*链表：从第一个内存空间一直链接到最后一个内存空间
	1、首先定义一个结构体，结构体里面有姓名和学号两个数据类型，加上*pNext的指针，用于指向下一个结构体；
	2、分别有三个指针进行链表操作，pHead,pEnd,pNew；
		pNew：申请新的内存空间；
		pHead：指向头部的数据，从此就不需要变化；
		pEnd：指向每次申请内存空间结束；
	3、逻辑：
		(1).pNew申请的第一个内存空间，pHead,pEnd都指向pNew；pHead = pEnd = pNew = (struct student*)malloc(sizeof(student));
		(2).pNew申请下一个内存空间，也就是pNew->pNext指向的内存空间先要为NULL，重新申请空间；
			然后pEnd的pNext也要往后移一个空间，也就是pEnd->pNext = pNew;
			最后pEnd指向新的pNew，也就是pEnd = pNew;
			以此类推；
*/

struct student {
	char name[100];
	int iNumber;
	struct student* pNext;
};

struct student* Create() { //录入函数返回pHead
	struct student* pHead = NULL;
	struct student* pEnd, * pNew;
	//pHead可以不用这么早赋值
	/*pHead =*/ pEnd = pNew = (struct student*)malloc(sizeof(struct student)); //指向结构体指针，转换成万能指针

	if (!pNew) return NULL;//return NULL;去除警告
	printf("请输入学号和姓名，输入学号为0时停止输入\n");
	scanf_s("%s", pNew->name, 100);
	scanf_s("%d", &pNew->iNumber);
	//输入姓名和学号，输入0时停止输入，需要用到while循环

	pNew->pNext = NULL;
	if (pNew->iNumber != 0) { //当输入为0时，pHead不赋值，不打印
		pHead = pNew;
	}

	while (pNew->iNumber != 0) {

		//pNew->iNumber != 0，下一个空间要重新申请
		pNew = (struct student*)malloc(sizeof(struct student));
		if (!pNew) return NULL;
		//申请后重新录入
		scanf_s("%s", pNew->name, 100);
		scanf_s("%d", &pNew->iNumber);

		//录入后，要更新pEnd->pNext和pEnd的位置
		//这样会把最后是0的那组数据也输出，加个判断，还是会在结束时出现延迟
		//是因为最后是0时，pEnd的pNext没有分配地址，是一个野指针，最开始时要
		//分配pNew->pNext = NULL;
		if (pNew->iNumber != 0) {
			pNew->pNext = NULL;
			pEnd->pNext = pNew;
			pEnd = pNew;
		}
	}

	return pHead;
}

void Print(struct student* pHead) {
	//通过pHead一直指向pNext的值，判断是否为空，为空就不打印了
	struct student* pTemp = pHead;
	while (pTemp != NULL) {
		printf("%s,%d\n", pTemp->name, pTemp->iNumber);
		pTemp = pTemp->pNext;
	}
}


int main() {

	struct student* pHead = Create();
	Print(pHead);
	return 0;
}