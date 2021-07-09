#include<iostream>
#include<algorithm>
using namespace std;

//用kruskal算法计算留下的边权重和，再用总权重减掉剩下的边的权重得到去除边的权重和。 
struct Edge 
{
	int u, v, w;
	bool operator <(struct Edge& edge) //因为要用sort()进行排序，重载运算符'<'。 
	{
		return w < edge.w;
	}
}e[10005];
int n, m, par[10005];
int unionfind(int x) //查找元素的根节点。 
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
		if (fu != fv) //根节点不同。 
		{
			ans += e[i].w;
			par[fu] = fv;
			if (++cnt == n - 1)return ans;// 已有n-1条边。 
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
