#include<conio.h>
#include<stdio.h>
#include<graphics.h>
int main()
{
int a=10;
char s[5];//声明数组，用来存放字符串
initgraph(320,240);
sprintf(s, "%d", a);//将整形a转换成字符串
outtextxy(10, 60, s);//将字符串输出到界面上
getch();
closegraph();
return 0;
}

