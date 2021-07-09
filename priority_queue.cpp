#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, t;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		q.push(t);
	}
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		sum += a + b;
		q.push(a + b);
	}
	cout << sum << endl;
	return 0;
}
