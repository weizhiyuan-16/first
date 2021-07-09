#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	stack<char>a;
	stack<char>b;
	a.push(s[0]);
	int i=1;
	while(s[i]!='\0')
	{
		if(a.empty())
		{
			a.push(s[i]);
		}
		else if ((a.top()==s[i]+32)||(a.top()==s[i]-32))
		{
			a.pop();
		}
		else
		{
			a.push(s[i]);
		}
		i++;
	}
	if (a.empty())
		cout<<-1;
	else
	{	while(!a.empty())
		{
			b.push(a.top());
			a.pop();

		} 
		while(!b.empty())
		{
			cout<<b.top();
			b.pop();
		}
	return 0;

	
	}
	
}

