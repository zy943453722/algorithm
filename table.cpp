#include<iostream>
using namespace std;
#define N 100
int table[N][N] = {0};
void Print(int n)
{
   int i,j;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            cout<<table[i][j]<<' ';
        }
        cout<<endl;
    }
}
void Copy(int nn,int s_xx,int s_yy,int d_xx,int d_yy)
{
   int i,j;
   for(i = 0;i<nn;i++)
    {
        for(j = 0;j<nn;j++)
        {
           table[i+d_xx][j+d_yy] = table[i+s_xx][j+s_yy];
        }
    }
}
void Table(int nn, int s_xx,int s_yy)
{
   if(nn ==1)
     return;
   else
    {
        Table(nn/2,s_xx,s_yy);//排好左上角
        Table(nn/2,s_xx,s_yy+nn/2);//排好右上角
        Copy(nn/2,s_xx,s_yy,s_xx+nn/2,s_yy+nn/2);//将左上角复制到右下角
        Copy(nn/2,s_xx,s_yy+nn/2,s_xx+nn/2,s_yy);//将右上角复制到左下角
    }
}
int main()
{
   int n,i;
   int s_x = 0;
   int  s_y =0;
    cout<<"输入想要多少个运动员参加比赛！"<<endl;
   cin>>n;
   for(i = 0;i<n;i++)
    {
        table[0][i] = i+1;
    }
   Table(n,s_x,s_y);
   Print(n);
   return 0;
}
