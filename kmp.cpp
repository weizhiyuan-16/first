#include <iostream>
using namespace std;

int kmp(int* next, int f, int l, int n) 
{
	int cur;
	int* tmp = new int[n];
	tmp[0] = f; 
	for (int i = 2; i < n; i++) 
	{
		if (next[i] == 0)//���ƥ�䳤��Ϊ0 
		{
			if (f == 1) cur = 0;//��ǰ�ַ���ǰһ���ַ������ַ����� 
			else cur = 1;
		}
		else 
		{
			if (next[i] >= i || ( i != next[i] + 1 && tmp[i - next[i] - 1] == tmp[0])) //�������ƥ�䳤�ȹ������ַ���ƥ��ʱ���ܻ��ݵ���ȷλ��  
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
