#include <iostream>
using namespace std;

class Vertex
{
	int flag;
	public:
		int val;
		int* dis;
		Vertex(){flag = 0;}
		~Vertex(){delete dis;}
		void set(int n, int i);
		void setflag(){flag = 1;}
		int Getf(){return flag;}
};

void Vertex::set(int n, int i)
{
	dis = new int[n];
	val = i;
}



int Min(int a[])
{
	int min = a[0];
	for(int i = 1;a[i] ; ++i)
	{
		
		if(a[i] < min) min = a[i];

	}
	return min;
}

int main()
{
	int n, m;
	cin >> n;
	int* d = new int[n];
	Vertex* v = new Vertex[n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			v[i].set(n, i);
			cin >> v[i].dis[j];
			cout << v[0].dis[0] << 't' << endl;
		}
	}
	cout << v[0].dis[0] << 't' << endl;

	cin >> m;
	int tmp1, tmp2;
	for(int i = 0;i < m; ++i)
	{
		cin >> tmp1 >>tmp2;
		v[tmp1 - 1].setflag();
		v[tmp2 - 1].setflag();
	}
	int tol = 0;
	int* tmp;
	for(int count = m; m < n - 1;)
	{
		cout << v[0].dis[0] << 't' << endl;
		for(int i = 0; i < n; ++i)
		{
			if(v[i].Getf() == 1) continue;
			else
			{
				for(int k = 0; k < n; ++k)
				{
					tmp[k] = v[i].dis[k];

				}

				
				tol += Min(tmp);

				++m;
			}
		}
	}
	cout << tol << endl;
	
	
}
