#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
*	//为了代码的可移植性，使用scanf fopen方法，不使用 scanf_s fopen_s 加上这句代码 #define _CRT_SECURE_NO_WARNINGS
	图书借阅系统：
	1、在终端展示系统的功能：录入书籍、速览书籍、借阅书籍、归还书籍、查找书籍、删除书籍、退出系统；
	2、用户输入数字选择功能；
		(1).录入书籍：书名、价格、数量；通过链表的形式每次在头部插入新书籍信息，每次都直接覆盖原有数据；
		(2).速览书籍：打印所有书籍信息；
		(3).借阅书籍：输入书名，找到对应书籍，数量-1，若数量为0，提示库存不足；
		(4).归还书籍：输入书名，找到对应书籍，数量+1；
		(5).查找书籍：输入书名，找到对应书籍，打印书籍信息；
		(6).删除书籍：输入书名，找到对应书籍，从链表中删除该节点，并释放内存；
		(7).退出系统：退出程序。
	2-1：
		根据键入的数字，选择对应功能；
	2-2：
		链表存储书籍信息：
		(1).定义结构体指针，包括书籍信息(书名、价格、数量),和指向下一节点的指针；
		(2).初始化头结点，头结点不存储书籍信息，只存储指向下一节点的指针，指向NULL；
		(3).每次录入书籍信息时，在头结点后插入新节点；即NewNode->next = NodeHead->next,NodeHead->next = NewNode;
		(4).其他功能通过遍历链表实现。

*/


//菜单函数
void menu() {
	printf("--------------------------\n");
	printf("0.录入书籍\n");
	printf("1.速览书籍\n");
	printf("2.借阅书籍\n");
	printf("3.归还书籍\n");
	printf("4.查找书籍\n");
	printf("5.删除书籍\n");
	printf("6.退出系统\n");
	printf("--------------------------\n");
	printf("请输入(0-6):\n");
}

//录入书籍
//书籍信息结构体
struct bookInfo {
	char name[100];
	float price;
	int num;
};

//链表节点结构体
struct Node {
	struct bookInfo data;
	struct Node* next;
};

//创建链表头节点
struct Node* list = NULL;

struct Node* createHead() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	if (!headNode) return;
	headNode->next = NULL; //头结点里的next指针指向NULL，无书籍信息

	return headNode; //返回头结点地址
}

//根据录入的信息，创建链表节点
struct Node* createNode(struct bookInfo data) {
	//新建链表节点
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) return;
	newNode->data = data; //将录入的信息赋值给新节点
	newNode->next = NULL; //新节点的next指针指向NULL
	return newNode; //返回新节点地址
}

//插入新增信息到头部
void insertBook(struct Node* headNode, struct bookInfo data) {

	struct Node* newNode = createNode(data); //创建新节点

	//将新节点插入到头结点
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//对链表数据进行排序
void sortBookList(struct Node* list) {
	//冒泡排序链表的数据，存储到文件中
	struct Node* move = list->next;
	struct Node* sort = list->next;
	struct bookInfo temp; //定义一个临时变量，交换数据
	struct Node* save = NULL; //定义一个临时节点指针，指向最后一个已经排序好的节点,比较一轮后保存最后一个节点的位置
	for (sort = list->next; sort->next != NULL; sort = sort->next) {  //控制比较轮数
		//for (move = list->next; move->next != NULL; move = move->next) { //move从首节点开始往后移动比较 实际每一轮都从头结点比较到最后
		for(move = list->next; move->next != save; move= move->next){
			if (strcmp(move->data.name, move->next->data.name) > 0) {
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
		}
		save = move; //保存最后一个已经排序好的节点位置
	}
}

//读取文件中的书籍信息到链表
void readBookInfo(char *Filename,struct Node *list) {
	FILE* fp = fopen(Filename, "r"); //r模式，读取文件,文件不存在会报错
	if (fp == NULL) {
		fopen("bookInfo.txt", "w"); //文件不存在，先创建文件
		return;
	}
	struct bookInfo temp; //定义一个临时书籍信息结构体变量

	while (fscanf(fp, "%s%f%d", temp.name, &temp.price, &temp.num) != EOF) {
		
		insertBook(list,temp); //将读取的信息插入到初始化之后的链表中，然后继续录入时再插入新的数据到链表头部
	}
	sortBookList(list);
	fclose(fp); //关闭文件
}

//保存书籍信息到文件
void saveBookInfo(char *Filename, struct Node* list) {

	//打开文件
	FILE* fp = fopen(Filename, "w");	//w模式，覆盖原有内容
	if (!fp) return;

	sortBookList(list);

	//写入文件 fprintf
	//定义一个临时节点指针，指向头结点的下一个节点
	struct Node* move = list->next;
	while (move != NULL) { //有多个数据是 move需要不断后移，打印信息，直到move指向NULL
		fprintf(fp, "%s %.1f %d\n", move->data.name, move->data.price, move->data.num);
		move = move->next; //move后移
	}

	//关闭文件
	fclose(fp);
}

//速览书籍信息
void showBookList(struct Node* list) {
	//定义一个临时节点指针，指向头结点的下一个节点
	struct Node* move = list->next;
	while (move != NULL) { //有多个数据是 move需要不断后移，打印信息，直到move指向NULL
		printf("%s %.1f %d\n", move->data.name, move->data.price, move->data.num);
		move = move->next; //move后移
	}
}

//查找书籍信息
struct Node* searchBook(struct Node* list, char* name) {
	struct Node* move = list->next;
	while (move != NULL && strcmp(move->data.name, name)) { //strcmp相等返回0，不等返回非0
		move = move->next; //move后移
	}
	return move; //返回查找到的节点地址，没找到返回NULL
}

//删除书籍信息
void deleteBook(struct Node* list, char* name) {
	struct Node* move = list->next; //定义一个移动节点指针，初始指向头结点的下一个节点
	struct Node* prev = list; //定义一个前驱节点指针，初始指向头结点

	while (move != NULL && strcmp(move->data.name, name)) {
		prev = move; //前驱节点后移
		move = move->next; //move后移
	}

	if (move == NULL) {
		printf("未找到书籍，无法删除\n");
		return;
	}
	else {
		printf("删除成功\n");
		prev->next = move->next; //前驱节点的next指针指向move的下一个节点
		free(move); //释放move节点内存
		move = NULL;
	}
}

//根据输入的数字选择功能
void keyEvent() {
	int key = 0;
	scanf("%d", &key);
	struct bookInfo temp;
	struct Node* result;
	switch (key) {
		case 0:
			printf("[录入] \n");
			printf("录入书籍的书名，数量，价格\n");
			scanf("%s%f%d", temp.name, &temp.price, &temp.num);
			//printf("%s %.1f %d\n", temp.name, temp.price, temp.num);

			//将录入的信息同步到链表
			insertBook(list,temp); //传入头结点和录入的信息
			//同步文件
			saveBookInfo("bookInfo.txt", list); //传入文件名和头结点
			
			break;
		case 1:
			printf("[速览] \n");
			printf("书名，数量，价格\n");
			showBookList(list); //传入头结点
			break;
		//2,3借阅 归还之前先做4 查找书籍
		case 2:
			printf("[借阅] \n");
			printf("请输入借阅书籍的书名\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //传入头结点和书名,查链表，最终查出一个有效数据
			if (result != NULL) {
				if (result->data.num <= 0) {
					printf("库存不足，无法借阅\n");
					break;
				}
				else {
					printf("借阅成功\n");
					result->data.num--; //数量-1
					saveBookInfo("bookInfo.txt", list); //同步文件
				}
			}
			else {
				printf("未找到该书籍\n");
			}
			break;
		case 3:
			printf("[归还] \n");
			printf("请输入归还书籍的书名\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //传入头结点和书名,查链表，最终查出一个有效数据
			if (result != NULL) {
				printf("归还成功\n");
				result->data.num++; //数量+1
				saveBookInfo("bookInfo.txt", list); //同步文件
			}
			else {
				printf("未找到该书籍\n");
			}
			break;
		case 4:
			printf("[查找] \n");
			printf("请输入查找书籍的书名\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //传入头结点和书名,查链表，最终查出一个有效数据
			if (result != NULL) {
				printf("%s %.1f %d\n", result->data.name, result->data.price, result->data.num);
			}
			else {
				printf("未找到该书籍\n");
			}
			break;
		case 5:
			printf("[删除] \n");
			printf("请输入删除书籍的书名\n");
			scanf("%s", temp.name);
			deleteBook(list, temp.name); //传入头结点和书名
			break;
		case 6:
			printf("退出系统\n");
			exit(0);
			break;
		default:
			break;
	}
}



int main() {
	//初始化头部节点
	list = createHead(); //因为每次运行程序，都重新初始化节点指向NULL，所以每次录入都只会保存当前录入的信息，覆盖原有信息
	readBookInfo("bookInfo.txt",list);	//所以每次重新录入信息后，要先读取文件的内容

	while (1) {
		menu();
		keyEvent();

		system("pause");
		system("cls");
	}
	return 0;
}