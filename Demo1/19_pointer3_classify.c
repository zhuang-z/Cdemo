#include<stdio.h>

int main() {

	//ָ��ķ��� 
	int a = 100;
	int* ap = &a;
	*ap = 10;

	float b = 1.1f;
	float* bp = &b;
	*bp = 1.2f;

	char c = 'k';
	char* cp = &c;
	*cp = 'n';

	printf("%d\n", a);
	printf("%p\n", ap);

	printf("%f\n", b);
	printf("%p\n", bp);

	printf("%c\n", c);
	printf("%p\n", cp);

	int i = 0x11223344;

	//int* ip1 = &i;

	//*ip1 = 0; 
	//intռ4���ֽڣ���ֵ���޸����е��ֽڣ�ֱ�Ӹ�ֵ��0

	//printf("%x\n", i);   //ʮ������%x��ӡ
	
	char* ip2 = (char *) &i;  //ǿ������ת����

	*ip2 = 0;   //charֻռ1���ֽڣ���ֵֻ���޸������λ,1���ֽ���2λ  1���ֽ�=8bit��2^8=256 0-255 ʮ�����Ƶ���ff 15*16+15 = 255 ����1���ֽ�ռ2λ
	//����ָ�����Ͳ��ܻ��ã��޸ĵ�Ȩ�޲�һ����int�޸�4���ֽڣ�char�޸�һ���ֽ�
	printf("%x\n", i);   //ʮ������%x��ӡ
	

	int arr[] = { 11,22,33 };
	char* p = arr;
	printf("%p\n", arr);
	printf("%p\n", p);
	printf("%p\n", p + 1); //ȡ����22�ĵ�ַ����Ϊ��int������Ҫ��4�����˵��ָ�����Ͳ��ܻ��ã�����ɵ�ַ�ļ�����Һ��޸�����

	char ch1[] = { 'x','i','a','o','y','o','u' };
	char* ch2 = ch1;
	printf("%p\n", ch2);   //�ɶ������ǲ���ͨ��*(ch2+1) = '�ַ�'����ֵ������д
	/*char *ch2 ="xiaoyou";  char *ch3="xiaoyou";   ch2��ch3�ĵ�ַ����xiaoyou�ĵ�ַ�����Ὺ���µĿռ�����xiaoyou����ַ������������ʡ�ռ�   */


	return 0;
}