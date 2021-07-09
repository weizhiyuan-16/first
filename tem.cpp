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
//��ddl�����ɴ�С����ֹ��������ȴ���,ddl��ͬ�İ�bonus�ɴ�С���� 
static bool cmpDDL(const subject& s1, const subject& s2){
	if(s1.ddl != s2.ddl){
		return s1.ddl > s2.ddl;
	}
	else{
		return s1.bonus > s2.bonus;
	}
}



//�ֵ�����С���� 
static bool cmpLx(const subject& s1, const subject& s2){
	return s1.course < s2.course;
}

class compare{
	public:
		bool operator()(subject& s1, subject& s2) const{
			//������ֵ�����С�������� 
			if(s1.bonus == s2.bonus){
				return s1.course > s2.course;
			}
			//�����bonus�ɴ�С���� 
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
		//�������ֹ������ѹ������У���bonus����bonus����ڶ�ͷ�� 
		while(s.size() && s[0].ddl == maxdate){
			q.push(s[0]);
			s.erase(s.begin());
		}
		if(!q.empty()){
			struct subject temp = q.top();
			max += temp.bonus;
			struct subject a = {1, 1, temp.course, temp.effort};
			bool find = false;
			//�ϲ��������ͬ�Ŀγ� 
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
