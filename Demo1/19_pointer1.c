#include<stdio.h>

void xiaoyou_scanf(int *p) {  //�βν���ʵ�εĵ�ַ

	printf("%p\n", p);

	//����b��1000��int *p����b�ĵ�ַ��p����b�ĵ�ַ��*p����b��ַ��ֵ

	*p = 1000;
}

int main() {
	
	int a = 100;
	printf("%d\n", a);  //��ӡa��ֵ
	printf("%p\n", &a);  //%p  &a  �Ǵ�ӡa�ĵ�ַ
	// printf("%d\n", &a); ��ӡ��ַʱ��%d,����ʾ��int *���ж��壬
	// ��ָ����ж��壬ָ���Ǵ���һ��ֵ���ڴ��ַ�ı���

	int* p = &a;   //int *p��������a�ĵ�ַ��*�Ű���int���߰���p��û��ϵ����������p�ģ�p���ǵ�ַ��*p����a��ֵ
	printf("%p\n", p);

	char name[1] = {'xiao'};
	printf("%s\n", name);  
	printf("%p\n", name);  //����������ԣ����������ǵ�ַ

	//дһ��scanf_s���Ƶĺ���
	int b;   //����b���õ�b��ֵ
	printf("%p\n",&b);  //��ַ�ͺ�����ĵ�ַһ��
	xiaoyou_scanf(&b);  //ʵ�λ�ȡb�ĵ�ַ��

	printf("%d\n", b);

	return 0;
}