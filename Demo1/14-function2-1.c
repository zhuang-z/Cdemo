#include<stdio.h>
#include<stdbool.h>
void xiaoyou_printf() {
	printf("Hello xiaoyou!");
}

int isPrime(int n) {  //�ж��ǲ�������
	int i;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			/*printf("%d��������\n",n);
			break; //����forѭ����ִ��֮������ */

			return false;  //������������Ļ�������һ��false��ֱ���ж�����������false��������Ҳ������ִ�У�
		}
	}

	/*if (i > n / 2) {
		printf("%d������\n", n);
	}*/

	return true;  //���������������Ļ���û�����if��䣬�ͷ���һ��true
}