#include<stdio.h>
#include<stdbool.h>

int main() {

	//关系运算符 > < == >= <= !=
	int a = 28;
	if (a>=28) {  //()里的条件符合，执行{}里的语句
		printf("符合条件\n");
	}

	//布尔类型 C89没有bool类型  C99才加进来  依赖库#include<stdbool.h>
	bool isMatch = true; // true:1 false:0
	printf("%d\n", isMatch);


	/*
		逻辑运算符
			&&：与，同真为真，一假则假；
			||：或，一真则真，同假为假；
			！：非，取反；
	*/

	printf("%d\n", 1 > 2 && 3 > 4);
	printf("%d\n", 1 > 2 || 3 > 4);
	printf("%d\n", !(1 > 2));  //非的优先级比关系运算符要高

	/*
		商场 周末，家电满250元打7折；
	*/
	int day = 6;  //周六或者周天才能打折
	int type = 1; //0：食品  1：家电 2：日用品
	int price = 300;

	if (price > 250 && type == 1 && !(day == 6 || day == 7)) {
		price *= 0.7;
		printf("%d\n", price);
	}

	//&&短路

	int gender = 0; //0表示女，1表示男
	if (gender == 0) {
		printf("女\n");
	}
	//&&短路写法，前面成立才会进行后面的打印语句
	gender == 1 && printf("男\n");

	return 0;
}