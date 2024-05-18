#include<stdio.h>

int main() {

	int sum = 250;
	/*
	if(sum > 200){
		sum = sum*0.7;
	}
	*/

	//三目运算符：
	sum = sum > 200 ? sum * 0.7 : sum;
	printf("%d\n", sum);

	//逗号运算符 ， 把逗号后面的值赋值给前面
	int a = 1;
	a = (a += 2, a * a);
	printf("%d\n", a);



	//自增自减运算符 b++ ++b

	int b = 10;
	/*int b1 = b++;
	int b2 = ++b;
	printf("%d %d\n", b1,b2);*/

	int c = 10 + b++; // ++在后，先赋值计算b+b，然后b再自增
	int d = 10 + ++b; // ++在钱，b先自增，再赋值计算b+b
	printf("%d %d", c, d);


	return 0;
}