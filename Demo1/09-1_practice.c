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

    printf("�������������䣺");
    scanf("%d", &i);

    if (i < 18)
        printf("��δ��18���꣬����ʹ���������\n");
    else
        printf("������18���꣬��ӭʹ�ñ����򣬺ٺٺ�...\n");

    return 0;
}
��д

INT main()
BEGIN
    INT i;
    printf("�������������䣺");
    scanf_s("%d", &i);

    IF i < 18 THEN
        printf("��δ��18���꣬����ʹ���������\n");
    ELSE
        printf("������18���꣬��ӭʹ�ñ����򣬺ٺٺ�...\n");
    FI
    return 0;
END

*/

int main() {

    char ch;
    printf("������һ����д/Сд��ĸ��");
    scanf_s("%c", &ch, 4);  //�������ַ���ע���&��4��ʾ�ַ���ռ�ֽ���
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        printf("ת�����Сд��ĸ�ǣ�%c\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;
        printf("ת����Ĵ�д��ĸ�ǣ�%c\n", ch);
    }

    return 0;
}




