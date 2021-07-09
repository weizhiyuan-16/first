#include<iostream>
using namespace std;
class unionfind 
{
private:
	int* parent;
	int size;
public:
	unionfind(int s) 
	{
		size = s;
		parent = new int[size];
		for (int i = 0; i < size; i++) 
		{
			parent[i] = i;
		}
	}
	int find(int x) 
	{
		while (parent[x] != x)
			x = parent[x];
		return x;
	}
	void combine(int v1, int v2) 
	{
		int par1 = find(v1);
		int par2 = find(v2);
		if (par1 == par2)
			return;
		else 
		{
			if (par1 > par2)
				parent[par2] = par1;
			else if (par1 < par2)
				parent[par1] = par2;
			
			return;
		}
	}
	bool isconnect(int v1, int v2) 
	{
		return (find(v1) == find(v2));
	}
};
int main() {
	int n, m, p;
	int v1, v2;
	int result;
	cin >> n >> m;
	unionfind u(n);
	for (int i = 0; i < m; i++) 
	{
		cin >> v1 >> v2;
		u.combine(v1, v2);
	}
	cin >> p;
	int* num = new int[2 * p];
	for (int i = 0; i < 2*p;) 
	{
		cin >> num[i] >> num[i+1];
		i += 2;
	}
	for (int i = 0; i < 2 * p;) 
	{
		result = u.isconnect(num[i], num[i + 1]);
		if (result == 0)
			cout << "false" << endl;
		else
			cout << "true" << endl;
		i += 2;
	}
	return 0;
}

/*��Ŀ����
��ׯ�д���һЩ·��������������ڴ�ׯ��·���ж�ĳ������ׯ�Ƿ��ܹ���ͨ��n����ׯʹ��0��n-1�Ĳ�ͬ������ʶ��·ʹ��ȡֵ��Χ��0��n-1���������Ա�ʾ������ 3 5�������ׯ3��5֮����һ��·��

Input Format

��ׯ���� n�� 0<n<=20

·������ m��0<m<=50

m��·����Ϊ2m����Χ�ڡ�0��n-1��������   

��Ҫ�ж��Ƿ������Ĵ�ׯ���� p 0<p<=10

��Ҫ�ж��Ƿ�������p�Դ�ׯ����Ϊ2p����Χ�ڡ�0��n-1����������

Output Format
�ܹ���ͨ���

true

,������ͨ���

false



Example
Input
5
4

0 4

2 4

0 2

1 3

2

3 4

2 4

Output
false

true*/
