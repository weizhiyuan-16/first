#include<iostream>
#include<stack>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	int* data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	stack<int>s;

	for (int i = 1; i < data[0]; i++)
		s.push(i);
	int tmp = data[0];
	for (int i = 1; i < n; i++) 
	{
		if (!s.empty()) 
		{
			if (data[i] == s.top())s.pop();//��ǰԪ����ջ��Ԫ����ͬʱ��ȡ��ջ��Ԫ�� 
			else if (data[i] > s.top())//��ǰԪ�ش���ջ��Ԫ�أ����ú���������ջ 
				for (int j = tmp + 1; j < data[i]; j++)
					s.push(j);
			else if (data[i] < s.top()) //��ǰԪ��С��ջ��Ԫ�أ��򲻿����������ĳ�ջ˳�� 
			{
				cout << "false" << endl;
				return 0;
			}
		}
	}
	cout << "true" << endl;
	return 0;
}
