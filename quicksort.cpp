//#include<iostream>
//using namespace std;
//
//void QuickSort(int* arr, int low, int high, int n)
//{
//	int i = low;
//	int j = high;
//	int p = high + 1;
//	int flag;
//	while(i < j)
//	{
//		flag = 0;
//		for(; i < j;)
//		{
//			while(arr[i] < arr[p] && i < j) i++;
//			while(arr[j] > arr[p] && i < j) j--;
//			
//			
//			if(i < j && arr[i] > arr[j]) 
//			{
//				swap(arr[i], arr[j]);	
//				flag = 1;
//			}		
//		}
//		
//		
//		while(arr[i] < arr[p] && i < high + 1) ++i;
//		if(arr[i] > arr[p])
//		{
//			swap(arr[i], arr[p]);
//			flag = 1;
//		}	
//
//	    if(high == n - 2)
//	    {
//	    	int count = 1;
//	    	if(count == 1)
//	    	{
//		    	int k = 0;
//		    	for(; k < n; k++) 
//				{
//					cout << arr[k];
//					if(k != n - 1)cout << ' ';
//				}
//				cout << endl;
//				count++;	    		
//			}
//			
//		}        
//		if(!flag)--high;
//		if(high > 0)QuickSort(arr, low, high, n);
//		
//    }
//
//	
//}
//
//int main()
//{
//	int n;
//	int* data;
//	cin >> n;
//	data = new int[n];
//
//	for(int i = 0; i < n; i++) cin >> data[i];
//	QuickSort(data, 0, n - 2, n);
//	for(int i = 0;i < n; ++i)
//	{
//		cout << data[i];
//		if(i != n - 1)cout << ' ';
//	}
//	    
//	cout << endl;		
//	return 0;
//}
////8 20 15 14 18 21 36 40 10

#include<iostream>
#include<algorithm>
using namespace std;

int n;
int* num;
void QuickSort(int low, int high, int depth) 
{
	if (low > high)return;
	int L = low, R = high;
	int pivot = num[high];
	while (L < R) {
		while (L < R && num[L] < pivot)++L;
		while (L < R && num[R] >= pivot)--R;
		swap(num[L], num[R]);
	}
	swap(num[L], num[high]);
	if (!depth)
		for (int i = 0; i < n; ++i) 
		{
			cout << num[i];
			if (i != n - 1)cout << " ";
		}
	QuickSort(low, L - 1, depth + 1);
	QuickSort(L + 1, high, depth + 1);
}
int main() 
{
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = rand() % 100;
	}
	QuickSort(0, n - 1, 0);
	cout << endl;
	for (int i = 0; i < n; ++i) 
	{
		cout << num[i];
		if (i != n - 1)cout << " ";
	}
	return 0;
}

