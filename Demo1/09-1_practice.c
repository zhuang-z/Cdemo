#include<stdio.h>

#define STRING char *
#define IF if(
#define THEN ){
#define ELSE }else{
#define FI ;}
#define WHILE while(
#define DO ){
#define OD ;}
#define INT int
#define BEGIN {
#define END }

/*
#include <stdio.h>

int main()
{
    int i;

    printf("请输入您的年龄：");
    scanf("%d", &i);

    if (i < 18)
        printf("您未满18周岁，不得使用这个程序！\n");
    else
        printf("您已满18周岁，欢迎使用本程序，嘿嘿嘿...\n");

    return 0;
}
改写

INT main()
BEGIN
    INT i;
    printf("请输入您的年龄：");
    scanf_s("%d", &i);

    IF i < 18 THEN
        printf("您未满18周岁，不得使用这个程序！\n");
    ELSE
        printf("您已满18周岁，欢迎使用本程序，嘿嘿嘿...\n");
    FI
    return 0;
END

*/

int main() {

    char ch;
    printf("请输入一个大写/小写字母：");
    scanf_s("%c", &ch, 4);  //单输入字符，注意加&，4表示字符所占字节数
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        printf("转换后的小写字母是：%c\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;
        printf("转换后的大写字母是：%c\n", ch);
    }

    return 0;
}




