/*************************************************************************
	> File Name: Matrixchain.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月12日 星期三 18时20分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define Max 100
static int m[Max][Max] = {{-1}};
static int s[Max][Max] = {{-1}};
void Traceback(int x,int y)
{
   if(x == y)
    {
     cout << "A" << x;
    }
    else
    {
      cout << "(";
   Traceback(x,s[x][y]);
   Traceback(s[x][y] + 1,y);
    cout <<")";
    }
}
void Matrixchain(int pp[],int nn)
{
  int i,j,k,a;//a控制列的循环
  int temp = 0;
  for(i = 0; i < nn; i++)
     m[i][i] = 0;
  for(a = 1; a < nn; a++)//这个二维表必须按主对角线方向斜着填
  {
      for(i = 0; i <= nn - a -1; i++)//nn-a-1指斜着填时i最大到的位置
      {
          j = a + i;//j的位置
          m[i][j] = m[i][i] + m[i+1][j] + pp[i]*pp[i+1]*pp[j+1];
          s[i][j] = i;//以第i+1个式子为分点
          //比较分点不同带来的同一位置不同大小
          for(k = i + 1; k <= j; k++)
          {
              temp = m[i][k] + m[k+1][j] + pp[i]*pp[k+1]*pp[j+1];
              if(temp < m[i][j])
              {
                m[i][j] = temp;
                s[i][j] = k;
              }         
          }
      }
  }
}
int main()
{
    int p[Max];//存放矩阵的行和列
    int n,i,j;
    cout << "请输入有多少个矩阵连乘:" << endl;
    cin >> n;
    cout << "请输入矩阵的行列：" << endl;
    for(i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    Matrixchain(p,n);
    cout << "最小连乘次数为：" << endl;
    cout << m[0][5] <<endl;
   /* for(i = 0; i < n; i++)
    {
        for(j = i; j < n;j++)
        {
          cout << m[i][j]<<' ';
        }
        cout << endl;
    }*/
   /* for(i = 0;i < n ;i++)
    {
        for(j = i; j < n; j++)
            cout << s[i][j]<<' ';
        cout<<endl;
    }*/
    cout << "最优次序为："<<endl;
    Traceback(0,n-1);
    return 0;
}
