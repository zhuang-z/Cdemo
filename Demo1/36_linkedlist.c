#include<stdio.h>
#include<stdlib.h>
/*�����ӵ�һ���ڴ�ռ�һֱ���ӵ����һ���ڴ�ռ�
	1�����ȶ���һ���ṹ�壬�ṹ��������������ѧ�������������ͣ�����*pNext��ָ�룬����ָ����һ���ṹ�壻
	2���ֱ�������ָ��������������pHead,pEnd,pNew��
		pNew�������µ��ڴ�ռ䣻
		pHead��ָ��ͷ�������ݣ��Ӵ˾Ͳ���Ҫ�仯��
		pEnd��ָ��ÿ�������ڴ�ռ������
	3���߼���
		(1).pNew����ĵ�һ���ڴ�ռ䣬pHead,pEnd��ָ��pNew��pHead = pEnd = pNew = (struct student*)malloc(sizeof(student));
		(2).pNew������һ���ڴ�ռ䣬Ҳ����pNew->pNextָ����ڴ�ռ���ҪΪNULL����������ռ䣻
			Ȼ��pEnd��pNextҲҪ������һ���ռ䣬Ҳ����pEnd->pNext = pNew;
			���pEndָ���µ�pNew��Ҳ����pEnd = pNew;
			�Դ����ƣ�
*/

struct student {
	char name[100];
	int iNumber;
	struct student* pNext;
};

struct student* Create() { //¼�뺯������pHead
	struct student* pHead = NULL;
	struct student* pEnd, * pNew;
	//pHead���Բ�����ô�縳ֵ
	/*pHead =*/ pEnd = pNew = (struct student*)malloc(sizeof(struct student)); //ָ��ṹ��ָ�룬ת��������ָ��

	if (!pNew) return NULL;//return NULL;ȥ������
	printf("������ѧ�ź�����������ѧ��Ϊ0ʱֹͣ����\n");
	scanf_s("%s", pNew->name, 100);
	scanf_s("%d", &pNew->iNumber);
	//����������ѧ�ţ�����0ʱֹͣ���룬��Ҫ�õ�whileѭ��

	pNew->pNext = NULL;
	if (pNew->iNumber != 0) { //������Ϊ0ʱ��pHead����ֵ������ӡ
		pHead = pNew;
	}

	while (pNew->iNumber != 0) {

		//pNew->iNumber != 0����һ���ռ�Ҫ��������
		pNew = (struct student*)malloc(sizeof(struct student));
		if (!pNew) return NULL;
		//���������¼��
		scanf_s("%s", pNew->name, 100);
		scanf_s("%d", &pNew->iNumber);

		//¼���Ҫ����pEnd->pNext��pEnd��λ��
		//������������0����������Ҳ������Ӹ��жϣ����ǻ��ڽ���ʱ�����ӳ�
		//����Ϊ�����0ʱ��pEnd��pNextû�з����ַ����һ��Ұָ�룬�ʼʱҪ
		//����pNew->pNext = NULL;
		if (pNew->iNumber != 0) {
			pNew->pNext = NULL;
			pEnd->pNext = pNew;
			pEnd = pNew;
		}
	}

	return pHead;
}

void Print(struct student* pHead) {
	//ͨ��pHeadһֱָ��pNext��ֵ���ж��Ƿ�Ϊ�գ�Ϊ�վͲ���ӡ��
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