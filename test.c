#include<conio.h>
#include<stdio.h>
#include<graphics.h>
int main()
{
int a=10;
char s[5];//�������飬��������ַ���
initgraph(320,240);
sprintf(s, "%d", a);//������aת�����ַ���
outtextxy(10, 60, s);//���ַ��������������
getch();
closegraph();
return 0;
}

