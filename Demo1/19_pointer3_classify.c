#include<stdio.h>

int main() {

	//指针的分类 
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
	//int占4个字节，赋值会修改所有的字节，直接赋值成0

	//printf("%x\n", i);   //十六进制%x打印
	
	char* ip2 = (char *) &i;  //强制类型转换，

	*ip2 = 0;   //char只占1个字节，赋值只会修改最后两位,1个字节是2位  1个字节=8bit，2^8=256 0-255 十六进制等于ff 15*16+15 = 255 所以1个字节占2位
	//所以指针类型不能混用，修改的权限不一样，int修改4个字节，char修改一个字节
	printf("%x\n", i);   //十六进制%x打印
	

	int arr[] = { 11,22,33 };
	char* p = arr;
	printf("%p\n", arr);
	printf("%p\n", p);
	printf("%p\n", p + 1); //取不到22的地址，因为是int类型需要加4，充分说明指针类型不能混用，会造成地址的记忆混乱和修改困难

	char ch1[] = { 'x','i','a','o','y','o','u' };
	char* ch2 = ch1;
	printf("%p\n", ch2);   //可读，但是不可通过*(ch2+1) = '字符'来赋值，不可写
	/*char *ch2 ="xiaoyou";  char *ch3="xiaoyou";   ch2和ch3的地址都是xiaoyou的地址，不会开辟新的空间来存xiaoyou这个字符串，比数组节省空间   */


	return 0;
}