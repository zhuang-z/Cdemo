#include<stdio.h>

int main() {

    //enum 枚举
    enum week { mon = 1, tue, wed, thu, fri, sat, sun };
    //创建新的类型 week,week里的数据从0开始 mon=1,从1开始编号
    enum week day = mon;

    printf("%d\n", day);
    printf("%d\n", sat);
    printf("%d\n", sun);

    return 0;
}