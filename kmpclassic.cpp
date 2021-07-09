#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
int kmp(char* P,char* T)//使用KMP算法匹配的函数
{
int num1=0,num2=0;
int next[100]={-2};
int t=0;
next[0]=-1;
next[1]=0;
int i=1;
for(;P[i]!=0;)//生成next数组
{
num1++;
if(P[i]==P[t]||t==-1)
{
next[++i]=++t;
}
else t=next[t];
num1++;
}
int k=0;//与主串匹配
for(int j=0;T[j]!=0;)
{
num2++;
if(T[j]==P[k]||k==-1)
{
j++;k++;
}
else k=next[k];
num2++;
if(k==i)
{
cout<<"预处理次数："<<num1<<endl;
cout<<"比较次数： "<<num2<<endl;
return j-1;
}
num2++;
}
cout<<"匹配不成功 "<<endl;
cout<<"预处理次数： "<<num1<<endl;
cout<<"比较次数： "<<num2<<endl;
return -1;
}
int bm(char* P,char* T)//使用BM算法匹配的函数
{
int num1=0,num2=0;
int ss[100]={0},gs[100]={0};
int m=0,n=0;
for(;P[n]!=0;n++);//获得主串长度和模式串长度
for(;T[m]!=0;m++);
for(int i=0;i<n;i++)//生成ss数组
{
int j=0;
num1++;
for(;i-j>=0;j++)
{
if(P[i-j]!=P[n-1-j])break;
num1++;num1++;
}
num1++;
ss[i]=j;
}
for(int i=0;i<n;i++)//根据ss数组生成gs数组
{
int q=n-1-i;
int flag=0;
for(int k=i-1;k>=0;k--)
{
num1++;
if(ss[k]==q)
{
gs[i]=n-1-k;
flag=1;
break;
}
num1++;
}
if(flag==0)
for(int k=i-1;k>=0;k--)
{
num1++;
if(ss[k]<q&&ss[k]==k+1)
{
gs[i]=n-k-1;
flag=1;
break;
}
num1++;
}
if(flag==0)gs[i]=n;
num1++;
}
int i=0,j=n-1;//与主串匹配
for(i=n-1;i<m;)
{
num2++;
if(P[j]==T[i])
{
i--;
j--;
if(j==-1)
{

cout<<"预处理次数： "<<num1<<endl;
cout<<"比较次数： "<<num2<<endl;
return i+1;
}
num2++;
}
else
{
i+=gs[j];
j=n-1;
num2++;
}
num2++;
}
cout<<"匹配不成功 "<<endl;
cout<<"预处理次数： "<<num1<<endl;
cout<<"比较次数： "<<num2<<endl;

return -1;
}
int main()
{
clock_t starttime1,endtime1,starttime2,endtime2;
char P[100]={0},T[1000]={0};
cin>>P>>T;

cout<<"KMP算法： ";
starttime1=clock();
kmp(P,T);
endtime1=clock();
cout<<"匹配时间： "<<(double)(endtime1-
starttime1)/CLOCKS_PER_SEC<<"s"<<endl;
cout<<endl;
cout<<"BM算法： ";
starttime2=clock();
bm(P,T);
endtime2=clock();
cout<<"匹配时间： "<<(double)(endtime2-
starttime2)/CLOCKS_PER_SEC<<"s"<<endl;
cout<<endl;
return 0;
}
