#include<stdio.h>
#include<string.h>
//struct  结构体
//第一种定义结构体的方式，调用时必须写全
struct student {
	char name[100];
	int age;
};

//第二种，定义类型和变量放在一起
struct person {
	char name[100];
	int age;
}person0, person1;

//第三种，使用typedef定义，可以修改结构体名字

typedef struct address {
	char* province;
	char* city;
	char* district;
}ADDR;

typedef struct student1 {
	char name[100];
	int age;
	int score;
	//char* address[3];  //也可以把address重新定义一个结构体。
	ADDR address;
}STU;

int main() {

	//struct student student0, student1;  //调用结构体时需要写全struct
	struct student student0 = { 
		"Youzi",
		25 
	}; //最好和最初的定义结构保持一致；
	printf("%s\n", student0.name);
	printf("%d\n", student0.age);

	//使用typedef定义的结构体，可以直接使用修改后的名字来定义；
	STU student1 = {
		"Youzi1",
		26,
		100,
		{"广东","深圳","高新园区"}
	};

	/*
	STU student1 = {
		//"Youzi1",  //不能一开始的初始值没有，无法甄别这个值是第一个还是最后一个，可以后面的不写再定义都可以
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
	
	student1.name = "xiaoyou"; 这样做是不可以的，因为name的定义是字符数组，是一个常量，不能直接赋值；
	可以使用strcpy_s方法 strcpy_s(student1.name,100,"xiaoyou");
	也可以定义name的时候直接定义成指针 char* name; name="XXX";
	*/
	strcpy_s(student1.name, 100, "xiaoyou"); //替换student1的name
	printf("%s\n", student1.name);
	printf("%d\n", student1.score);
	//printf("%s\n", student1.address[0]);
	printf("%s\n", student1.address.district);
	
	
	return 0;
}