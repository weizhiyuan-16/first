#include <stdio.h>
#include <stdlib.h>
struct student
{
	 int num;
	 char name[20];
	 char sex;
	 char address[50];
};
int main()
{
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
	printf("%d %s %c %s",&a[c].num,&a[c].name,&a[c].sex,&a[c].address);
	return 0;
	
}
int max(int a[5])
{
	int i=0;
	int b=a[0];
	for(;i<4;i++)
	{
		if(a[i]>a[i+1])
		{
			a[i+1]=a[i];
		}
		
	}
	return a[i+1];
}
