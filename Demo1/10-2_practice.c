#include<stdio.h>

// Ϊ�˷�����ã�����Ϊ�������ҵ��
// ǰ�����˵��������Ž����˺궨��
#define LEFT_MOTO_GO    8
#define LEFT_MOTO_BACK    9
#define RIGHT_MOTO_GO    10
#define RIGHT_MOTO_BACK    11
#define HIGH 1
#define LOW 0

// ...ʡ�Բ��ִ���...
void digitalWrite(int num,char* elec) {

}

void loop()
{
    char ch; // ���ڽ�������
    scanf_s("%c", &ch, 1);
    switch (ch)
    {
        // �����������Ҫ�������䣡����
        case 'g':
            digitalWrite(LEFT_MOTO_GO, HIGH);
            digitalWrite(LEFT_MOTO_BACK, LOW);
            digitalWrite(RIGHT_MOTO_GO, HIGH);
            digitalWrite(RIGHT_MOTO_BACK, LOW);
            break;
        case 'b':
            digitalWrite(LEFT_MOTO_GO, LOW);
            digitalWrite(LEFT_MOTO_BACK, HIGH);
            digitalWrite(RIGHT_MOTO_GO, LOW);
            digitalWrite(RIGHT_MOTO_BACK, HIGH);
            break;
        case 'r':
            digitalWrite(LEFT_MOTO_GO, HIGH);
            digitalWrite(LEFT_MOTO_BACK, LOW);
            digitalWrite(RIGHT_MOTO_GO, LOW);
            digitalWrite(RIGHT_MOTO_BACK, LOW);
            break;
        case 'l':
            digitalWrite(LEFT_MOTO_GO, LOW);
            digitalWrite(LEFT_MOTO_BACK, LOW);
            digitalWrite(RIGHT_MOTO_GO, HIGH);
            digitalWrite(RIGHT_MOTO_BACK, LOW);
            break;
        default:
            digitalWrite(LEFT_MOTO_GO, LOW);
            digitalWrite(LEFT_MOTO_BACK, LOW);
            digitalWrite(RIGHT_MOTO_GO, LOW);
            digitalWrite(RIGHT_MOTO_BACK, LOW);
            break;
    }

    // ...ʡ�Բ��ִ���...
}

int main() {

	return 0;
}