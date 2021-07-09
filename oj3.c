#include <stdio.h>
struct student
{
	int num;
	char name[20];
	char sex;
	char address[50]; 

};
int max(int b[5])
{
	int i=0;
	int j=0;
	for (;i<4;i++)
	{
		if (b[i]>b[i+1])
		{
			j=i+1;
		}
	}
	return j;
}
int main()
{
	struct student a[5];
	int i=0,j=0;
	int b[5];
	scanf("%d %s %c %s %d %s %c %s %d %s %c %s %d %s %c %s %d %s %c %s",a[0].num,a[0].name,a[0].sex,a[0].address,a[1].num,a[1].name,a[1].sex,a[1].address,a[2].num,a[2].name,a[2].sex,a[2].address,a[3].num,a[3].name,a[3].sex,a[3].address,a[4].num,a[4].name,a[4].sex,a[4].address);
	for (;j<5;j++)
	{
		b[j]=a[j].num;
	}
	int c=max(b);
	printf("%d %s %c %s",a[c].num,a[c].name,a[c].sex,a[c].address);
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
	printf("%d:%d",y,x);
	return 0;
	
}




