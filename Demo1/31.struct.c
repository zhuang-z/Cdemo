#include<stdio.h>
#include<string.h>
//struct  �ṹ��
//��һ�ֶ���ṹ��ķ�ʽ������ʱ����дȫ
struct student {
	char name[100];
	int age;
};

//�ڶ��֣��������ͺͱ�������һ��
struct person {
	char name[100];
	int age;
}person0, person1;

//�����֣�ʹ��typedef���壬�����޸Ľṹ������

typedef struct address {
	char* province;
	char* city;
	char* district;
}ADDR;

typedef struct student1 {
	char name[100];
	int age;
	int score;
	//char* address[3];  //Ҳ���԰�address���¶���һ���ṹ�塣
	ADDR address;
}STU;

int main() {

	//struct student student0, student1;  //���ýṹ��ʱ��Ҫдȫstruct
	struct student student0 = { 
		"Youzi",
		25 
	}; //��ú�����Ķ���ṹ����һ�£�
	printf("%s\n", student0.name);
	printf("%d\n", student0.age);

	//ʹ��typedef����Ľṹ�壬����ֱ��ʹ���޸ĺ�����������壻
	STU student1 = {
		"Youzi1",
		26,
		100,
		{"�㶫","����","����԰��"}
	};

	/*
	STU student1 = {
		//"Youzi1",  //����һ��ʼ�ĳ�ʼֵû�У��޷�������ֵ�ǵ�һ���������һ�������Ժ���Ĳ�д�ٶ��嶼����
		26,
		100
	};

	STU student1 = {
		"Youzi1",
		//26,
		//100
	};
	student1.age = 26;
	student1.score = 100;
	
	student1.name = "xiaoyou"; �������ǲ����Եģ���Ϊname�Ķ������ַ����飬��һ������������ֱ�Ӹ�ֵ��
	����ʹ��strcpy_s���� strcpy_s(student1.name,100,"xiaoyou");
	Ҳ���Զ���name��ʱ��ֱ�Ӷ����ָ�� char* name; name="XXX";
	*/
	strcpy_s(student1.name, 100, "xiaoyou"); //�滻student1��name
	printf("%s\n", student1.name);
	printf("%d\n", student1.score);
	//printf("%s\n", student1.address[0]);
	printf("%s\n", student1.address.district);
	
	
	return 0;
}