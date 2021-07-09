#include<iostream>
#include<stack>

using namespace std;

struct edge
{
	int bg, ed, val;
	edge(int p = 0,int q = 0,int v = -1):bg(p), ed(q), val(v){}
};

struct Node
{
	int flag;//标示结点是否已被访问。 
	Node(int f = 0):flag(f){}
};
//存储距离该结点最近的点以及路径长 
struct path
{
	int length, k;
	path(int l = 101,int kk = 0):length(l),k(kk){}
	path(const path& p)
	{
		length = p.length;
		k = p.k;
	}
};
//得到距离该点最近的点的路径长度 
int minpath(int bg, int ed, edge* e, int m)
{
	if(bg == ed)return 0;
	int min = 101;
	for(int i = 0;i < m; i++)
		if(e[i].bg == bg && e[i].ed == ed && e[i].val < min)
			min = e[i].val;

		return min;
}

int main()
{
	int n, m, t1, t2, t3, s;
	cin >> n >> m;
	edge* e = new edge[m];
	Node* N = new Node[n];
	int* pre = new int[n];//与当前结点相连的前一个点。 
	path* p = new path[n];
    
   
	for(int i = 0; i < n; i++)
		p[i].k = i;

	for(int i = 0; i < n; i++)
		pre[i] = -1;

	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> t3;
		e[i].bg = t1 - 1;
		e[i].ed = t2 - 1;
		e[i].val = t3;
	}
	cin >> s;
	s -= 1;
	pre[s] = s;
	p[s].length = 0;
	N[s].flag = 1;

	int* key = new int[n];
	for(int i = 0; i < n; i++)
	{
		p[i].length = minpath(s, i, e, m);
		key[i] = p[i].length;//暂存各结点的最短路径。 
	}

	int c1, c2;
	c1 = s;//从源点开始搜寻。 
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(N[j].flag == 1)continue;//已访问，直接跳到下一个结点。 
			if(key[j] > (key[c1] + minpath(c1, j, e, m)))
				{
					key[j] = key[c1] + minpath(c1, j, e, m);
					pre[j] = c1;
				}
		}
		int min = 101, j = 0;;
		for(;j < n; j++)
		{
			if(N[j].flag == 1)continue;
			if(key[j] <= min)
				{
					min = key[j];
					c2 = j;
				}
		}
		
		N[c2].flag = 1;
		if(i == 0)pre[c2] = c1;
		p[c2].length = key[c2];
		c1 = c2;
	}

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(p[j].length < p[i].length)
			{
				path pp = p[j];
				p[j] = p[i];
				p[i]= pp;
			}

	int count = 1, flag = 0;
	for(int i = 0; i < n; i++)
	{
		int num = p[i].k;
		if(p[i].k == s)continue;
		if(p[i].length == 101)
		{
			flag++;
			continue;
		}

		stack<int> st;
		st.push(num);
		while(pre[num] != s)
		{
			st.push(pre[num]);
			num = pre[num];
		}

		cout << "No." << count++ << " : " << s + 1 << " ";
		while(!st.empty())
		{
			cout << "-> " << st.top() + 1 << " ";
			st.pop();
		}
		cout << ", d = " << p[i].length << endl;
	}

	if(flag > 0)
	{
	cout << "No." << count << " : No Path to";
	int *np = new int[flag];
	int q = 0;
	for(int i = 0; i < n; i++)
	{
		if(p[i].length == 101) np[q++] = p[i].k + 1;
	}

	for(int i = 0;i < flag; i++)
		for(int j = i + 1; j < flag; j++)
			if(np[j] < np[i])
			{
				int tmp = np[j];
				np[j] = np[i];
				np[i] = tmp;
			}

	for(int i = 0; i < flag; i++)cout << " " << np[i];
	}

	return 0;

}


