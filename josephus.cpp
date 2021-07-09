#include <iostream>
using namespace std;
void josephus(int n, int k)
{
	int a[n];
	for(int q=0;q<n;q++)
	{
		a[q]=1;
	}
	int i=1,j=0,count=0;
	while(j<n&&count<n)
	{
		if(i<k)
		{
			if(a[j]!=0)
			{
				j++;
			    i++;
			}
			else
			{
				j++;
			}
			
		
		}
		else
		{
			if(a[j]!=0)
			{
				a[j]=0;
				cout<<j+1;
				j++;
				count++;
				if(count<n)
				{
					cout<<"->";
				}
				i=1;
			}
			else
			{
				j++;
			}	
		}

			j=j%n;
			
		}
	
	
	
}


int main(){
	int n,k;
	cin>>n>>k;
	josephus(n,k);
	return 0;
}
