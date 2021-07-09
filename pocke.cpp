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
			//从小于最小零钱的最大面额硬币开始取，和恰好为最小零钱时，则可直接使用，不用再用小面额的硬币凑。 
			while(tmp.first <= temp && tmp.second > 0){
				temp -= tmp.first;
				--tmp.second;
			} 
			//该种硬币用完 
			if(tmp.second == 0){
				pocket.erase(pocket.begin() + i);
			}
		}
			//用当前存在的最小面额的硬币凑，使总值超过最小零钱 
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
			//钱不够 
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
//因爲凑夠最少零錢minmn的組合并不固定，所以不能一次凑夠很多個minmn ，要分成一個一個的去實現。 
