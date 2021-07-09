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
int  g_pos;  // �ַ�������±�
 
/* �ַ�ת���� */
double Translation(int & pos)
{
    double integer = 0.00;    // ��������
    double remainder = 0.00;  // С������
 
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
 
/* ������������� */
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
 
/* ���������������� */
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
 
/* ��������ջ����ģ����� */
double Compute()
{
    stack<char> optr;    // ������ջ
    stack<double> opnd;  // ������ջ
 
	optr.push('#');      //���ڷ�ջ��
    int len = strlen(s);
    bool is_minus = true;  // �ж��ǲ��Ǹ���
 
    for (g_pos = 0; g_pos < len;)
    {
        //1. ����
        if (s[g_pos] == '-' && is_minus)  // �Ǹ���
        {
            opnd.push(0);
            optr.push('-');
            g_pos++;
        }
        //2. �������� )
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
            optr.pop();  // ɾ��'('
            if (optr.size() < 1)
            {
            	cout << "ERROR IN INFIX NOTATION" << endl;
            	return 0;
			}
        }
        //3. ����
        else if (s[g_pos] >= '0' && s[g_pos] <= '9')
        {
            is_minus = false;
            opnd.push(Translation(g_pos));
        }
        //4. ( ������
        else if (s[g_pos] == '(')
        {
            is_minus = true;
            optr.push(s[g_pos]);
            g_pos++;
        }
        //5. + - * / ^ % 
        else if (s[g_pos] == '+' || s[g_pos] == '-' || s[g_pos] == '*' || s[g_pos] == '/' || s[g_pos] == '^' || s[g_pos] == '%' )
        {
            while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))    //��ǰ���ȼ�С��ջ�����ȼ�
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
        //6.�����ַ����������ֻ�涨����� 
        else
        {
        	cout << "ERROR IN INFIX NOTATION" << endl;
        	return 0;
		}
    }
    
    //��ʣ�������������������м��� 
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
    //�������������#�������ջ�Բ�Ϊ�գ�˵����󵯳��Ĳ�Ϊ#���ж�������� 
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
