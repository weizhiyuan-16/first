#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 32;
int w[N], v[N], d[N];

int main(){
	memset(d, 0, sizeof(d));
	memset(w, 0, sizeof(w));
	memset(v, 0, sizeof(v));
	int maxw, n;
	cin >> maxw >> n;
	for(int i = 1; i <= n; ++i){
		cin >> w[i] >> v[i];
		for(int j = maxw; j >= w[i]; --j){
			d[j] = max(d[j], d[j - w[i]] + v[i]);
		}
	}
	cout << d[maxw] << endl;
	return 0;
}
