#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* num = new int[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	int min = 1;
	while(1)
	{
		int i = 0;
		for(; i + min < n;)
		{
			if(num[i] <= num[i + min]) i++;
			else break;
		}
		if(i + min < n) ++min;
		else break;		
	}
	cout << min << endl;

}

//15 18 13 5 9 10 9 19 24 17 20 17 9 20 24 21
