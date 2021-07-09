#include <stdio.h>
#include <string.h>
struct student
{
	char name[50];
	struct student *next;
};
int main()
{
	struct student s[5];
	int i = 0;
	for (; i < 5; i++)
	{
		scanf ("%s",&s[i]);
	}
	struct student temp;
	int j,k,w;
	for (j = 0;j < 5;j++)
	{
		k=j;
		for(w=k+1;w<5;w++)
		{
			if (strcmp(s[w].name,s[k].name)>0)
			k=w;
		}
		temp=s[k];
		s[k]=s[j];
		s[j]=temp;
		}
		for (i=0;i<5;i++)
		{
			if(i==4)
			s[i].next=NULL; 
			else 
			s[i].next=&s[i+1];
	
	    }
	    struct student *p;
			p=&s[0];
			for(;p!=NULL;)
			{
				printf("%s ",p->name);
				p=p->next;
			}
}
