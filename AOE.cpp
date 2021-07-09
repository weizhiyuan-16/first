#include<iostream>
#include<string>
#include<queue>
using namespace std;

int loop(int a[20][20],int N)//判断依赖关系是否成立 
{
	queue<int> q;
	int* in = new int[N];
	int* visit = new int[N];
	for(int i = 0; i < N; i++) 
	{
		in[i] = 0;
		visit[i] = 0;
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] != -1)
				in[j]++;				
	    }
	}

	for(int i = 0; i < N; i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
			visit[i] = 1;
			break;
		}		
	}

	while(!q.empty())
	{
		int t = q.front();
		for(int i = 0; i < N; i++)
		{
			if(a[t][i] != -1) in[i]--;
		}
		for(int i = 0; i < N; i++)
		{
			if(in[i] == 0 && visit[i] == 0)
			{
				q.push(i);
				visit[i] = 1;
		    }			
		}

		q.pop();
	}

	for(int i = 0; i < N; i++)
	{
		if(visit[i] == 0)return -1;
	}

	return 0;

}

int maxpath(int s, int a[20][20], int N, int* e)
{
	int* et = new int[N];
	int* flag = new int[N];
	for(int i = 0; i < N; i++)
		{
			et[i] = 0;
			flag[i] = 0;
		}

	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t = q.front();
		for(int i = 0; i < N; i++)
			if(a[t][i] != -1)
			{
				q.push(i);
				et[i] = (et[i] > et[t] + a[t][i]) ? et[i] : et[t] + a[t][i];
				flag[t] = 1;//后面的时间已包括该阶段消耗时间; 
			}

		q.pop();
	}

	for(int i = 0; i < N; i++)
		et[i] += e[i];

	int max = 0;
	for(int i = 0; i < N; i++)
	{
		if(flag[i] == 0 && et[i] > max) 
		{
			max = et[i];
		}
    }
		

	return max;
}

int main()
{
	int N;
	string s;
	cin >> N;
	getchar();
	int a[20][20];
	int* e = new int[N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			a[i][j] = -1;		
	}


	for(int i = 0; i < N; i++)
	{
		getline(cin, s);//istream& getline ( istream &is , string &str , char delim );默认的char delim为'\n'; 
		int k = 2;
		if(s[k] == ' ') k++;

		if((k + 1 < s.length() && s[k + 1] == ' ') || k == s.length() - 1)
			{
				e[i] = s[k] - '0';//存入活动消耗的时间 
				k += 2;
				
			}
		else 
		{
			e[i] = 10 * (s[k] - '0') + s[k + 1] - '0';
			k += 3;
		}

		while(k + 1 < s.length())
		{
			if(s[k+1] == ';')
				{
					a[s[k] - '0' - 1][i] = s[k] - '0' - 1;
					k += 2;
				}
			else 
			{
				a[(s[k] - '0' - 1) * 10 + s[k + 1]- '0' - 1][i] = (s[k] - '0' -1 ) * 10 + s[k + 1] -'0' - 1;
				k += 3;
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] != -1) a[i][j] = e[a[i][j]];				
		}	
	}


	if(loop(a,N) == -1)
	{
		cout << "error" << endl;
		return 0;
	}
	else
	{
	    int max = 0;
		for(int i = 0; i < N; i++)
		{
			int flag = 0;
			for(int j = 0; j < N; j++)
			{
				if(a[j][i] != -1)
					{
						flag = 1;
						break;
					}				
			} 
			if(flag == 0)
				{
					int t = maxpath(i, a, N, e);
					if(t > max)max = t;
			    }
	    }

	cout << max << endl;
	
	return 0;
	}
}
