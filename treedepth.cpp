#include<iostream>
using namespace std;
 
int GetHeight(char* pre,char* in,int n)   //��������ĸ߶�
{
    if(n == 0)    //��û�н�㣬Ϊ����
    {
        return 0;
    }
    int i;
    for(i = 0; i < n; i++)
    {
        if(in[i] == pre[0])  //�ҵ�������������λ��
        {
            break;
        }
    }
    int left = GetHeight(pre + 1, in, i);  //�����������
    int right = GetHeight(pre + i + 1, in + i + 1, n - i - 1);   //�����������
    return max(left, right) + 1;  //��������������ȵĽϴ�ֵ�еĽϴ�ֵ+�����
}
int main()
{
    int n;
    cin >> n;
    char pre[n + 1], in[n + 1];  //���������
    cin >> pre >> in;
    cout << GetHeight(pre, in, n) << endl;
    return 0;
}


 
