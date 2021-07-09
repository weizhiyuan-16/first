#include<iostream>
using namespace std;

void reverse(int num[], int begin, int end) 
{
	while (begin < end)
		swap(num[begin++], num[end--]);
}
void exchange(int num[], int begin, int mid, int end) 
{
	reverse(num, begin, mid - 1);
	reverse(num, mid, end);
	reverse(num, begin, end);
	}

int main() 
{
	int n, m;
	int num[50];
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
		cin >> num[i];

	int p1, p2;
	p1 = 0;
	p2 = n;
	while (p1 < p2 && p2 < n + m) {
		while (p1 < p2 && num[p1] <= num[p2])
			p1++;

		int mid = p2;
		while (p2 < n + m && num[p2] < num[p1]) {
			p2++;
		}
		exchange(num, p1, mid, p2 - 1);
		p1 += (p2 - mid);
	}

	for (int i = 0; i < n + m; i++) {
		if (i == 0)cout << num[i];
		else  cout << ' ' << num[i];
	}
	return 0;
}
//O(mn)
