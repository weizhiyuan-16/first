#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool loop(int a[20][20], int N)
{
	 queue<int> q;
	 int* in = new int[N];
	 int* visit = new int[N];
	 for(int i = 0; i < N; ++i)
	 {
	 	visit[i] = 0;
	 	in[i] = 0;
	 }
	 for(int i = 0; i < N; ++i)
	 {
	 	for(int j = 0; j < N; ++j)
	 	{
	 		if(a[i][j] != -1)++in[i];
		}
	 }
	 for(int i = 0; i < N; ++i)
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
	 	for(int i = 0; i < N; ++i)
	 	{
	 		if(a[i][t] != -1) --in[i];
		}
		for(int i = 0; i < N; ++i)
		{
			if(in[i] == 0 && visit[i] == 0)
			{
				q.push(i);
				visit[i] = 1;
			}
		}
		q.pop();
	 }
	 for(int i = 0; i < N; ++i)
	 {
	 	if(visit[i] == 0)return false;
	 }
	 return true;
	
}

int maxpath(int* e, int a[20][20], int N, int s)
{
	 int* et = new int[N];
	 int* flag = new int[N];
	 for(int i = 0; i < N; ++i)
	 {
	 	et[i] = 0;
	 	flag[i] = 0;
	 }
	 queue<int> q;
	 q.push(s);
	 while(!q.empty())
	 {
	 	int t = q.front();
	 	for(int i = 0; i < N; ++i)
	 	{
	 		if(a[i][t] != -1)
	 		{
	 			q.push(i);
	 			et[i] = (et[i] > (et[t] + a[i][t]) ? et[i] : et[t] + a[i][t]);
	 			flag[t] = 1;
			 }
		 }
		 q.pop();
	 }
	 for(int i = 0; i < N; ++i)
	 {
		et[i] += e[i];
	 }
	 int max = 0;
	 for(int i = 0; i < N; ++i)
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
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			a[i][j] = -1;
		}
	}
	for(int i = 0; i < N; ++i)
	{
		getline(cin, s);
		int k = 2;
		if(s[k] == ' ' && s[k]) ++k;
		if(k < s.length() - 1 && s[k + 1] == ' ' || k == s.length() - 1)
		{
			e[i] = s[k] - '0';
			k += 2;
		}
		while(k < s.length() - 1 && s[k + 1] == ';')
		{
			a[i][s[k] - '0' - 1] = e[s[k] - '0' - 1];
			k += 2;
		}
		
	}
	if(!loop(a, N))//²»³ÉAOEÍ¼; 
	{
		cout << "error" << endl;
		return 0;
	 }
	 else
	 {
	 	int max = 0;
	 	for(int i = 0; i < N; ++i)
	 	{
	 		int flag = 0;
	 		for(int j = 0; i < N; ++j)
	 		{
	 			if(a[i][j] != -1)
	 			{
	 				flag = 1;
	 				break;
				 }
			 }
			 if(flag == 0)
			 {
			 	int t = maxpath(e, a, N, i);
			 	if(t > max) max = t;
			 }
		 }
		 cout << max << endl;
	}
	
	return 0; 

}
