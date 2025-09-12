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

	4、对链表进行增删操作；
		(1).删除一个数据：
			删除第一个：pHead最先指向头部，直接让pHead->pNext赋值给pHead，然后把原来的pHead释放free掉；
			删除指定某个位置的数据：中间删掉了，前一个的next直接指向隔一个的数据，隔一个的数据是当前的位置的pNext，pPre->pNext直接指向当前的pNext
		(2).增加一个数据：
			增加第一个：pNew->pNext指向原来的pHead，pHead赋值成pNew；
			增加指定某个位置的数据；
			增加最后一个：原来的pEnd指向pNext，新的pEnd指向pNew
		

*/

struct student {
	char name[100];
	int iNumber;
	struct student* pNext;
};

int count = 0;

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

		count++;
	}

	return pHead;
}

void Print(struct student* pHead) {
	//通过pHead一直指向pNext的值，判断是否为空，为空就不打印了
	struct student* pTemp = pHead;
	printf("总共有%d个同学\n", count);
	int index = 1;
	while (pTemp != NULL) {
		printf("第%d个同学的信息\n", index);
		printf("%s,%d\n", pTemp->name, pTemp->iNumber);
		pTemp = pTemp->pNext;
		index++;
	}
}

struct student* DeleteHead(struct student* pHead) {
	struct student* pTemp = pHead; //先让临时指向原来的pHead，pHead重新赋值，然后释放临时的
	pHead = pHead->pNext;
	free(pTemp);
	printf("-------删除之后---------\n");
	count--;
	return pHead;
}

struct student* InsertHead(struct student* pHead) {
	struct student* pNew;
	pNew = (struct student*)malloc(sizeof(struct student));
	if (!pNew) return NULL;
	scanf_s("%s", pNew->name, 100);
	scanf_s("%d", &pNew->iNumber);

	pNew->pNext = pHead; //pNew的next指向原来的pHead
	pHead = pNew;   //pHead被pNew覆盖
	count++;
	return pHead;
}

struct student* DeletePosition(struct student* pHead,int index) { //index传入位置信息
	struct student* pTemp = pHead; //先让临时指向原来的pHead，pHead重新赋值，然后释放临时的
	struct student* pPre = pHead;

	if (index == 1) {
		return DeleteHead(pHead);
	}
	for (int i = 1; i < index; i++) { //例，index=3，从i=1开始找，符合条件，i进入循环，i++，i=2... i=3 不进入循环，正好找到
		pPre = pTemp; //进入循环后，pPre被pTemp覆盖，一直到序号位置的pTemp；
		pTemp = pTemp->pNext; // pTemp每次都被pNext覆盖 pHead pHead->pNext (pHead->pNext)->pNext
		//找到位置时，pPre正好是当前位置的上一个，pTemp正好是找到的；
	}
	//出循环后
	pPre->pNext = pTemp->pNext;
	free(pTemp);
	printf("-------删除之后---------\n");
	count--;
	return pHead;
}

int main() {

	struct student* pHead = Create();
	Print(pHead);

	//删除第一个数据
	//pHead = DeleteHead(pHead);
	// 
	//删除指定位置数据
	//pHead = DeletePosition(pHead,3);
	
	//添加第一个数据
	pHead = InsertHead(pHead);
	Print(pHead);


	return 0;
}