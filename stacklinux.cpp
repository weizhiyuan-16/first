//这个是别人的，你试下你的思路。 
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
        //读取一个完整的目录名称；
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
我的思路是：
首先要遇到一个'/'。 
1.遇到'/'：1个入栈 
2.遇到'.'：（1）2个：出栈直到出了一个'/';(2)1个：入栈
3.遇到字母：全部入栈。
最后如果栈顶为'.'则让它出栈，并使'/'也出栈。 
*/ 
