/*************************************************************************
	> File Name: LCSLenth2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月13日 星期四 23时00分31秒
 ************************************************************************/
//递归版本实现最长子序的查找
#include<iostream>
using namespace std;
#define Max 100
static int c[Max][Max] = {{-1}};
static int b[Max][Max] = {{-1}};
void Found(char xx[],int i,int j)//从表的最后一个元素开始寻找1的元素，进而找最长子序
{
   if(i == 0 || j == 0)
    return;
   if(b[i][j] == 1)
    {
        Found(xx,i-1,j-1);
        cout << xx[i-1];
    }
    else if(b[i][j] == 2)
    {
        Found(xx,i,j-1);
    }
    else
    {
       Found(xx,i-1,j);
    }
}
int LCSLen(char xx[],char yy[],int i,int j)
{
    int tmp;
    if(c[i][j] > 0)
      return c[i][j];
    if(i == 0 ||j == 0)
    {
        return 0;
    }
    else
    {
        if(xx[i-1] == yy[j-1])
        {
            c[i][j] = LCSLen(xx,yy,i-1,j-1) + 1;
            b[i][j] = 1;
        }
        else if(LCSLen(xx,yy,i,j-1) > LCSLen(xx,yy,i-1,j))
        {
            c[i][j] = LCSLen(xx,yy,i,j-1);
            b[i][j] = 2;//取左方
        }
        else
        {
            c[i][j] = LCSLen(xx,yy,i-1,j);
            b[i][j] = 3;
        }
    }
    return c[i][j];
}
int LCSLength(char xx[],char yy[],int mm,int nn)
{
    int i,j;
    for(i = 0; i <= mm; i++)
    {
        for(j = 0; j <= nn; j++)
        {
            c[i][j] = 0;
        }
    }
    return LCSLen(xx,yy,mm,nn);
}
int main()
{
    int m,n,i,j;
    int total;
    char x[Max],y[Max];
    cout << "请输入X的和y的序列长度："<< endl;
    cin>>m>>n;
    cout << "请输入x序列和y序列："<<endl;
    for(i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    for(i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    total = LCSLength(x,y,m,n);
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "最长子序列长度为：" << total;
    cout << "最长公共子序列是："<<endl;
    Found(x,m,n);
    return 0;
}
