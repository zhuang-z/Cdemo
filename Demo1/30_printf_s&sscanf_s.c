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
	printf("%s\n", straddress1[0]);

	//sscanf_s:�����÷�
	/*
	* 1���������� %*s %*d 
	  2��ָ����� %8s:���ǰ8���ֽ�
	  3�����ϲ��� %[a-z]:������һ������a-z֮��ľͲ������
				 %[abc]:%[Youzi] ��ȷƥ���ַ���������˳��Ҳ����ƥ��
				 %[^abc]: ^��ʾ�ǣ�������һ��������ľͲ������
	*/

	char* address2 = "���� ���� ������ʰ��ʰ";
	char straddress2[2][100]; //%*s������һ������֮��ֻ��Ҫ�õ���ά���������ռȿɣ�
	sscanf_s(address2, "%*s %s %8s", straddress2[0], 100, straddress2[1], 100);
	printf("%s\n", straddress2[1]);

	char* name = "ouYzi 1999";
	char buf1[100];
	char buf2[100];
	char buf3[100];
	sscanf_s(name, "%[a-z]", buf1, 100); //%[a-z]:������һ������a-z֮��ľͲ������
	sscanf_s(name, "%[Youzi ]", buf2, 100); //% [abc]:%[Youzi] ��ȷƥ���ַ���������˳��Ҳ����ƥ��
	sscanf_s(name, "%[^9]", buf3, 100);//%[^abc]:^ ��ʾ�ǣ�����abc������ַ��������������һ����abc����ľͲ������
	printf("%s\n", buf1);
	printf("%s\n", buf2);
	printf("%s\n", buf3);

	char* address3 = "����|����|����";
	char straddress3[3][100];
	sscanf_s(address3, "%[^|]|%[^|]|%[^|]", straddress3[0], 100, straddress3[1], 100, straddress3[2], 100);  //%s %s %s �ָ�Ļ����address1ȫ��д��straddress1[0]�У�ʣ�µ�������������
	//������һ�о�ʹ�õ� ^ �������������������"ح"�����Ȼ��ح�����治�����"ح"���зָ���Ȼ����ƥ����������������
	printf("%s\n", straddress3[0]);



	return 0;
}