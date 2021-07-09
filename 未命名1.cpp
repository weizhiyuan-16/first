#include<iostream>
#include<queue>
#include<string>
#include<stack>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;//Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），
//Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆
string str = "";
string ans = "";

void judge(int N) {
	

	if (N == 0) {
		cout << str;
		return;
	}
	if (N == str.size()) {
		cout << 0;
		return;
	}
	deque<int> dq;
	dq.push_back(str[0]-'0');
	int i = 1;
	while(i < str.size()) {
		 while (!dq.empty() && str[i] - '0' > dq.back() && N > 0) {
			 dq.pop_back();
			 N--;
		 }
		 dq.push_back(str[i] - '0');
		 i++;

	}
	while (N > 0) {
		N--;
		dq.pop_back();
	}
	while (!dq.empty()) {
		ans += to_string(dq.front());
		dq.pop_front();
	}
	cout << ans;
}


int main() {
	int M, N;
	cin >> M >> N;
	q.push(1);
	for (int i = 0; i < M; ++i) {
		int t = q.top();
		str = str + to_string(t);
		q.pop();
		q.push(2 * t + 1);
		q.push(4 * t + 5);
	}
	cout << str << endl;
	judge(N);
	return 0;
}

