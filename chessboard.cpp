/*************************************************************************
> File Name: Chessboard.cpp
> Author:
> Mail:
> Created Time: 2017年03月24日 星期五 19时43分36秒
************************************************************************/

#include<iostream>
#define N 100
using namespace std;
#include<math.h>
int Count = 0;
int board[N][N] = {0};
void ChessBoard(int s_xx,int s_yy,int d_xx,int d_yy,int n)
{
     int s,t;
     if(n==1)
     return;
     else
     {
        t = ++Count;
        s = n/2;//分割棋盘
        if(d_xx<s_xx+s&&d_yy<s_yy+s)//dirty块在其中
        ChessBoard(s_xx,s_yy,d_xx,d_yy,s);
         else
         {
             board[s_xx+s-1][s_yy+s-1] = t;//之后把他当成dirty块
             ChessBoard(s_xx,s_yy,s_xx+s-1,s_yy+s-1,s);//覆盖剩余棋盘
         }//走完else会接着往下走判断下面的if-else
         if(d_xx>=s_xx+s&&d_yy<s_yy+s)
         ChessBoard(s_xx+s,s_yy,d_xx,d_yy,s);
         else
         {
             board[s_xx+s][s_yy+s-1] = t;//之后把他当成dirty块
             ChessBoard(s_xx+s,s_yy,s_xx+s,s_yy+s-1,s);
         }
         if(d_xx<s_xx+s&&d_yy>=s_yy+s)
         ChessBoard(s_xx,s_yy+s,d_xx,d_yy,s);
         else
         {
                board[s_xx+s-1][s_yy+s] = t;
                ChessBoard(s_xx,s_yy+s,s_xx+s-1,s_yy+s,s);
         }
         if(d_xx>=s_xx+s&&d_yy>=s_yy+s)
           ChessBoard(s_xx+s,s_yy+s,d_xx,d_yy,s);
         else
         {
                board[s_xx+s][s_yy+s] = t;
                ChessBoard(s_xx+s,s_yy+s,s_xx+s,s_yy+s,s);
         }
    }
 }
        void Print(int b[][N],int s)
        {
            int i,j;
            for(i = 0;i<s;i++)
            {
                for(j = 0;j<s;j++)
                {
                    cout<<b[i][j]<<' ';
                }
                cout<<endl;
            }
        }
        int main()
        {
            int k,d_x,d_y,size;
            cout<<"请输入想要覆盖多大的棋盘："<<endl;
            cin>>k;
            int s_x = 0;
            int s_y = 0;
            cout<<"请输入特殊方格的位置坐标："<<endl;
            cin>>d_x;
            cin>>d_y;
            size = pow(2,k);
            ChessBoard(s_x,s_y,d_x,d_y,size);
            Print(board,size);
            return 0;
        }
