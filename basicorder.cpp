#include <iostream>
using namespace std;

void print(int data[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<data[i]<<' '; 
	}
	cout<<endl;
}

int maxbit(int data[],int n){
	int num=1;
	int p=10;
	for (int i=0;i<n;i++){
		while(data[i]/p!=0){
			num++;
			p *=10;
		}
	}
	return num;
}


void radixsort(int data[],int n){
	int tmp[n],count[10];
	int max=maxbit(data,n);
	int radix=1;
	int k;
	for(int j=1;j<=max;j++){
		for(int i=0;i<10;i++){
			count[i]=0;
		}
		for(int a=0;a<n;a++){
			k=(data[a]/radix)%10;
			count[k]++;
		}
		for(int i=1;i<10;i++){
			count[i]=count[i-1]+count[i];
		}
		for(int i=0;i<n;i++){
			k=(data[i]/radix)%10;
			tmp[count[k]-1]=data[i];
			count[k]--;
		}
		for(int i=0;i<n;i++){
			data[i]=tmp[i];
		}
		print(data,n);
		radix*=10;
	}
		
	
}

int main(){
	int n;
	cin>>n;
	int data[n];
	
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	radixsort(data,n);
	return 0;
}
