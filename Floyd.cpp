#include<iostream>
using namespace std;

int main()
{
	int n, m, t1, t2, t3;
	cin >> n >> m;

	int* c = new int[n * n];
    //建立关系矩阵。 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			{
				c[i * n + j] = 100000;//初始默认所有点之间都不连通。 
				if(i == j)c[i * n + j] = 0;
			}

	for(int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> t3;
		c[t1 * n + t2] = t3;
	}

	for(int k = 0; k < n;k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				t1 = c[i * n + k];//起始点到中间点路径长 
				t2 = c[k * n + j];//中间点到目标点路径长 
				t3 = c[i * n + j];//当前最短路径长 

				if(t1 != -1 && t2 != -1 && t1 + t2 < t3)
					c[i*n+j] = t1 + t2;
			}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			{
				if(j != 0)cout << ' ';
				
				if(c[i * n + j] == 100000) cout << -1;
					else cout << c[i * n + j];
			}
		cout << endl;
	}
	

	return 0;
}
