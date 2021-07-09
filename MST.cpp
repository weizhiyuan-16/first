#include<iostream>

using namespace std;

//查找当前顶点的标志 
int find(int t, int* p)
{
	if(p[t] == t) return t;
	else return find(p[t], p);
}

//连接两点，使两点标志相同。 
void union_t(int t1,int t2,int* p)
{
	if(find(t1, p) != find(t2, p))p[find(t1, p)] = t2;
}


int main()
{
	int n, m, t1, t2; 
	int sum = 0; 
	cin >> n;
	int* e = new int[n * n];
	int* v = new int[n];

	for(int i = 0; i < n; i++)
		v[i] = i;

	for(int i = 0; i < n * n; i++)
	{
		cin >> t1;
		e[i] = t1;
	}

	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		union_t(t1 - 1, t2 - 1, v);
		e[(t1 - 1) * n + t2 - 1] = -1;//标记已存在的路。 
	}
	for(; m < n - 1;)
	{
		int min = 10000;
		int vi, vj;
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(e[i * n + j] != -1 && e[i * n + j] < min && (find(i, v) != find(j, v)))//寻找所有边中权重最小且对应两点未连接的边 
				{
					min = e[i * n + j];
					vi = i;
					vj = j;
				}
			}
		}

		sum += e[vi * n + vj];
		e[vi * n + vj] = -1;
		union_t(vi, vj, v);
		m++;
	}

	cout << sum;
	return 0;

}
