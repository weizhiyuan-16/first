#include <stdio.h>
int main()
{
	int n,w,i;
	int a;
	float s[100];
	int value[100],weight[100];
	scanf ("%d %d",&n,&w);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&value[i],&weight[i]);
		s[i]=weight[i]/value[i];
		
	}
	for (int j=0;j<n-1;j++)
	{
		if(s[j]>s[j+1])
		{
			a=s[j];
			s[j]=s[j+1];
			s[j+1]=a; 
		}
	}
	for (int q=0;q<n;q++)
	{
		int h=
	}
	return 0;
}
