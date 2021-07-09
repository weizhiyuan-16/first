#include <iostream>
#include <algorithm>
using namespace std;


int n,m;
int* a;


bool judge(int x){
	int last = 0;
	for(int i = 1; i < m; ++i){
		int cnt = last + 1;
		while(cnt < n && a[cnt] - a[last] < x){
			cnt++;
		}
		//x偏大 
		if(cnt == n)return false;
		last = j;
	}
	//x偏小或刚好 
	return true;
}

int main(){
	cin >> n >> m;
	a = new int[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a,a + n);
	int left = 0;
	int right = a[n - 1] ;
	while(left < right){
		int mid = (left + right + 1) >> 1;
		//预估的最小间隔偏小 
		if(judge(mid)){
			left = mid;
		}
		//预估的最小间隔偏大 
		else{
			right = mid - 1;

		}
		
	}
	cout << right;
	return 0;
}
