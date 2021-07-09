#include<iostream>
using namespace std;
int flag = 0; 
void IsHeap(int num[], int n) 
{
	bool isMax = true, isMin = true;
	int lChild, rChild;
	for (int i = 1; i <= n; ++i) 
	{
		lChild = i * 2;
		rChild = i * 2 + 1;
		if (rChild <= n) 
		{
			if (num[i] == num[lChild] && num[i] == num[rChild])continue;//结点与孩子相等，可以是最大堆也可以是最小堆。 
			else if (num[i] <= num[lChild] && num[i] <= num[rChild])//结点的左右孩子都不比它小，故不是最大堆。 
				isMax = false;
			else if (num[i] >= num[lChild] && num[i] >= num[rChild])//结点的左右孩子都不比它大，故不是最小堆。 
				isMin = false;
			else
			{
				isMax = isMin = false;
				break;
			}
		}
		else if (lChild <= n) 
		{
			if (num[i] == num[lChild])continue;
			else if (num[i] < num[lChild])
				isMax = false;
			else if (num[i] > num[lChild])
				isMin = false;
			else 
			{
				isMax = isMin = false;
				break;
			}
		}
	}
	//四种结果 
	if (isMax == true) 
	{
		if (isMin == false)flag = 1;
		if (isMin == true)flag = 3;
	}
	else 
	{
		if (isMin == true)flag = 2;
		if (isMin == false)flag = 4;
	}
}
void BuildMaxHeap(int num[], int n) //生成最大堆 
{
	for (int i = n / 2; i >= 1; --i) 
	{
		int t = num[i];//结点 
		int c = i * 2;//左孩子 
		while (c <= n) 
		{
			if (c < n && num[c] <= num[c + 1])
				c++;
			if (t < num[c]) //结点小于左孩子 
			{
				num[c / 2] = num[c];//将左孩子的值赋给结点 
				c *= 2;//到下一层 
			}
			else break;
		}
		num[c / 2] = t;//将原结点的值赋给左孩子 
	}
}

void BuildMinHeap(int num[], int n) //生成最小堆 
{
	for (int i = n / 2; i >= 1; --i) 
	{
		int t = num[i];
		int c = i * 2;
		while (c <= n) 
		{
			if (c < n && num[c] >= num[c + 1])
				c++;
			if (t > num[c]) 
			{
				num[c / 2] = num[c];
				c *= 2;
			}
			else break;
		}
		num[c / 2] = t;
	}
}
void BuildHeap(int num[], int n) 
{

	if (flag == 1) 
	{
		cout << "max ";
		BuildMinHeap(num, n);
	}
	if (flag == 2) 
	{
		cout << "min ";
		BuildMaxHeap(num, n);
	}
	if (flag == 3) 
	{
		cout << "max min" << endl;
		return;
	}
	if (flag == 4) 
	{
		BuildMaxHeap(num, n);
	}
	for (int i = 1; i <= n; ++i) 
	{
		if (i == n)cout << num[i];
		else cout << num[i] << " ";
	}
}
int main() {
	int n, num1[1001];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> num1[i];
	IsHeap(num1, n);
	BuildHeap(num1, n);
	return 0;
}

