#include <iostream>
#include <queue>
using namespace std;
int main()
{
	long long a,b;
	long long t,w;
	int x,y,n;
	cin >> a >> b >> n;
	x = n;
	y = 0;
	queue <long long> q;
	q.push(0);
	q.push(a);
	q.push(b);
	for (int i = 1 ; i < n ; i++)
	{
		q.push(0);
		for (int j = 1 ; j <= i + 2 ; j++)
		{
			t = q.front();
			q.pop();
			w = q.front();
			q.push(b * t + a * w);//计算系数，利用杨辉三角 
		}
	}
	q.pop();
	while (!q.empty())
	{
		if(q.front() == 1){}
		else if(q.front() == -1)
		{
			cout << "-";
		}
		else
		{
			cout << q.front();
		}
		if (x == 1)
		{
			cout << "x";
		}
		else if (x == 0){}
		else
		{
			cout << "x^" << x;
		}
		if (y == 1)
		{
			cout << "y";
		}
		else if (y == 0){}
		else
		{
			cout << "y^" << y;
		}
		x--;
		y++;
		
		q.pop();
		if (!q.empty() && q.front() > 0)
		cout << "+";
	}
	 
}  
