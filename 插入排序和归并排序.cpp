#include<iostream>
using namespace std;

int num[101], numM[101], mid[101];
int main()
{
	int n, flag = 1;
	int i, j;
	cin >> n;
	for (i = 0; i < n; ++i) 
	{
		cin >> num[i];
		numM[i] = num[i];
	}
	for (i = 0; i < n; ++i) cin >> mid[i];

	flag = 0;
	for (i = 1; i < n; ++i) 
	{
		//先check
		int k;
		for (k = 0; k < n; ++k)
		{
			if (num[k] != mid[k])break;
			
		} 
		if (k == n)
			flag = 1;

		//再insert sort
		int x = num[i];
		j = i - 1;
		while (j >= 0 && num[j] > x) 
		{
			num[j + 1] = num[j];
			--j;
		}
		num[j + 1] = x;

		if (flag == 1) {
			cout << "Insertion Sort" << endl;
			for (i = 0; i < n; ++i) 
			{
				cout << num[i];
				if (i != n - 1)cout << " ";
			}
			return 0;
		}
	}

	//merge sort
	for (int step = 1; step < n; step *= 2) 
	{
		//先check
		int k;
		for (k = 0; k < n; ++k)
			if (numM[k] != mid[k])break;
		if (k == n)
			flag = 1;

		//再merge sort
		int tmp[21], cnt = 0;
		i = 0;
		while (i < n) 
		{
			int l = i, r = i + step;
			while (l < i + step && r < i + 2 * step && r < n) 
			{
				if (numM[l] <= numM[r])
					tmp[cnt++] = numM[l++];
				else
					tmp[cnt++] = numM[r++];
			}
			if (l >= i + step)
				while (r < i + 2 * step && r < n)
					tmp[cnt++] = numM[r++];
			else
				while (l < i + step && l < n)
					tmp[cnt++] = numM[l++];
			i += 2 * step;
		}
		for (i = 0; i < n; ++i)
			numM[i] = tmp[i];
		if (flag == 1) {
			cout << "Merge Sort" << endl;
			for (i = 0; i < n; ++i) {
				cout << numM[i];
				if (i != n - 1)cout << " ";
			}
			return 0;
		}
	}
}
/*10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0 */
