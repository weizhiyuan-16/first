#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

const int INF = 100000;
const int MAXN = 101;
int vis[MAXN], map[MAXN][MAXN], low[MAXN];
int flag, N;
int answer;

void prim() {
	memset(vis, 0, sizeof(vis));
	int temp, k;
	answer = 0;
	flag = 1;
	vis[2] = 1;//从2开始访问 
	//low用于记录 U-V到V的最小距离 
	for (int i = 1; i <= N; ++i)low[i] = map[2][i];
	for (int i = 1; i < N; ++i) {
		temp = INF;
		
		//用temp记录当前U-V与V的最小距离 
		for (int j = 1; j <= N; ++j) {
			if (!vis[j] && low[j] < temp) 
				temp = low[k = j];
		}
		int x = 0;
		
		//x记录将要加入V的点与U-V中距离最短的路径条数 
		for (int j = 1; j <= N; ++j) {
			if (vis[j]&&map[k][j] == temp)++x;
			if (x > 1) {
				flag  = 0;
				return;
			}
		}
		//将k加入V 
		vis[k] = 1;
		answer += temp;
		//更新最短距离
		for (int j = 1; j <= N; ++j) {
			if (!vis[j] && map[k][j] < low[j])
				low[j] = map[k][j];
		}
	}

}
int main() {
	int E, st, ed, dis;
	memset(map, INF, sizeof(map));
	scanf("%d %d", &N, &E);
	while (E--) {
		cin >> st >> ed >> dis;
		if (dis < map[st][ed])
			map[st][ed] = map[ed][st]= dis;
	}
	prim();
	if (flag) {
		printf("Daniel %d\n", answer);
	}
	else printf("Tom -1\n");
	return 0;
}
