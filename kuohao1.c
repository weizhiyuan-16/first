#include <stdio.h>
int main()
{
	char a[20];
	char *p;
	p=&a[0];
	int xk1=0,xk2=0,dk1=0,dk2=0;
	scanf("%s",&a);
	for(;*p!='\0';p++)
	{
		if (*p=='(')
		{
			xk1++;
		}
		else if(*p==')')
		{
			xk2++;
		}
		else if(*p=='[')
		{
			dk1++;
		}
		else if(*p==']')
		{
			dk2++;
		}
	}
	if (xk1==xk2&&dk1==dk2)
	{
	    printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	
	return 0;
}
