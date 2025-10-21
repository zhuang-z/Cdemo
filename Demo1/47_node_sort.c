#include<stdio.h>
#include<stdlib.h>

typedef struct Student {  // ѧ����Ϣ�ṹ��
	char name[20];
	float score;
}Stu;

typedef struct _Node {  // ����ڵ�ṹ��
	Stu data;
	struct _Node* next;
}Node;

struct Node* createLink() {
	Node* head = malloc(sizeof(Node)); // 1.����ͷ���
	if (!head) return;
	head->next = NULL; // ͷ����nextָ��ָ��NULL,���洢����
	Node* move = head; // ����һ���ƶ��ڵ�ָ�룬��ʼָ��ͷ��� ,ÿ��¼�����ݺ�moveָ���½ڵ�

	int num;
	printf("������ѧ������:");
	scanf_s("%d", &num);
	// 2.¼��ѧ����Ϣ
	for (int i = 0; i < num; i++) {
		Node* newNode = malloc(sizeof(Node)); //3.����һ���½ڵ�ָ��,ÿ��¼��Ҫ�����ڵ�
		if (!newNode) return;
		newNode->next = NULL; // �½ڵ��nextָ��ָ��NULL
		move->next = newNode; // move��nextָ��ָ���½ڵ�,�����½ڵ�

		printf("�������%d��ѧ���������ͳɼ�:", i + 1);
		scanf_s("%s %f", newNode->data.name, 20, &newNode->data.score);

		move = newNode; // �ƶ�move�ڵ�ָ��ָ���½ڵ�
	}
	return head; // ����ͷ����ַ
}

void outputLink(Node* head){
	Node* move = head->next; // ָ���׽ڵ㣬ͷ��㲻�洢���ݣ��׽ڵ���ͷ������һ���ڵ�
	while (move != NULL) {
		printf("ѧ��������%s���ɼ���%.2f\n", move->data.name, move->data.score);
		move = move->next; // move����
	}
}

// ð������ ��С����
// ÿ�αȽ����ڵ������ڵ㣬���ǰһ���ڵ�ĳɼ����ں�һ���ڵ�ĳɼ����򽻻�������, ����ÿ�αȽϺ����Ľڵ�ᱻ�����������
void bubbleSort(Node* head) {
	Stu temp; // ����һ����ʱ���������ڽ���������
	Node* move = NULL;
	Node* save = NULL;
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next) { // �����ƱȽ�����
		//for (Node* move = head->next; move->next != NULL; move = move->next) { // �ڲ����ÿ�ֱȽϴ���,����ÿ�ζ���Ƚϵ����һ���ڵ�
		for (move = head->next; move->next != save; move = move->next) { // �ڲ����ÿ�ֱȽϴ���,����ÿ��ֻ��Ƚϵ��ϴδ洢�����Ľڵ�
			if (move->data.score > move->next->data.score) { // ���ǰһ���ڵ�ĳɼ�С�ں�һ���ڵ�ĳɼ����򽻻�������
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
		}
			save = move; //ÿ�ֱȽϺ󣬼�¼���һ���ڵ��λ�ã���һ�ֱȽ�ʱ���ٱȽϸýڵ�
	}
}

// �������� ��С����
// ÿ���õ���һ���ڵ�����ݣ���ǰ���Ѿ�����õĽڵ����ݽ��бȽϣ��ҵ����ʵ�λ�ò���
// ����ָ�룬orderMoveָ��ͷ�ڵ㣬disorderMoveָ��ͷ�ڵ��next��next�ڵ�
// �ƶ�ָ����룬��Ҫ֪����ǰdisorderMove��ǰһ���ڵ��λ�ã�������Ҫһ��preָ�룬��ʼָ��head->next,��һ���ڵ��λ�ã���ʼָ��disorderMove->next
// disorderMoveÿ���ƶ���pre�ĵ�ַҪ����ΪdisorderMove
// ÿ�β����disorderMoveָ����һ���ڵ㣬orderMoveָ��ͷ�ڵ㣬���¿�ʼ�Ƚ�
// disorderMoveָ��NULLʱ���������
// ÿ�αȽ�ʱ��orderMove��nextָ��disorderMoveʱ����
// �ȽϺ����Ҫ���룬�ȼ�¼disorderMove����һ���ڵ��λ�ã�Ȼ���disorderMove���뵽pre��orderMove֮��
// disorderMoveָ��preҲ����orderMove��next��orderMove��nextָ��disorderMove��preָ��disorderMove����һ���ڵ㣬
// �����disorderMoveָ��pre
// ��������룬orderMove���ƣ�pre����
void insertSort(Node* head) {
	Node* orderMove = head; // ָ������ڵ���ƶ�ָ�룬��ʼָ��ͷ���(orderMove����ָ��head->next����Ϊ�������disorderMoveҪ����Ļ����޷���֪orderMove����һ���ڵ�ĵ�ַ(�˴���һ���ڵ���ͷ��㣬�����ƶ��Ļ����޷���֪��))
	Node* disorderMove = head->next->next; // ָ������ڵ���ƶ�ָ�룬��ʼָ��ͷ�ڵ��next��next�ڵ�
	Node* pre = head->next; // ָ��disorderMove��ǰһ���ڵ㣬��ʼָ��head->next
	while (disorderMove != NULL) { // disorderMoveָ��NULLʱ���������
		while(orderMove->next != disorderMove){ //�Ƚ�ʱ��orderMove��next���ܵ���disorderMove��ָ�򼴽���
			// ��ʼ�Ƚϣ����С�ģ���ǰ����
			if (orderMove->next->data.score > disorderMove->data.score) {
				Node* back = disorderMove->next; // �ȼ�¼disorderMove����һ���ڵ��λ��
				disorderMove->next = orderMove->next; // disorderMoveָ��preҲ����orderMove��next
				orderMove->next = disorderMove; // orderMove��nextָ��disorderMove
				pre->next = back; // preָ��disorderMove����һ���ڵ�
				disorderMove = pre; // disorderMoveָ��pre
				break; // ���������ѭ����������һ�β���
			}
		// ��������룬orderMove����
		orderMove = orderMove->next; // orderMove����
		}

		// ÿ�β����Ķ��� pre���Ƽ�ָ��disorderMove, disorderMoveָ����һ���ڵ㣬orderMoveָ��ͷ��㣬���¿�ʼ�Ƚ�
		pre = disorderMove; // preָ��disorderMove(�岻���� pre��Ҫ���ƣ���ΪdisorderMove�ں���)
		disorderMove = disorderMove->next; // �ȼ�¼disorderMove����һ���ڵ��λ��
		orderMove = head; // orderMove����ָ��ͷ���
	}

}

// ѡ������ ��С����
// ÿ������С�������Ľڵ㣬�ŵ���һλ
// turn����������ָ��ǰ�׽ڵ�
// minָ��ǰ��С�ڵ㣬��ʼָ���׽ڵ�
// moveָ���׽ڵ����һ���ڵ�
// ÿ�αȽϣ����move�ĳɼ�С��min�ĳɼ�����minָ��move������move����
// �Ƚϵ�moveָ��NULLʱ��˵�����ֱȽϽ���������turn��min��������
void selectSort(Node* head){
	//Node* move = head->next->next;
	//Node* turn = head->next;
	//Node* min = head->next;

	//while (turn->next != NULL) { // ��������
	//	while(move !=NULL){ // ���ƱȽϴ���
	//		if (move->data.score < min->data.score) { // ���move�ĳɼ�С��min�ĳɼ�����minָ��move
	//			min = move;
	//		}
	//		move = move->next; // move����
	//	}
	//	if (turn != min) { // ���turnָ���һ���ڵ�����С�ڵ㣬minҲָ���һ���ڵ�����С�ģ�����Ҫ����
	//		Stu temp = turn->data; // ����turn��min��������
	//		turn->data = min->data;
	//		min->data = temp;
	//	}
	//	turn = turn->next; // turnָ����һ���ڵ�
	//	min = turn; // minָ����һ���ڵ�
	//	move = turn->next; // moveָ����һ���ڵ����һ���ڵ�
	//}

	for(Node* turn = head->next; turn->next!=NULL;turn = turn->next){ // ��������
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
	// Node* move = head->next;  // �ڴ˴���������head->nextΪNULL�������moveָ��NULL������move->data�ᱨ��
	
	while (cur != NULL) { // curָ��ͷ��������ƶ�
		Node* min = cur; // ÿ��ѭ����Ҫ���¶���min��ָ��ǰ�ڵ�
		Node* move = cur->next; // ÿ��ѭ����Ҫ���¶���move��ָ��ǰ�ڵ����һ���ڵ�`
		while (move != NULL) { // moveָ��head->next��������ƶ�
			// �ҵ���С�ڵ�
			if (move->data.score < min->data.score) {
				min = move;
			}
			move = move->next; // move����,��һ�ֱȽϽ���
		}

		// ��������
		if (cur != min) {
			Stu temp = cur->data;
			cur->data = min->data;
			min->data = temp;
		}

		// �������cur����
		cur = cur->next; // cur����,�ڶ��ֱȽϿ�ʼ //��Ϊÿ�ֱȽ�min��move��������cur���¶���ģ�����cur���Ƽ���
	}

}

int main() {
	Node* head = createLink();

	//bubbleSort(head);
	//insertSort(head);
	//selectSort(head);
	selectSort1(head);

	printf("����ѧ���ɼ������Ľ�����£�\n");
	outputLink(head);

	return 0;
}