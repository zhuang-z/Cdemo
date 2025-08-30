#include<stdio.h>
#include<math.h>

int main() {
	//求 1^2 + 2^3 + 3^4 + 4^5 + 5^6 的值
	double a = 1, b = 2, c = 3, d = 4, e = 5;
	printf("%.0lf\n", (pow(a, b) + pow(b, c) + pow(c, d) + pow(d, e))); //pow函数是math.h中的函数，返回值为double类型


	//舍罕王的故事
	//棋盘的第 1 格放 1 粒，第 2 格放 2 粒，第三格放 4 粒，以后每一格都比前一格增加一倍，依此放完棋盘 64 格
	int i;
	unsigned long long int sum = 0;

	for (i = 0; i < 64; i++) {
		unsigned long long int temp = pow(2, i);
		sum = sum + temp;
	}
	unsigned long long int weight = sum / 25000;

	printf("舍罕王应该给予达伊尔%llu粒麦子\n", sum);
	printf("约合%.0llu公斤\n", weight);

	return 0;
}