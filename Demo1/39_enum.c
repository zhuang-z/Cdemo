#include<stdio.h>

int main() {

    //enum ö��
    enum week { mon = 1, tue, wed, thu, fri, sat, sun };
    //�����µ����� week,week������ݴ�0��ʼ mon=1,��1��ʼ���
    enum week day = mon;

    printf("%d\n", day);
    printf("%d\n", sat);
    printf("%d\n", sun);

    return 0;
}