#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;
 
char s[1000];
int  g_pos;  // 字符数组的下标
 
/* 字符转数字 */
double Translation(int & pos)
{
    double integer = 0.00;    // 整数部分
    double remainder = 0.00;  // 小数部分
 
    while (s[pos] >= '0' && s[pos] <= '9')
    {
        integer *= 10;
        integer += (s[pos] - '0');
        pos++;
    }
 
    if (s[pos] == '.')
    {
        pos++;
        int c = 1;
        while (s[pos] >= '0' && s[pos] <= '9')
        {
            double t = s[pos] - '0';
            t *= pow(0.1, c);
            c++;
            remainder += t;
            pos++;
        }
    }
 
    return integer + remainder;
}
 
/* 返回运算符级别 */
int GetLevel(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
    case '%':
    	return 3;
    case '(':
        return 0;
    case '#':
        return -1;
    };
}
 
/* 对两个数进行运算 */
double Operate(double a1, char op, double a2)
{
	int a = a1;
    int b = a2;
    switch (op)
    {
    case '+':
        return a1 + a2;
    case '-':
        return a1 - a2;
    case '*':
        return a1 * a2;
    case '/':
        return a1 / a2;
    case '%':
    	return a % b;
    case '^':
    	return pow(a1,a2);
    };
}
 
/* 利用两个栈进行模拟计算 */
double Compute()
{
    stack<char> optr;    // 操作符栈
    stack<double> opnd;  // 操作数栈
 
	optr.push('#');      //置于符栈顶
    int len = strlen(s);
    bool is_minus = true;  // 判断是不是负号
 
    for (g_pos = 0; g_pos < len;)
    {
        //1. 负号
        if (s[g_pos] == '-' && is_minus)  // 是负号
        {
            opnd.push(0);
            optr.push('-');
            g_pos++;
        }
        //2. 是右括号 )
        else if (s[g_pos] == ')')
        {
            is_minus = false;
            g_pos++;
 
            while (optr.top() != '(' && optr.size() > 1)
            {
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();
 
                double result = Operate(a1, op, a2);
                opnd.push(result);
            }
            optr.pop();  // 删除'('
            if (optr.size() < 1)
            {
            	cout << "ERROR IN INFIX NOTATION" << endl;
            	return 0;
			}
        }
        //3. 数字
        else if (s[g_pos] >= '0' && s[g_pos] <= '9')
        {
            is_minus = false;
            opnd.push(Translation(g_pos));
        }
        //4. ( 左括号
        else if (s[g_pos] == '(')
        {
            is_minus = true;
            optr.push(s[g_pos]);
            g_pos++;
        }
        //5. + - * / ^ % 
        else if (s[g_pos] == '+' || s[g_pos] == '-' || s[g_pos] == '*' || s[g_pos] == '/' || s[g_pos] == '^' || s[g_pos] == '%' )
        {
            while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))    //当前优先级小于栈顶优先级
            {
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();
 
                double result = Operate(a1, op, a2);
                opnd.push(result);
            }
 
            optr.push(s[g_pos]);
            g_pos++;
        }
        //6.输入字符不属于数字或规定运算符 
        else
        {
        	cout << "ERROR IN INFIX NOTATION" << endl;
        	return 0;
		}
    }
    
    //对剩余的运算符及操作数进行计算 
    while (optr.top() != '#' && opnd.size() >= 2)
    {
        double a2 = opnd.top();
        opnd.pop();
        double a1 = opnd.top();
	    opnd.pop();
	    char op = optr.top();
	    double result = Operate(a1, op, a2);
        opnd.push(result);
        optr.pop();
    }
    optr.pop();
    //计算结束并弹出#后运算符栈仍不为空，说明最后弹出的不为#，有多余运算符 
	if (!optr.empty())
    {
    	cout << "ERROR IN INFIX NOTATION" << endl;
    	return 0;
	}
	else if(opnd.size() != 1)
    {
    	cout << "ERROR IN INFIX NOTATION" << endl;
    	return 0;
	}
	else
	{
	    cout << setiosflags(ios::fixed) << setprecision(2) << opnd.top() << endl;
	    return 0;
	}
	

}
 
int main()
{
    cin >> s;
    Compute();
    return 0;
}
