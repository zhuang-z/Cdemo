#include<stdio.h>
#include<math.h>
int main() {

	//算数运算练习
	//1.等额本息还款法
	/*
	等额本息还款法，也称定期付息，即借款人每月按相等的金额偿还贷款本息，其中每月贷款利息按月初剩余贷款本金计算并逐月结清。
	月均还款 = 贷款本金 * (月利率 * (1 + 月利率)^还款月数) / ((1 + 月利率)^还款月数 - 1)
	总利息 = 还款月数 * 月均还款 - 贷款本金
	贷款本金 = 房款总额 * 按揭成数*/

	/*
	输入房屋单价、面积、按揭成数、按揭年数以及基准利率
	偿还的房款总额、首期付款、贷款总额、支付利息以及每月需要还款多少各项数据。*/

	/*
	float price, area, ration, year, month, yrate, mrate;
	float total, first, daikuan, huankuan, lixi, yuejun;

	printf("请输入单价（元/平方）：");
	scanf_s("%f",&price);
	printf("请输入面积：");
	scanf_s("%f", &area);
	printf("请输入按揭成数：");
	scanf_s("%f", &ration);
	printf("请输入按揭年数：");
	scanf_s("%f", &year);
	printf("请输入当前基准年利率：");
	scanf_s("%f", &yrate);
	printf("============报告结果===========\n");

	mrate = yrate /100 / 12; //月利率 年利率/12
	month = year * 12; //还款月数 按揭年数*12

	total = price * area; //房款总额 价格*面积
	first = total * (1 - ration * 0.1); //首期付款 房款总额*(1-按揭成数)
	daikuan = total * ration * 0.1; //贷款总额 房款总额*按揭成数
	yuejun = daikuan * mrate * pow((1 + mrate), month) / (pow((1 + mrate), month) - 1); //月均还款 贷款本金*(月利率*(1+月利率)^还款月数)/((1+月利率)^还款月数-1)
	lixi = month * yuejun - daikuan; //利息 还款月数*月均还款-贷款本金
	huankuan = daikuan + lixi; //还款总额 还款月数*月均还款


	printf("房贷总额%.2f\n",total);
	printf("首期付款%.2f\n",first);
	printf("贷款总额%.2f\n", daikuan);
	printf("还款总额%.2f\n",huankuan);
	printf("支付利息%.2f\n",lixi);
	printf("月均还款%.2f\n",yuejun);
	*/

	//2.计算5年本息和
	int n1 = 5, n2 = 3, n3 = 2;
	float deposite1, deposite2, deposite3;
	float principal = 60000; //本金  
	// 14000元 5年后本息和 94018.54元
	// 23000元 5年后本息和 154459.05元
	// 40000元 5年后本息和 268624.41元
	// 50000元 5年后本息和 335780.50元  5*5 = 25万元 增量 85,780.5元 上涨34%
	// 60000元 5年后本息和 402936.60元  6*5 = 30万元 增量 102936.6元 上涨34%
	float rate1 = 0.0275; //3 5年定期利率
	float rate2 = 0.0225; //2年利率
	float rate3 = 0.0135; //1年利率
	float raw = principal;
	int year = 5;
	int i = 1;
	while (i <= year) {
		deposite1 = principal * (1 + rate1);
		if (i != year) {
			principal = deposite1 + raw;
		}
		i++;

	}
	//deposite1 = principal * (1 + rate1 * n1); //一次性定期存5年；
	//deposite2 = principal * (1 + rate1 * n2) * (1 + rate2 * n3); //先存3年定期，再存2年定期
	//deposite3 = principal * (pow((1 + rate3), n1)); //存1年定期，第二年取出再存1年，依次类推

	printf("一次性定期存5年本息和%.2f %.2f\n", deposite1, principal);
	//printf("先存3年定期，再存2年定期本息和%.2f\n", deposite2);
	//printf("存1年定期，第二年取出再存1年，依次类推本息和%.2f\n", deposite3);

	printf("%d\n", (1 != 0 && 2 / 1));
	return 0;
}