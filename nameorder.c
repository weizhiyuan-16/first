#include <stdio.h>
struct student
{//1808 hangsan M Beijing 1803 lisi M Tianjin 1805 wangwu M Hebei 1810 zhaoliu F Henan 1801 chenyi F Shandong
	 int num;
	 char name[20];
	 char sex;
	 char address[50];
};
int max(int a[5])
{
	int i=0;
	int max=0,g;
	for(;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			g=i;
		}
		
	}
	return g;
}
int main()
{
	int max(int a[5]);
	struct student a[5];
	int i=0;
	int j=0;
	int b[5];
	for (;i<5;i++)
	{
		scanf("%d %s %c %s",&a[i].num,&a[i].name,&a[i].sex,&a[i].address);
	}
	for (;j<5;j++)
	{
		b[j]=a[j].num;
	}
	int c=max(b);
	printf("%d %s %c %s\n",a[c].num,a[c].name,a[c].sex,a[c].address);
	int x=0,y=0;
	for (i=0;i<5;i++)
	{
		if (a[i].sex=='F')
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	printf ("%d:%d",y,x);
	return 0;
	
}

