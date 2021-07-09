#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        vector<vector<int>> res(m, vector<int>(n));
        /*������һ��vector������Ԫ������Ϊvector<int>��
		��ʼ��Ϊ����m��vector<int>����
		ÿ��������һ���´�����vector<int>����Ŀ�����
		������´�����vector<int>���󱻳�ʼ��Ϊ����n��0��*/
        for(int i = 0; i < m; i++)
        {
        	for (int j = 0; j < n; j++) cin >> res[i][j];
		}

        int row = res.size();
        int col = res[0].size();
        int left = 0, right = col-1, top = 0, bottom = row-1;
        vector<int> s;
        
        while(left <= right && top <= bottom) 
        {
        	//˳ʱ�롣 
            for(int i = left; i <= right; i++) s.push_back(res[top][i]);

            for(int i = top + 1; i <= bottom; i++) s.push_back(res[i][right]); 
			   
            if(top != bottom)
            {
                 for(int i = right - 1; i >= left; i--) s.push_back(res[bottom][i]);    
            }

            if(left != right)
            {
                 for(int i = bottom - 1;i >= top + 1 ; i--) s.push_back(res[i][left]);    
            }
            left++, top++, right--, bottom--;
            
            //��ʱ�롣 
            if(left < right && top < bottom)
            {
				for(int i = top; i <= bottom ; i++) s.push_back(res[i][left]);
	            
	            for(int i = left + 1; i <= right ; i++) s.push_back(res[right-1][i]);
	            
	            if(left != right)
	            {
	            	for(int i = bottom - 1; i >= top; i--) s.push_back(res[i][right]);
				}
				if(top != bottom)
				{
					for(int i = right - 1; i >= left + 1; i--) s.push_back(res[top][i]);
				}
				left++, top++, right--, bottom--;
			}
        }
        for(int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1)
                cout << s[i] << endl;
            else
                cout << s[i] << ' ';
        }
        
    }
    return 0;
}

