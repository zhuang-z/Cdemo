#include<stdio.h>
#include<string.h>

int main() {

	//rewind�������ļ�ָ������ָ���ļ���ͷ
	/*fseek�������ļ�ָ������ָ���ļ���ĳ��λ�ã���3����������һ���������ļ�ָ�룬�ڶ���������ƫ��������������������ʼλ�ã�
	 ��ʼλ���������궨�壬SEEK_SET(�ļ���ͷ) 0��SEEK_CUR(��ǰλ��) 1��SEEK_END(�ļ�ĩβ) 2*/
	 //ftell���������ļ�ָ�뵱ǰλ�þ����ļ���ͷ���ֽ���

	 //��վע�� ��¼��ֻע�����룬��¼ʱ�������룬���ļ������ݿ�����ȡ��������жԱ� ��֤�����Ƿ���ȷ
	char password[7] = "";
	printf("ע�����룺");
	scanf_s("%s", password, 7); //����ע������

	//������������ַ���д���ļ�
	FILE* fp;
	int error = fopen_s(&fp, "password.txt", "w+");
	if (error != 0) {
		printf("open failed!\n");
		return;
	}

	fputs(password, fp); //������д���ļ�

	int length = ftell(fp); //��ȡ�ļ�ָ�뵱ǰλ�þ����ļ���ͷ���ֽ���
	printf("%d\n", length);
	if(length == 6){
		printf("ע��ɹ�\n");
	}
	else {
		printf("ע��ʧ��\n");
		return;
	}

	/*
	if (password[0] != '\0') { //�ж������Ƿ�Խ�磬Խ��Ϊ����ע��ʧ�ܣ����涼��ִ��
		printf("ע��ɹ�\n");
	}
	else {
		printf("ע��ʧ��\n");
		return;
	}*/

	//��¼
	printf("��¼���룺");
	scanf_s("%s", password, 7); //�����¼���� ֱ�Ӹ���password֮ǰ������ռ�

	char password_db[7] = "";
	//rewind(fp); //���ļ�ָ������ָ���ļ���ͷ

	//fseek(fp, 0, SEEK_SET); //Ҳ������fseek(fp,0,0)���ļ�ָ������ָ���ļ���ͷ��0��ʾƫ����Ϊ0��0��ʾ���ļ���ͷ��ʼƫ��
	fseek(fp, -6, SEEK_CUR); //�ļ�ָ���ʱ��ĩβ �������������Ҫ��ͷ��ʼ�Ļ����轫ƫ��������Ϊ������-6��ʾ�ӵ�ǰλ����ǰƫ��6���ֽ� 123456
	//fseek(fp, -5, SEEK_END); //�ļ�ָ���ĩβ ����������-5��ʾ���ļ�ĩβ��ǰƫ��5���ֽ� 23456

	fgets(password_db, 7, fp); //���ļ��ж�ȡ���룬��Ϊ�ļ�ָ�����ļ�ĩβ�����Զ�ȡ��������
	printf("%s\n", password_db);

	//�ж������Ƿ���ȷ
	int result = strcmp(password, password_db);//strcmp�Ƚ������ַ�����ASCII�룬ǰ��Ĵ��ں���ķ���������ǰ��ĵ��ں���ķ���0��ǰ������ں���ķ��ظ���
	if (result == 0) {
		printf("��¼�ɹ�\n");
	}
	else {
		printf("��¼ʧ�� %d\n", result);
	}

	return 0;
}