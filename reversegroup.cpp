#include <iostream>
using namespace std;
class List
{
	public:
		List(int a[],int n,int m);
		~List(){};
		void Reverse();
		void print();
	private:
		int data[50];
		int group1,group2;
};

List::List(int a[],int n,int m)
{
	group1=n;
	group2=m;
	int i=0;
	for (;i<n+m;i++)
	{
		data[i]=a[i];
	}
	
}

void List::Reverse()
{
	int i=0,j=0,k=0;
	int tmp;
	for(;k<group1/2;k++)
	{
		tmp=data[k];
		data[k]=data[group1-1-k];
		data[group1-1-k]=tmp;
	}	
	for(;i<(group1+group2)/2;i++)
	{
		tmp=data[i];
		data[i]=data[group1+group2-1-i];
		data[group1+group2-1-i]=tmp;
	}
	for(;j<group2/2;j++)
	{
		tmp=data[j];
		data[j]=data[group2-1-j];
		data[group2-1-j]=tmp;
	}

}

void List::print()
{
	int i=0;
	for(;i<group1+group2;i++)
	{
		cout<<data[i]<<' ';
	}
}

int main()
{
	int a[30],n,m;
	int i=0;
	cin>>n>>m;
	for(;i<n+m;i++)
	{
		cin>>a[i];
	}
	List list(a,n,m);
	list.Reverse();
	list.print();
	list.~List();
	return 0;
}
//时间复杂度为O(n+m) 
