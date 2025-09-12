#include<stdio.h>
#include<stdlib.h>
/* union:共用体：几个不同的变量共同占用一段内存的结构，占用同一段地址空间
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
   应用:
   1、输入1时保存学生的信息(姓名，成绩)，输入2时保存老师的信息(姓名，工资，保险账号)
   2、
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

//共用体定义结构体空间
typedef union {
    STU student;
    TEA teacher;
}ANY;

void save1(STU* student) {
    //存文件成功，打印
    printf("save-student-%s-%d\n", student->name, student->score);
}

void save2(TEA* teacher) {
    //存文件成功，打印
    printf("save-teacher-%s-%d-%d\n", teacher->name, teacher->salary, teacher->iNumber);
}

void save(ANY* anydata, int type) {
    if (type == 1) {
        //存文件成功，打印
        printf("save-student-%s-%d\n", anydata->student.name, anydata->student.score);
    }
    else {
        //存文件成功，打印
        printf("save-teacher-%s-%d-%d\n", anydata->teacher.name, anydata->teacher.salary, anydata->teacher.iNumber);
    }
}

typedef struct { //:1表示0-7一位一位存
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
    /* 初识共用体
    struct stu student1;
    union tea teacher1;

    //struct占用8个字节，union只占4个字节；增加一个char c，
    // 结构体占用只会随着类型的变多占用更多，共用体只会以成员占用最大的内存作为占用空间
    printf("%lld\n",sizeof(student1));
    printf("%lld\n",sizeof(teacher1));

    //teacher1的 a b c的地址都是一样的
    printf("%p\n",teacher1.a);
    printf("%p\n",teacher1.b);
    printf("%p\n",teacher1.c);

    teacher1.a = 0x11111111; //int占4个字节，2个16进制占1个字节 11 11 11 11
    printf("%x\n",teacher1.a);
    teacher1.c = 0x33; //c占1个字节，会覆盖最后一个11
    printf("%x\n",teacher1.a);
    */

    /*应用*/

    Header header;
    header.all = 255;
    printf("%d\n", header.all);
    printf("%d\n", header.bits.b0); //一位一位读
    printf("%d\n", header.bits.b1); //一位一位读
    printf("%d\n", header.bits.b2); //一位一位读
    printf("%d\n", header.bits.b3); //一位一位读
    printf("%d\n", header.bits.b4); //一位一位读
    printf("%d\n", header.bits.b5); //一位一位读
    printf("%d\n", header.bits.b6); //一位一位读
    printf("%d\n", header.bits.b7); //一位一位读

    printf("请输入要录入的是学生，还是老师的信息，学生输入1，老师输入2\n");

    int type = 0;
    scanf_s("%d", &type);

    if (type == 1) {
        //申请 存学生的 内存
        //STU *student = (STU *)malloc(sizeof(STU));
        ANY* any = (ANY*)malloc(sizeof(ANY));
        //if(!student) return;
        if (!any) return;
        //scanf_s("%s%d",student->name,&student->score);
        scanf_s("%s%d", any->student.name, 100, &any->student.score);
        //输入之后 保存信息
        //save1(student); //结构体使用的保存方法不一样
        save(any, type); //student和teacher 共用同一个save方法
    }
    else {
        //申请 存老师的 内存
        //TEA *teacher = (TEA *)malloc(sizeof(TEA));
        ANY* any = (ANY*)malloc(sizeof(ANY));
        //if(!teacher) return;
        if (!any) return;
        //scanf_s("%s%d%d",teacher->name,&teacher->salary,&teacher->iNumber);
        scanf_s("%s%d%d", any->teacher.name, 100, &any->teacher.salary, &any->teacher.iNumber);
        //输入之后 保存信息
        //save2(teacher); //结构体使用的保存方法不一样
        save(any, type); //student和teacher 共用同一个save方法

    }



    return 0;
}