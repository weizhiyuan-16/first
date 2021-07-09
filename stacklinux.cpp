//����Ǳ��˵ģ����������˼·�� 
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string simplifyPath(string path) 
{
    stack<string> temp;
    int i = 0, j = 0;
    while(i < path.size() - 1)
    {
        j = i + 1;
        //��ȡһ��������Ŀ¼���ƣ�
        while(path[j] != '/') ++j; 
        if(i + 1 == j)
        {
            i = j;
            continue;
        }
        string s = path.substr(i, j - i);
        
        
        if("/." == s)
        {
            i = j;
            continue;
        }
        if("/.." == s && !temp.empty())  temp.pop();
        else if("/.." == s && temp.empty()) ;
        else 
            temp.push(s);
        i = j;
    }
    if(temp.empty()) return "/";
    else
    {
        string res;
        while(!temp.empty())
        {
            res = temp.top() + res;
            temp.pop();
        }
        return res;
    }
}
int main()
{
    string s;
    cin >> s;
    cout << simplifyPath(s);
}
/* 
�ҵ�˼·�ǣ�
����Ҫ����һ��'/'�� 
1.����'/'��1����ջ 
2.����'.'����1��2������ջֱ������һ��'/';(2)1������ջ
3.������ĸ��ȫ����ջ��
������ջ��Ϊ'.'��������ջ����ʹ'/'Ҳ��ջ�� 
*/ 
