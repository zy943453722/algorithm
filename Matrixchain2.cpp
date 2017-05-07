/*************************************************************************
	> File Name: Matrixchain2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月12日 星期三 19时35分59秒
 ************************************************************************/
//备忘录方法，相当于求出一个最优的子问题就返回输出，直到求到最终的答案
#include<iostream>
using namespace std;
#define Max 100
int m[Max][Max] = {{-1}};
int s[Max][Max] = {{-1}};
void print(int x,int y)
{
    if(x == y)
    {
     cout << "A" << x;
    }
    else
    {
      cout << "(";
      print(x,s[x][y]);
      print(s[x][y] + 1,y);
      cout <<")";
    }
}
int LookupChain(int i,int j,int p[])
{
    int u,t,k;
    if(m[i][j] > 0)
      return m[i][j];
    if(i == j)
      return 0;
    u = LookupChain(i,i,p) + LookupChain(i+1,j,p) + p[i] * p[i+1] * p[j+1];
    s[i][j] = i;
    for(k = i + 1; k < j;k++)
    {
        t = LookupChain(i,k,p) + LookupChain(k+1,j,p) + p[i] * p[k+1] * p[j+1];
        if(t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}
int MemoizedMatrixChain(int nn,int pp[])
{
    for(int i = 0; i < nn; i++)
    {
        for(int j = i; j < nn; j++)
        {
            m[i][j] = 0;
        }
    }
    return LookupChain(0,nn,pp);
}
int main()
{
    
    int p[Max];//存放矩阵的行和列
    int n,i,j,total;
    cout << "请输入有多少个矩阵连乘:" << endl;
    cin >> n;
    cout << "请输入矩阵的行列：" << endl;
    for(i = 0; i <= n; i++)
    {
                cin >> p[i];        
    }
    total = MemoizedMatrixChain(n-1,p);
    cout << "最小连乘次数为：" << total;
    cout <<"最优次序为：" << endl;
    print(0,n-1);
    return 0;
}
