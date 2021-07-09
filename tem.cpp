#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct subject{
	int bonus;
	int ddl;
	string course;
	int effort;
};
//按ddl排序，由大到小（截止日期晚的先处理）,ddl相同的按bonus由大到小排序 
static bool cmpDDL(const subject& s1, const subject& s2){
	if(s1.ddl != s2.ddl){
		return s1.ddl > s2.ddl;
	}
	else{
		return s1.bonus > s2.bonus;
	}
}



//字典序由小到大 
static bool cmpLx(const subject& s1, const subject& s2){
	return s1.course < s2.course;
}

class compare{
	public:
		bool operator()(subject& s1, subject& s2) const{
			//结果按字典序由小到大排序 
			if(s1.bonus == s2.bonus){
				return s1.course > s2.course;
			}
			//结果按bonus由大到小排序 
			return s1.bonus < s2.bonus;
		} 
};


int main(){
	int N, bonus, ddl, effort;
	string course;
	cin >> 	N;
	vector<subject> s;
	int max = 0;
	int maxdate = 0;
	
	for(int i = 0; i < N; ++i){
		cin >> bonus >> ddl >> course >> effort;
		struct subject a = {bonus, ddl, course, effort};
		s.push_back(a);
		if (ddl > maxdate) maxdate = ddl; 
	}
	sort(s.begin(),s.end(),cmpDDL);
	priority_queue<subject, vector<subject>, compare> q;
	vector <subject> result;
	while(maxdate){
		//将最晚截止的任务压入队列中（按bonus排序，bonus大的在队头） 
		while(s.size() && s[0].ddl == maxdate){
			q.push(s[0]);
			s.erase(s.begin());
		}
		if(!q.empty()){
			struct subject temp = q.top();
			max += temp.bonus;
			struct subject a = {1, 1, temp.course, temp.effort};
			bool find = false;
			//合并结果中相同的课程 
			for(int i = 0; i < result.size(); ++i){
				if(result[i].course == temp.course){
					result[i].effort += temp.effort;
					find = true;
					break; 
				}
			}
			if(!find) result.push_back(a);
			q.pop();
		}
		maxdate--;
	}
	sort(result.begin(), result.end(), cmpLx); 
	cout  << max << endl;
	for(int i = 0; i < result.size(); ++i){
		cout << result[i].course << " " << result[i].effort << endl;
	}
	return 0;
	
	
	
}
