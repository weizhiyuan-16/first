#include <iostream>
using namespace std;

int kmp(int* next, int f, int l, int n) 
{
	int cur;
	int* tmp = new int[n];
	tmp[0] = f; 
	for (int i = 2; i < n; i++) 
	{
		if (next[i] == 0)//最大匹配长度为0 
		{
			if (f == 1) cur = 0;//当前字符的前一个字符与首字符相异 
			else cur = 1;
		}
		else 
		{
			if (next[i] >= i || ( i != next[i] + 1 && tmp[i - next[i] - 1] == tmp[0])) //错误：最大匹配长度过长或字符不匹配时不能回溯到正确位置  
			{
				cout << "ERROR" << endl;
				return 0;
			}
			cur = tmp[next[i] - 1];
		}
		tmp[i - 1] = cur;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cout << tmp[i];
	}
    cout << l;
    cout << endl;
    return 0;
}
int main() 
{
	int f, l, n;
	cin >> f >> l >> n;
	int* next = new int[n];
	for (int i = 0; i < n; i++)
		cin >> next[i];
	kmp(next, f, l, n);
	return 0;
}
