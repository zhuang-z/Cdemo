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

	4�������������ɾ������
		(1).ɾ��һ�����ݣ�
			ɾ����һ����pHead����ָ��ͷ����ֱ����pHead->pNext��ֵ��pHead��Ȼ���ԭ����pHead�ͷ�free����
			ɾ��ָ��ĳ��λ�õ����ݣ��м�ɾ���ˣ�ǰһ����nextֱ��ָ���һ�������ݣ���һ���������ǵ�ǰ��λ�õ�pNext��pPre->pNextֱ��ָ��ǰ��pNext
		(2).����һ�����ݣ�
			���ӵ�һ����pNew->pNextָ��ԭ����pHead��pHead��ֵ��pNew��
			����ָ��ĳ��λ�õ����ݣ�
			�������һ����ԭ����pEndָ��pNext���µ�pEndָ��pNew
		

*/

struct student {
	char name[100];
	int iNumber;
	struct student* pNext;
};

int count = 0;

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

		count++;
	}

	return pHead;
}

void Print(struct student* pHead) {
	//ͨ��pHeadһֱָ��pNext��ֵ���ж��Ƿ�Ϊ�գ�Ϊ�վͲ���ӡ��
	struct student* pTemp = pHead;
	printf("�ܹ���%d��ͬѧ\n", count);
	int index = 1;
	while (pTemp != NULL) {
		printf("��%d��ͬѧ����Ϣ\n", index);
		printf("%s,%d\n", pTemp->name, pTemp->iNumber);
		pTemp = pTemp->pNext;
		index++;
	}
}

struct student* DeleteHead(struct student* pHead) {
	struct student* pTemp = pHead; //������ʱָ��ԭ����pHead��pHead���¸�ֵ��Ȼ���ͷ���ʱ��
	pHead = pHead->pNext;
	free(pTemp);
	printf("-------ɾ��֮��---------\n");
	count--;
	return pHead;
}

struct student* InsertHead(struct student* pHead) {
	struct student* pNew;
	pNew = (struct student*)malloc(sizeof(struct student));
	if (!pNew) return NULL;
	scanf_s("%s", pNew->name, 100);
	scanf_s("%d", &pNew->iNumber);

	pNew->pNext = pHead; //pNew��nextָ��ԭ����pHead
	pHead = pNew;   //pHead��pNew����
	count++;
	return pHead;
}

struct student* DeletePosition(struct student* pHead,int index) { //index����λ����Ϣ
	struct student* pTemp = pHead; //������ʱָ��ԭ����pHead��pHead���¸�ֵ��Ȼ���ͷ���ʱ��
	struct student* pPre = pHead;

	if (index == 1) {
		return DeleteHead(pHead);
	}
	for (int i = 1; i < index; i++) { //����index=3����i=1��ʼ�ң�����������i����ѭ����i++��i=2... i=3 ������ѭ���������ҵ�
		pPre = pTemp; //����ѭ����pPre��pTemp���ǣ�һֱ�����λ�õ�pTemp��
		pTemp = pTemp->pNext; // pTempÿ�ζ���pNext���� pHead pHead->pNext (pHead->pNext)->pNext
		//�ҵ�λ��ʱ��pPre�����ǵ�ǰλ�õ���һ����pTemp�������ҵ��ģ�
	}
	//��ѭ����
	pPre->pNext = pTemp->pNext;
	free(pTemp);
	printf("-------ɾ��֮��---------\n");
	count--;
	return pHead;
}

int main() {

	struct student* pHead = Create();
	Print(pHead);

	//ɾ����һ������
	//pHead = DeleteHead(pHead);
	// 
	//ɾ��ָ��λ������
	//pHead = DeletePosition(pHead,3);
	
	//��ӵ�һ������
	pHead = InsertHead(pHead);
	Print(pHead);


	return 0;
}