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
			if (num[i] == num[lChild] && num[i] == num[rChild])continue;//����뺢����ȣ�����������Ҳ��������С�ѡ� 
			else if (num[i] <= num[lChild] && num[i] <= num[rChild])//�������Һ��Ӷ�������С���ʲ������ѡ� 
				isMax = false;
			else if (num[i] >= num[lChild] && num[i] >= num[rChild])//�������Һ��Ӷ��������󣬹ʲ�����С�ѡ� 
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
	//���ֽ�� 
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
void BuildMaxHeap(int num[], int n) //�������� 
{
	for (int i = n / 2; i >= 1; --i) 
	{
		int t = num[i];//��� 
		int c = i * 2;//���� 
		while (c <= n) 
		{
			if (c < n && num[c] <= num[c + 1])
				c++;
			if (t < num[c]) //���С������ 
			{
				num[c / 2] = num[c];//�����ӵ�ֵ������� 
				c *= 2;//����һ�� 
			}
			else break;
		}
		num[c / 2] = t;//��ԭ����ֵ�������� 
	}
}

void BuildMinHeap(int num[], int n) //������С�� 
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

