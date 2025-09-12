#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
*	//Ϊ�˴���Ŀ���ֲ�ԣ�ʹ��scanf fopen��������ʹ�� scanf_s fopen_s ���������� #define _CRT_SECURE_NO_WARNINGS
	ͼ�����ϵͳ��
	1�����ն�չʾϵͳ�Ĺ��ܣ�¼���鼮�������鼮�������鼮���黹�鼮�������鼮��ɾ���鼮���˳�ϵͳ��
	2���û���������ѡ���ܣ�
		(1).¼���鼮���������۸�������ͨ���������ʽÿ����ͷ���������鼮��Ϣ��ÿ�ζ�ֱ�Ӹ���ԭ�����ݣ�
		(2).�����鼮����ӡ�����鼮��Ϣ��
		(3).�����鼮�������������ҵ���Ӧ�鼮������-1��������Ϊ0����ʾ��治�㣻
		(4).�黹�鼮�������������ҵ���Ӧ�鼮������+1��
		(5).�����鼮�������������ҵ���Ӧ�鼮����ӡ�鼮��Ϣ��
		(6).ɾ���鼮�������������ҵ���Ӧ�鼮����������ɾ���ýڵ㣬���ͷ��ڴ棻
		(7).�˳�ϵͳ���˳�����
	2-1��
		���ݼ�������֣�ѡ���Ӧ���ܣ�
	2-2��
		����洢�鼮��Ϣ��
		(1).����ṹ��ָ�룬�����鼮��Ϣ(�������۸�����),��ָ����һ�ڵ��ָ�룻
		(2).��ʼ��ͷ��㣬ͷ��㲻�洢�鼮��Ϣ��ֻ�洢ָ����һ�ڵ��ָ�룬ָ��NULL��
		(3).ÿ��¼���鼮��Ϣʱ����ͷ��������½ڵ㣻��NewNode->next = NodeHead->next,NodeHead->next = NewNode;
		(4).��������ͨ����������ʵ�֡�

*/


//�˵�����
void menu() {
	printf("--------------------------\n");
	printf("0.¼���鼮\n");
	printf("1.�����鼮\n");
	printf("2.�����鼮\n");
	printf("3.�黹�鼮\n");
	printf("4.�����鼮\n");
	printf("5.ɾ���鼮\n");
	printf("6.�˳�ϵͳ\n");
	printf("--------------------------\n");
	printf("������(0-6):\n");
}

//¼���鼮
//�鼮��Ϣ�ṹ��
struct bookInfo {
	char name[100];
	float price;
	int num;
};

//����ڵ�ṹ��
struct Node {
	struct bookInfo data;
	struct Node* next;
};

//��������ͷ�ڵ�
struct Node* list = NULL;

struct Node* createHead() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	if (!headNode) return;
	headNode->next = NULL; //ͷ������nextָ��ָ��NULL�����鼮��Ϣ

	return headNode; //����ͷ����ַ
}

//����¼�����Ϣ����������ڵ�
struct Node* createNode(struct bookInfo data) {
	//�½�����ڵ�
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) return;
	newNode->data = data; //��¼�����Ϣ��ֵ���½ڵ�
	newNode->next = NULL; //�½ڵ��nextָ��ָ��NULL
	return newNode; //�����½ڵ��ַ
}

//����������Ϣ��ͷ��
void insertBook(struct Node* headNode, struct bookInfo data) {

	struct Node* newNode = createNode(data); //�����½ڵ�

	//���½ڵ���뵽ͷ���
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//���������ݽ�������
void sortBookList(struct Node* list) {
	//ð��������������ݣ��洢���ļ���
	struct Node* move = list->next;
	struct Node* sort = list->next;
	struct bookInfo temp; //����һ����ʱ��������������
	struct Node* save = NULL; //����һ����ʱ�ڵ�ָ�룬ָ�����һ���Ѿ�����õĽڵ�,�Ƚ�һ�ֺ󱣴����һ���ڵ��λ��
	for (sort = list->next; sort->next != NULL; sort = sort->next) {  //���ƱȽ�����
		//for (move = list->next; move->next != NULL; move = move->next) { //move���׽ڵ㿪ʼ�����ƶ��Ƚ� ʵ��ÿһ�ֶ���ͷ���Ƚϵ����
		for(move = list->next; move->next != save; move= move->next){
			if (strcmp(move->data.name, move->next->data.name) > 0) {
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
		}
		save = move; //�������һ���Ѿ�����õĽڵ�λ��
	}
}

//��ȡ�ļ��е��鼮��Ϣ������
void readBookInfo(char *Filename,struct Node *list) {
	FILE* fp = fopen(Filename, "r"); //rģʽ����ȡ�ļ�,�ļ������ڻᱨ��
	if (fp == NULL) {
		fopen("bookInfo.txt", "w"); //�ļ������ڣ��ȴ����ļ�
		return;
	}
	struct bookInfo temp; //����һ����ʱ�鼮��Ϣ�ṹ�����

	while (fscanf(fp, "%s%f%d", temp.name, &temp.price, &temp.num) != EOF) {
		
		insertBook(list,temp); //����ȡ����Ϣ���뵽��ʼ��֮��������У�Ȼ�����¼��ʱ�ٲ����µ����ݵ�����ͷ��
	}
	sortBookList(list);
	fclose(fp); //�ر��ļ�
}

//�����鼮��Ϣ���ļ�
void saveBookInfo(char *Filename, struct Node* list) {

	//���ļ�
	FILE* fp = fopen(Filename, "w");	//wģʽ������ԭ������
	if (!fp) return;

	sortBookList(list);

	//д���ļ� fprintf
	//����һ����ʱ�ڵ�ָ�룬ָ��ͷ������һ���ڵ�
	struct Node* move = list->next;
	while (move != NULL) { //�ж�������� move��Ҫ���Ϻ��ƣ���ӡ��Ϣ��ֱ��moveָ��NULL
		fprintf(fp, "%s %.1f %d\n", move->data.name, move->data.price, move->data.num);
		move = move->next; //move����
	}

	//�ر��ļ�
	fclose(fp);
}

//�����鼮��Ϣ
void showBookList(struct Node* list) {
	//����һ����ʱ�ڵ�ָ�룬ָ��ͷ������һ���ڵ�
	struct Node* move = list->next;
	while (move != NULL) { //�ж�������� move��Ҫ���Ϻ��ƣ���ӡ��Ϣ��ֱ��moveָ��NULL
		printf("%s %.1f %d\n", move->data.name, move->data.price, move->data.num);
		move = move->next; //move����
	}
}

//�����鼮��Ϣ
struct Node* searchBook(struct Node* list, char* name) {
	struct Node* move = list->next;
	while (move != NULL && strcmp(move->data.name, name)) { //strcmp��ȷ���0�����ȷ��ط�0
		move = move->next; //move����
	}
	return move; //���ز��ҵ��Ľڵ��ַ��û�ҵ�����NULL
}

//ɾ���鼮��Ϣ
void deleteBook(struct Node* list, char* name) {
	struct Node* move = list->next; //����һ���ƶ��ڵ�ָ�룬��ʼָ��ͷ������һ���ڵ�
	struct Node* prev = list; //����һ��ǰ���ڵ�ָ�룬��ʼָ��ͷ���

	while (move != NULL && strcmp(move->data.name, name)) {
		prev = move; //ǰ���ڵ����
		move = move->next; //move����
	}

	if (move == NULL) {
		printf("δ�ҵ��鼮���޷�ɾ��\n");
		return;
	}
	else {
		printf("ɾ���ɹ�\n");
		prev->next = move->next; //ǰ���ڵ��nextָ��ָ��move����һ���ڵ�
		free(move); //�ͷ�move�ڵ��ڴ�
		move = NULL;
	}
}

//�������������ѡ����
void keyEvent() {
	int key = 0;
	scanf("%d", &key);
	struct bookInfo temp;
	struct Node* result;
	switch (key) {
		case 0:
			printf("[¼��] \n");
			printf("¼���鼮���������������۸�\n");
			scanf("%s%f%d", temp.name, &temp.price, &temp.num);
			//printf("%s %.1f %d\n", temp.name, temp.price, temp.num);

			//��¼�����Ϣͬ��������
			insertBook(list,temp); //����ͷ����¼�����Ϣ
			//ͬ���ļ�
			saveBookInfo("bookInfo.txt", list); //�����ļ�����ͷ���
			
			break;
		case 1:
			printf("[����] \n");
			printf("�������������۸�\n");
			showBookList(list); //����ͷ���
			break;
		//2,3���� �黹֮ǰ����4 �����鼮
		case 2:
			printf("[����] \n");
			printf("����������鼮������\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //����ͷ��������,���������ղ��һ����Ч����
			if (result != NULL) {
				if (result->data.num <= 0) {
					printf("��治�㣬�޷�����\n");
					break;
				}
				else {
					printf("���ĳɹ�\n");
					result->data.num--; //����-1
					saveBookInfo("bookInfo.txt", list); //ͬ���ļ�
				}
			}
			else {
				printf("δ�ҵ����鼮\n");
			}
			break;
		case 3:
			printf("[�黹] \n");
			printf("������黹�鼮������\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //����ͷ��������,���������ղ��һ����Ч����
			if (result != NULL) {
				printf("�黹�ɹ�\n");
				result->data.num++; //����+1
				saveBookInfo("bookInfo.txt", list); //ͬ���ļ�
			}
			else {
				printf("δ�ҵ����鼮\n");
			}
			break;
		case 4:
			printf("[����] \n");
			printf("����������鼮������\n");
			scanf("%s", temp.name);
			result = searchBook(list, temp.name); //����ͷ��������,���������ղ��һ����Ч����
			if (result != NULL) {
				printf("%s %.1f %d\n", result->data.name, result->data.price, result->data.num);
			}
			else {
				printf("δ�ҵ����鼮\n");
			}
			break;
		case 5:
			printf("[ɾ��] \n");
			printf("������ɾ���鼮������\n");
			scanf("%s", temp.name);
			deleteBook(list, temp.name); //����ͷ��������
			break;
		case 6:
			printf("�˳�ϵͳ\n");
			exit(0);
			break;
		default:
			break;
	}
}



int main() {
	//��ʼ��ͷ���ڵ�
	list = createHead(); //��Ϊÿ�����г��򣬶����³�ʼ���ڵ�ָ��NULL������ÿ��¼�붼ֻ�ᱣ�浱ǰ¼�����Ϣ������ԭ����Ϣ
	readBookInfo("bookInfo.txt",list);	//����ÿ������¼����Ϣ��Ҫ�ȶ�ȡ�ļ�������

	while (1) {
		menu();
		keyEvent();

		system("pause");
		system("cls");
	}
	return 0;
}