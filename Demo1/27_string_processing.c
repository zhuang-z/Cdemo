#include<stdio.h>
#include<stdlib.h>
#include<string.h> //�ַ����������Ŀ�
void split(char* str, char *p, char** splitstr);
//���߱����������ü�鰲ȫ��
//#pragma warning(diasble:4996)  4996�Ǵ�����
int main() {
	char* p1 = (char*)malloc(100);
	char* str = "xiaoyouzi";

	// p =str; //strֱ�Ӹ�ֵ��p��str�õ������ַ����ĵ�ַ��p��ָ���ַ����ģ�����p�����100���ڴ�ռ�ûʹ��
	//if (!p) return;
	//for(int i = 0; i < 9; i++){
	//	p[i] = str[i]; //����
	//}

	//printf("%s", p);

	//1.strcpy_s������strcpy_s(Ŀ���ַ���ֽ�����Դ��ַ)
	if (!p1) return;
	strcpy_s(p1, 10, str);  //�ַ�������Ҫ��Ӧ,�����"\0"
	printf("%s\n", p1);
	//free(p1);

	//2.strlen������strlen�������ַ����ַ��ĸ�����������"\0"
	printf("%zd\n", strlen(p1));   //��ӡstrlen��Ҫ��%zd
	free(p1);

	char* p2 = (char*)malloc(100);
	if (!p2) return;
	strcpy_s(p2, strlen(str)+1, str); //strlen������"\0",Ҫ��1
	printf("%s\n", p2);
	free(p2);

	//3.strncpy_s:�����ַ�����ǰ���ٸ��ַ�
	char* p3 = (char*)malloc(100);
	if (!p3) return;
	strncpy_s(p3,strlen(str)+1,str,4); //���Ĳ����Ƕ���λ,�����λ�����������ַ�����Сʱ,����������������
	/*for (int i = 0; i < 15; i++){
		printf("%d\n", p3[i]);
	}*/
	printf("%s\n", p3);
	free(p3);

	//4.strcat_s:�ַ���׷�Ӻ�������ԭ�е��ַ���׷���ַ����������ַ�������������ʹ��strcpy��strcat��Щ���������ܸ����µ��ַ�����ռ���Ѿ�������ַ��������ĵط���Ҳ�������ַ�������׷��
	char* p4 = (char*)malloc(120);
	if (!p4) return;
	char* str1 = "����/Ůʿ";

	scanf_s("%s", p4, 100);
	strcat_s(p4, 120, str1); //120:�����ַ���֮��Ĵ�С������������ڴ�ռ��С
	printf("%s\n", p4);
	strncat_s(p4, 120, str1, 2); //2��ʾ�����ֽڵĴ�С
	printf("%s\n", p4);
	free(p4);

	/*char *mystr = "xiaoyouzi"
	  strcat_s(mystr,120,str1);
	  printf("%s",mystr); //������⣬��Ϊ��mystr��������ַ��������������ܸ���
	*/

	//5.strcmp strncmp:�ַ����ȽϺ���
	char* p5 = "abc";
	char* p5_1 = "abd";
	char* p5_2 = "abb";
	char* p5_3 = "abc";
	printf("%d\n",strcmp(p5, p5_1));
	printf("%d\n", strcmp(p5, p5_2));
	printf("%d\n", strcmp(p5, p5_3));
	printf("%d\n", strncmp(p5, p5_1,3));  //�Ƚ�p5 �� p5_1��ǰ�����ַ���С

	//Ӧ�ã�ע���˺�ʱ����һ����������͵ڶ������������Ƿ�һ��

	char* p5_4 = (char*)malloc(100);
	char* p5_5 = (char*)malloc(100);
	if (!p5_4 || !p5_5) return;
	scanf_s("%s", p5_4, 100);
	scanf_s("%s", p5_5, 100);
	if (strcmp(p5_4, p5_5) == 0) {
		printf("������ȷ\n");
	}
	else {
		printf("�������벻һ��\n");
	}
	free(p5_4);
	free(p5_5);

	//6.strchr strstr strrchr():�ж��ַ��Ƿ����ַ����У�ģ������
	char* p6_1 = "xiaoyouzi";
	char* p6_2 = strchr(p6_1, 'i');  //strchr,ֻ��ƥ��鵽�ĵ�һ���ַ�
	char* p6_3 = strrchr(p6_1, 'i');
	printf("%p\n", p6_1);
	printf("%p\n", p6_2);
	printf("%d\n", (int)(p6_3 - p6_1));

	char* p6_4[] = { "youzi","yoyo","goudan" };
	char p6_5 = 0;
	
	/*������scanf_s("%s", p4, 100);��scanf_s("%s", p5_4, 100);
	�Լ�scanf_s("%s", p5_5, 100);֮�����뻺�������ܻ�������з����ַ���
	�����һ��������scanf_s("%c", &p6_5, 1);��������з����ܻᱻ�������ֱ�Ӷ�ȡ��
	���³���û�еȴ��û������µ��ַ���*/
	int c;
	while ((c = getchar()) != '\n' && c != EOF); //������뻺�����еĲ����ַ�

	printf("��������Ҫ���ҵ�ģ���ַ���\n");
	scanf_s("%c", &p6_5, 1);  //strchrֻ�ܶ��ַ����ң���������ֻ����1���ַ�
	for (int i = 0; i < sizeof(p6_4) / sizeof(char*); i++) {
		if (strchr(p6_4[i], p6_5) !=NULL) {
			printf("%s\n", p6_4[i]);
		}
	}


	while ((c = getchar()) != '\n' && c != EOF); //������뻺�����еĲ����ַ�

	char* p6_6[] = { "youzi","yoyo","goudan","gouzi"};
	char p6_7[100];

	printf("��������Ҫ���ҵ�ģ���ַ�����\n");
	scanf_s("%s", &p6_7,100);  //strchrֻ�ܶ��ַ����ң���������ֻ����1���ַ�

	//��p7_2�����ַ���ƴ��
	strcat_s(p6_7,100, "");
	for (int i = 0; i < sizeof(p6_6) / sizeof(char*); i++) {
		if (strstr(p6_6[i], p6_7) != NULL) {  //strstr������'\0',���Ҫ�����ַ�����ƴ��
			printf("%s\n", p6_6[i]);
		}
	}


	//7.strtok:�ַ����и� strtokֻ�������������ַ����ͷָ���
	//  strtok_s(�ַ���,�ָ���,������)
	char p7_1[100] = "����|ƺɽ|����԰,aaa,ccc"; //������char *p7_1 = "����|ƺɽ|����԰";ָ����ַ�������;
	//��ʹ��strtok_s�Ⱥ�����Ҫ�޸��ַ�������ʱ��
	//����ʹ��ָ���ַ���������ָ�룬��Ӧ��ʹ���ַ�������߶�̬����Ŀ��޸��ڴ�ռ䡣
	char* splitstr[100];

	//char* buf = NULL;  //�趨ָ����ȡ��ַ������ָ��
	//splitstr[0] = strtok_s(p7_1, "|", &buf); //�и�֮��Ҫ�����ָ������������,��strtokֻ����һ��
	////printf("%s\n", splitstr[0]);
	////���������и�
	//int i1 = 0;
	//while (splitstr[i1]) {
	//	i1++;
	//	splitstr[i1] = strtok_s(NULL, "|", &buf);//����һ���и�ĵط������и�
	//}

	//��split�������ã�
	split(p7_1, "|,", splitstr);  //strtok�Էָ������Զ�����

	//��ӡ
	int m = 0;
	while (splitstr[m]) {
		printf("%s\n", splitstr[m]);
		m++;
	}


	return 0;
}

void split(char *str,char *p,char **splitstr) {  //�ַ�������ָ����գ��ַ���Ҳ��ָ����գ�ָ�������ö���ָ�����
	char* buf = NULL;  //�趨ָ����ȡ��ַ������ָ��
	splitstr[0] = strtok_s(str, p, &buf); //�и�֮��Ҫ�����ָ������������,��strtokֻ����һ��
	//printf("%s\n", splitstr[0]);
	//���������и�
	int i = 0;
	while (splitstr[i]) {
		i++;
		splitstr[i] = strtok_s(NULL, p, &buf);//����һ���и�ĵط������и�
	}
}