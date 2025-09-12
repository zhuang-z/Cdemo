#include<stdio.h>
#include<stdlib.h>
/* union:�����壺������ͬ�ı�����ͬռ��һ���ڴ�Ľṹ��ռ��ͬһ�ε�ַ�ռ�
*/

/*
struct stu{
    char c;
    int a;
    int b;
}

union tea{
    char c;
    int a;
    int b;
}
*/

/*
   Ӧ��:
   1������1ʱ����ѧ������Ϣ(�������ɼ�)������2ʱ������ʦ����Ϣ(���������ʣ������˺�)
   2��
*/
typedef struct {
    char name[100];
    int score;
}STU;

typedef struct {
    char name[100];
    int salary;
    int iNumber;
}TEA;

//�����嶨��ṹ��ռ�
typedef union {
    STU student;
    TEA teacher;
}ANY;

void save1(STU* student) {
    //���ļ��ɹ�����ӡ
    printf("save-student-%s-%d\n", student->name, student->score);
}

void save2(TEA* teacher) {
    //���ļ��ɹ�����ӡ
    printf("save-teacher-%s-%d-%d\n", teacher->name, teacher->salary, teacher->iNumber);
}

void save(ANY* anydata, int type) {
    if (type == 1) {
        //���ļ��ɹ�����ӡ
        printf("save-student-%s-%d\n", anydata->student.name, anydata->student.score);
    }
    else {
        //���ļ��ɹ�����ӡ
        printf("save-teacher-%s-%d-%d\n", anydata->teacher.name, anydata->teacher.salary, anydata->teacher.iNumber);
    }
}

typedef struct { //:1��ʾ0-7һλһλ��
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
}Bits;

typedef union {
    Bits bits;
    unsigned char all;
}Header;

int main() {
    /* ��ʶ������
    struct stu student1;
    union tea teacher1;

    //structռ��8���ֽڣ�unionֻռ4���ֽڣ�����һ��char c��
    // �ṹ��ռ��ֻ���������͵ı��ռ�ø��࣬������ֻ���Գ�Առ�������ڴ���Ϊռ�ÿռ�
    printf("%lld\n",sizeof(student1));
    printf("%lld\n",sizeof(teacher1));

    //teacher1�� a b c�ĵ�ַ����һ����
    printf("%p\n",teacher1.a);
    printf("%p\n",teacher1.b);
    printf("%p\n",teacher1.c);

    teacher1.a = 0x11111111; //intռ4���ֽڣ�2��16����ռ1���ֽ� 11 11 11 11
    printf("%x\n",teacher1.a);
    teacher1.c = 0x33; //cռ1���ֽڣ��Ḳ�����һ��11
    printf("%x\n",teacher1.a);
    */

    /*Ӧ��*/

    Header header;
    header.all = 255;
    printf("%d\n", header.all);
    printf("%d\n", header.bits.b0); //һλһλ��
    printf("%d\n", header.bits.b1); //һλһλ��
    printf("%d\n", header.bits.b2); //һλһλ��
    printf("%d\n", header.bits.b3); //һλһλ��
    printf("%d\n", header.bits.b4); //һλһλ��
    printf("%d\n", header.bits.b5); //һλһλ��
    printf("%d\n", header.bits.b6); //һλһλ��
    printf("%d\n", header.bits.b7); //һλһλ��

    printf("������Ҫ¼�����ѧ����������ʦ����Ϣ��ѧ������1����ʦ����2\n");

    int type = 0;
    scanf_s("%d", &type);

    if (type == 1) {
        //���� ��ѧ���� �ڴ�
        //STU *student = (STU *)malloc(sizeof(STU));
        ANY* any = (ANY*)malloc(sizeof(ANY));
        //if(!student) return;
        if (!any) return;
        //scanf_s("%s%d",student->name,&student->score);
        scanf_s("%s%d", any->student.name, 100, &any->student.score);
        //����֮�� ������Ϣ
        //save1(student); //�ṹ��ʹ�õı��淽����һ��
        save(any, type); //student��teacher ����ͬһ��save����
    }
    else {
        //���� ����ʦ�� �ڴ�
        //TEA *teacher = (TEA *)malloc(sizeof(TEA));
        ANY* any = (ANY*)malloc(sizeof(ANY));
        //if(!teacher) return;
        if (!any) return;
        //scanf_s("%s%d%d",teacher->name,&teacher->salary,&teacher->iNumber);
        scanf_s("%s%d%d", any->teacher.name, 100, &any->teacher.salary, &any->teacher.iNumber);
        //����֮�� ������Ϣ
        //save2(teacher); //�ṹ��ʹ�õı��淽����һ��
        save(any, type); //student��teacher ����ͬһ��save����

    }



    return 0;
}