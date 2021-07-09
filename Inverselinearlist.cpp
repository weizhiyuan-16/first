#include <iostream>
using namespace std;
class SqList
{
	public:
		SqList ( int n,int a[] );
		~ SqList (){};
		void Inverse();
		void Print();
	private:
		int length;
		int elem[];
		
		
};

SqList::SqList( int n,int a[] )
{
	for( int i = 0; i < n; i++ )
	{
		elem[i] = a[i];
	}
	length = n;
}

void SqList::Inverse()
{
	for( int i = 0; i < length/2; i++)
	{
		int tmp = elem[i];
		elem[i] = elem[length-1-i];
		elem[length-1-i] = tmp;
	}
	
}

void SqList::Print()
{
	for ( int i = 0; i < length; i++ )
	{
		cout<<elem[i]<<' ';
	}
}


int main()
{
	int n,a[50];
	cin>>n;
	for ( int i=0; i < n; i++ )
	{
		cin>>a[i];
	}
	SqList list( n,a );
	list.Inverse();
	list.Print();
	return 0;
	
	
}
