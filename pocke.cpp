#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int n,minmn;
	cin >> n >> minmn;
	int ans = 0 ;
	pair<int,int> coin;
	vector<pair<int,int>> pocket;
	for(int i = 0; i < n; ++i){
		cin >> coin.first >> coin.second;
		pocket.push_back(coin);
	}
	sort(pocket.begin(),pocket.end());
	
	while(!pocket.empty()){
		int temp = minmn;
		for(int i = pocket.size() - 1;i >= 0; --i){
			pair<int,int>& tmp = pocket.at(i);
			//��С����С��Ǯ��������Ӳ�ҿ�ʼȡ����ǡ��Ϊ��С��Ǯʱ�����ֱ��ʹ�ã���������С����Ӳ�Ҵա� 
			while(tmp.first <= temp && tmp.second > 0){
				temp -= tmp.first;
				--tmp.second;
			} 
			//����Ӳ������ 
			if(tmp.second == 0){
				pocket.erase(pocket.begin() + i);
			}
		}
			//�õ�ǰ���ڵ���С����Ӳ�Ҵգ�ʹ��ֵ������С��Ǯ 
			if(temp > 0){
				for(int j = 0; j < pocket.size(); ++j){
					pair<int,int>& tmp = pocket.at(j);
					while(temp > 0 && tmp.second > 0){
						temp -= tmp.first;
						--tmp.second;
					}
					if(tmp.second == 0){
						pocket.erase(pocket.begin() + j);
					}
					if(temp <= 0){
						break;
					}
				}
				
			}
			//Ǯ���� 
			if(temp > 0){
				break;
			}
			else{
				++ans;
			}
		
			
			
		
	}
	cout << ans << endl;
	return 0;
	
	
	
	

}
//�򠑴Չ��������Xminmn�ĽM�ϲ����̶������Բ���һ�δՉ�ܶ���minmn ��Ҫ�ֳ�һ��һ����ȥ���F�� 
