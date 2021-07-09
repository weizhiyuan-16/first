#include<iostream>
#include<algorithm>
using namespace std;

//��kruskal�㷨�������µı�Ȩ�غͣ�������Ȩ�ؼ���ʣ�µıߵ�Ȩ�صõ�ȥ���ߵ�Ȩ�غ͡� 
struct Edge 
{
	int u, v, w;
	bool operator <(struct Edge& edge) //��ΪҪ��sort()�����������������'<'�� 
	{
		return w < edge.w;
	}
}e[10005];
int n, m, par[10005];
int unionfind(int x) //����Ԫ�صĸ��ڵ㡣 
{
	return x == par[x] ? x : par[x] = unionfind(par[x]);
}

int kruskal() 
{
	int cnt = 0, ans = 0;
	sort(e, e + m);
	for (int i = 0; i < m; ++i) 
	{
		int fu = unionfind(e[i].u), fv = unionfind(e[i].v);
		if (fu != fv) //���ڵ㲻ͬ�� 
		{
			ans += e[i].w;
			par[fu] = fv;
			if (++cnt == n - 1)return ans;// ����n-1���ߡ� 
		}
	}
}
int main() 
{
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		sum += e[i].w;
	}
	for (int i = 1; i <= n; i++)
		par[i] = i;
	cout << sum - kruskal() << endl;
}
