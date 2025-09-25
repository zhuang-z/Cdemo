#include<stdio.h>
#include<stdlib.h>

typedef struct Student {  // 学生信息结构体
	char name[20];
	float score;
}Stu;

typedef struct _Node {  // 链表节点结构体
	Stu data;
	struct _Node* next;
}Node;

struct Node* createLink() {
	Node* head = malloc(sizeof(Node)); // 1.创建头结点
	if (!head) return;
	head->next = NULL; // 头结点的next指针指向NULL,不存储数据
	Node* move = head; // 定义一个移动节点指针，初始指向头结点 ,每次录入数据后，move指向新节点

	int num;
	printf("请输入学生人数:");
	scanf_s("%d", &num);
	// 2.录入学生信息
	for (int i = 0; i < num; i++) {
		Node* newNode = malloc(sizeof(Node)); //3.定义一个新节点指针,每次录入要新增节点
		if (!newNode) return;
		newNode->next = NULL; // 新节点的next指针指向NULL
		move->next = newNode; // move的next指针指向新节点,链接新节点

		printf("请输入第%d个学生的姓名和成绩:", i + 1);
		scanf_s("%s %f", newNode->data.name, 20, &newNode->data.score);

		move = newNode; // 移动move节点指针指向新节点
	}
	return head; // 返回头结点地址
}

void outputLink(Node* head){
	Node* move = head->next; // 指向首节点，头结点不存储数据，首节点是头结点的下一个节点
	while (move != NULL) {
		printf("学生姓名：%s，成绩：%.2f\n", move->data.name, move->data.score);
		move = move->next; // move后移
	}
}

// 冒泡排序 从小到大
// 每次比较相邻的两个节点，如果前一个节点的成绩大于后一个节点的成绩，则交换数据域, 这样每次比较后，最大的节点会被交换到最后面
void bubbleSort(Node* head) {
	Stu temp; // 定义一个临时变量，用于交换数据域
	Node* move = NULL;
	Node* save = NULL;
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next) { // 外层控制比较轮数
		//for (Node* move = head->next; move->next != NULL; move = move->next) { // 内层控制每轮比较次数,这样每次都会比较到最后一个节点
		for (move = head->next; move->next != save; move = move->next) { // 内层控制每轮比较次数,这样每次只会比较到上次存储的最大的节点
			if (move->data.score > move->next->data.score) { // 如果前一个节点的成绩小于后一个节点的成绩，则交换数据域
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
		}
			save = move; //每轮比较后，记录最后一个节点的位置，下一轮比较时不再比较该节点
	}
}

// 插入排序 从小到大
// 每次拿到后一个节点的数据，和前面已经排序好的节点数据进行比较，找到合适的位置插入
// 两个指针，orderMove指向头节点，disorderMove指向头节点的next的next节点
// 移动指针插入，需要知道当前disorderMove的前一个节点的位置，所以需要一个pre指针，初始指向head->next,后一个节点的位置，初始指向disorderMove->next
// disorderMove每次移动，pre的地址要更新为disorderMove
// 每次插入后，disorderMove指向下一个节点，orderMove指向头节点，重新开始比较
// disorderMove指向NULL时，排序结束
// 每次比较时，orderMove的next指向disorderMove时结束
// 比较后，如果要插入，先记录disorderMove的下一个节点的位置，然后把disorderMove插入到pre和orderMove之间
// disorderMove指向pre也就是orderMove的next，orderMove的next指向disorderMove，pre指向disorderMove的下一个节点，
// 插入后，disorderMove指向pre
// 如果不插入，orderMove后移，pre后移
void insertSort(Node* head) {
	Node* orderMove = head; // 指向有序节点的移动指针，初始指向头结点(orderMove不能指向head->next，因为如果后续disorderMove要插入的话，无法得知orderMove的上一个节点的地址(此处上一个节点是头结点，后续移动的话就无法得知了))
	Node* disorderMove = head->next->next; // 指向无序节点的移动指针，初始指向头节点的next的next节点
	Node* pre = head->next; // 指向disorderMove的前一个节点，初始指向head->next
	while (disorderMove != NULL) { // disorderMove指向NULL时，排序结束
		while(orderMove->next != disorderMove){ //比较时，orderMove的next不能等于disorderMove，指向即结束
			// 开始比较，如果小的，往前插入
			if (orderMove->next->data.score > disorderMove->data.score) {
				Node* back = disorderMove->next; // 先记录disorderMove的下一个节点的位置
				disorderMove->next = orderMove->next; // disorderMove指向pre也就是orderMove的next
				orderMove->next = disorderMove; // orderMove的next指向disorderMove
				pre->next = back; // pre指向disorderMove的下一个节点
				disorderMove = pre; // disorderMove指向pre
				break; // 插入后跳出循环，进行下一次插入
			}
		// 如果不插入，orderMove后移
		orderMove = orderMove->next; // orderMove后移
		}

		// 每次插入后的动作 pre后移即指向disorderMove, disorderMove指向下一个节点，orderMove指向头结点，重新开始比较
		pre = disorderMove; // pre指向disorderMove(插不插入 pre都要后移，因为disorderMove在后移)
		disorderMove = disorderMove->next; // 先记录disorderMove的下一个节点的位置
		orderMove = head; // orderMove重新指向头结点
	}

}

// 选择排序 从小到大
// 每次找最小或者最大的节点，放到第一位
// turn控制轮数，指向当前首节点
// min指向当前最小节点，初始指向首节点
// move指向首节点的下一个节点
// 每次比较，如果move的成绩小于min的成绩，则min指向move，否则move后移
// 比较到move指向NULL时，说明本轮比较结束，交换turn和min的数据域
void selectSort(Node* head){
	//Node* move = head->next->next;
	//Node* turn = head->next;
	//Node* min = head->next;

	//while (turn->next != NULL) { // 控制轮数
	//	while(move !=NULL){ // 控制比较次数
	//		if (move->data.score < min->data.score) { // 如果move的成绩小于min的成绩，则min指向move
	//			min = move;
	//		}
	//		move = move->next; // move后移
	//	}
	//	if (turn != min) { // 如果turn指向第一个节点是最小节点，min也指向第一个节点是最小的，则不需要交换
	//		Stu temp = turn->data; // 交换turn和min的数据域
	//		turn->data = min->data;
	//		min->data = temp;
	//	}
	//	turn = turn->next; // turn指向下一个节点
	//	min = turn; // min指向下一个节点
	//	move = turn->next; // move指向下一个节点的下一个节点
	//}

	for(Node* turn = head->next; turn->next!=NULL;turn = turn->next){ // 控制轮数
		for (Node* move = turn->next; move != NULL; move = move->next) {
			Node* min = turn;
			if (move->data.score < min->data.score) {
				min = move;
			}
			if (turn != min) {
				Stu temp = turn->data;
				turn->data = min->data;
				min->data = temp;
			}
		}
	}
}

void selectSort1(Node* head) {
	Node* cur = head;
	// Node* min = cur;
	// Node* move = head->next;  // 在此处定义会出现head->next为NULL的情况，move指向NULL，后续move->data会报错
	
	while (cur != NULL) { // cur指向头依次向后移动
		Node* min = cur; // 每次循环都要重新定义min，指向当前节点
		Node* move = cur->next; // 每次循环都要重新定义move，指向当前节点的下一个节点`
		while (move != NULL) { // move指向head->next依次向后移动
			// 找到最小节点
			if (move->data.score < min->data.score) {
				min = move;
			}
			move = move->next; // move后移,第一轮比较结束
		}

		// 交换数据
		if (cur != min) {
			Stu temp = cur->data;
			cur->data = min->data;
			min->data = temp;
		}

		// 交换完后cur后移
		cur = cur->next; // cur后移,第二轮比较开始 //因为每轮比较min和move都是依据cur重新定义的，所以cur后移即可
	}

}

int main() {
	Node* head = createLink();

	//bubbleSort(head);
	//insertSort(head);
	//selectSort(head);
	selectSort1(head);

	printf("根据学生成绩排序后的结果如下：\n");
	outputLink(head);

	return 0;
}