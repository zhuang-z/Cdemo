#include<stdio.h>


int main() {

	//sprintf_s�����ַ���ƴ�Ӵ�ӡ���ڴ���
	char str[100];
	sprintf_s(str, 100, "�𾴵�%s����/Ůʿ", "xiaoyou");
	printf("%s\n", str);

	char time[100];
	sprintf_s(time, 100, "%dʱ %d�� %d��", 22, 10, 40);
	printf("%s\n", time);

	//sscanf_s:�ַ����ָ�
	char* address = "���� ���� ����";
	char straddress[3][100]; //ʹ�ö�ά����������
	sscanf_s(address,"%s %s %s",straddress[0],100, straddress[1],100, straddress[2],100); //100�����ܳ����Ķ�������ֵ,�Կո����ָ
	printf("%s\n", straddress[1]);

	char* address1 = "����|����|����";
	char straddress1[3][100];
	sscanf_s(address1, "%[^|]|%[^|]|%[^|]", straddress1[0], 100, straddress1[1], 100, straddress1[2], 100);  //%s %s %s �ָ�Ļ����address1ȫ��д��straddress1[0]�У�ʣ�µ�������������
	printf("%s", straddress1[0]);
	return 0;
}