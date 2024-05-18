#include<stdio.h>

int main() {
	/*
		浮点型(实型)数据
		float 单精度浮点型  %f
 		double 双精度浮点型 %lf
	*/

	int a1 = 10;
	float a2 = a1 * 0.7;

	double a3 = a1 / 3.0;  //进行浮点计算的话不能使用整形的数据计算，会计算出整形，10 / 3 = 3

	printf("a2 = %f\n", a2);
	printf("a3 = %lf", a3);
	
	
}