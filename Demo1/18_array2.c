#include<stdio.h>

int main() {
	
	//�б���ָ��
	int a[][3] = {  
		{100,99,98},
		{98,90},
		{88,83,70}
	};

	for (int i = 0; i < sizeof(a) / (sizeof(int) * 3); i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", a[i][j]);
		}
	}


	//�б���ָ��������д��һ��
	char str[][100] = { "xiaoyou","tiechui","goudan","����ʦ" };

	for (int i = 0; i < sizeof(str) / (sizeof(char) * 100); i++) {  //���ݵĴ�С/�������͵��ֽ���/���� ==����
		printf("%s\n", str[i]);   //��ӡ�ַ���
	}
	printf("%c\n", str[1][3]);  //��ӡ�ַ�

	return 0;
}