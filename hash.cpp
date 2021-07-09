#include<iostream>
#include<string.h>
using namespace std;

int n,seed;
int randI() {
	return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}
int rand32() {
	return ((randI() << 16) + (randI() << 1) + randI() % 2);
}
int maxGap(int arr[]) {
	int minN = arr[0], maxN = arr[0]; 
	//遍历找到数组中最大值最小值。 
	for (int i = 0; i < n; ++i) 
	{
		if (arr[i] > maxN)maxN = arr[i];
		if (arr[i] < minN)minN = arr[i];
	}
	if (maxN == minN)return 0;
    //构造n+1个桶。 
	bool* hasNum = new bool[n + 1];
	memset(hasNum, 0, sizeof(bool) * (n + 1));
	int* mins = new int[n + 1];
	int* maxs = new int[n + 1];
	//遍历数组 找到每个桶中max min。 
	for (int i = 0; i < n; ++i) 
	{
		//double gap = double(maxN - minN + 1) / (n + 1);
		double gap = double(maxN - minN) / (n - 1);
		int index = int((arr[i] - minN) / gap); //几号桶。  
		if (!hasNum[index])  
		{
			mins[index] = maxs[index] = arr[i];
			hasNum[index] = true;
		}
		else 
		{
			mins[index] = min(arr[i], mins[index]);
			maxs[index] = max(arr[i], maxs[index]);
		}
	}

	int maxGap = 0;
	int lastMax = maxs[0];
	for (int i = 1; i <= n; i++) 
	{
		if (hasNum[i]) //不是空桶。 
		{
			maxGap = max(maxGap, (mins[i] - lastMax));
			//cout << mins[i] << ' ' << lastMax << endl;
			lastMax = maxs[i];
		}
	}

	delete[]hasNum;
	delete[]maxs;
	delete[]mins;
	return maxGap;
}
int main() {
	cin >> n >> seed;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		arr[i] = rand32();
	cout << maxGap(arr) << endl;
	delete[]arr;
	return 0;
}
