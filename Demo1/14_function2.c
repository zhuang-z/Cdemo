#include<stdio.h>
#include<stdbool.h>

#include "14_function2.h"  //�����ͷ�ļ������԰Ѻ������Ž�ͷ�ļ����棬��main.c�ļ�������ͷ�ļ������ɽ��е���

//extern void xiaoyou_printf();  //��xiaoyou_printf()����������39�в��ܵ��õ�����(49-51)

//�����ķ���ֵ��������һ������
//1.���û�з���ֵ��void����
//2.��������Ӧ�ĺ�����������Ӧ�Ĺؼ��ֽ��ж��� int double char

//int isPrime(int n) {  //�ж��ǲ�������
//	int i;
//	for (i = 2; i <= n / 2; i++) {
//		if (n % i == 0) {
//			/*printf("%d��������\n",n);
//			break; //����forѭ����ִ��֮������ */    
//
//			return false;  //������������Ļ�������һ��false��ֱ���ж�����������false��������Ҳ������ִ�У�
//		}
//	}
//
//	/*if (i > n / 2) {
//		printf("%d������\n", n);
//	}*/
//	
//	return true;  //���������������Ļ���û�����if��䣬�ͷ���һ��true
//}



int main() {

	int a;
	for (a = 300; a < 500; a++) {   //1.�ж�300-500֮������ǲ�������   2.�ҳ�300-500֮�������
		if (isPrime(a)) {  //���ú����õ����ص�ֵ����true����false�������ֵ�����ж��ٴ�ӡ�����
			printf("%d\n", a);
		};  
	}

	xiaoyou_printf();

	return 0; //main�����ķ���ֵ�����ٱ��������ã����Ծ�return 0��
}


// ������main����֮�󣬳����մ��ϵ���ִ�У����Ҫ��main���������ܹ�ִ��xiaoyou_printf()����
// ��Ҫ��main������к���������,���߰Ѻ���д������.c�ļ���Ȼ���½�һ��ͷ�ļ���ͷ�ļ��Ժ�������������Ȼ���ͷ�ļ��������ã�ͷ�ļ����ֿ����Զ���
// #include "functionY"
// extern void xiaoyou_printf();
//void xiaoyou_printf() {   
//	printf("Hello xiaoyou!");
//}