#include<iostream>
using namespace std;

void QuickSort(int* arr, int low, int high)
{
	int i = low, j = high;
	int pivot = arr[high + 1];
	while(i < j)
	{
		while(arr[i] < pivot) ++i;
		while(arr[j] > pivot) --j;
		if(i < j && arr[i] > arr[j]) 
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;

		}
		while(arr[i] < pivot) ++i;
		swap(arr[i], pivot);
    }
	    
	
	if(i-1>low)
	    QuickSort(arr,low,i-1);
	if(j+1<high)
		QuickSort(arr,j+1,high);
}

int main()
{
	int n;
	int* data;
	cin >> n;
	data = new int[n];
	for(int i = 0; i < n; i++) 
	    cin >> data[i];
	QuickSort(data, 0, n - 2);
	for(int i = 0;i < n; ++i)
	    cout << data[i] << " ";
	cout << endl;		
	return 0;
}
