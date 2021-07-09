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

/*题目描述
村庄中存在一些路，根据输入的相邻村庄的路，判断某两个村庄是否能够联通。n个村庄使用0到n-1的不同整数标识。路使用取值范围【0，n-1】的整数对表示。例如 3 5，代表村庄3和5之间有一条路。

Input Format

村庄个数 n， 0<n<=20

路的条数 m，0<m<=50

m条路，即为2m个范围在【0，n-1】的整数   

需要判断是否相连的村庄对数 p 0<p<=10

需要判断是否相连的p对村庄，即为2p个范围在【0，n-1】的整数。

Output Format
能够连通输出

true

,不可连通输出

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
