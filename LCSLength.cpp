/*************************************************************************
	> File Name: LCSLength.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月12日 星期三 21时10分34秒
 ************************************************************************/
//最长公共子序列
//6 7
//x:acbecb
//y:abecdbb
//5
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
void LCSLength(char xx[],char yy[],int mm,int nn)
{
   int i,j;
   for(i = 0; i <= mm; i++)
     c[i][0] = 0;
   for(i = 0; i <= nn; i++)
     c[0][i] = 0;
   for(i = 1; i <= mm; i++)
    {
        for(j = 1; j <= nn; j++)
        {
            if(xx[i-1] == yy[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;//记录下变化的地方，好回溯找最长子序是什么
            }
            else if(c[i][j-1] > c[i-1][j])
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 2;//取左方时用2表示
            }
            else
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 3;//取上方时用3表示
            }
        }
    }
}    
int main()
{
    int m,n,i,j;
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
    LCSLength(x,y,m,n);
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout << endl;
    }
    cout << "最长公共子序列是："<<endl;
    Found(x,m,n);
    cout<<endl;
   for(i = 1; i <= m; i++)
    {
         for(j = 1; j <= n; j++)
        {
             cout<<b[i][j]<<' ';
        }
         cout << endl;
    }
    cout << "长度为："<< endl;
    cout << c[m][n] <<endl;
    return 0;
}
