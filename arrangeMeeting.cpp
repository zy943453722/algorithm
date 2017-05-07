/*************************************************************************
	> File Name: order.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月15日 星期六 15时17分39秒
 ************************************************************************/
//会场安排问题
//待安排活动数：5
//start： 1 12 25 27 36
//end  ：23 28 35 80 50
#include<iostream>
#include<fstream>
using namespace std;
#define Max 100
typedef struct meeting
{
    int sta;//开始时间
    int end;//结束时间
    int num;//会场序号
}Meeting;
void Merge(Meeting a[],int ll,int c,int rr,int n)
{
    int i,j,k=0;
    Meeting *p;
    p = new Meeting[rr-ll+1]();
    i=ll;
    j=c+1;
    while(i<=c||j<=rr)
    {
        if(i <= c && j<= rr)
       {
          if(a[i].sta < a[j].sta)
           {
               p[k].end = a[i].end;
               p[k].sta = a[i].sta;
               k++;
               i++;
           }
          else  if(a[i].sta == a[j].sta)
           {
               if(a[i].end > a[j].end)
               {
                  p[k].end = a[j].end;
                  p[k].sta = a[j].sta;
                  k++;
                  j++;
               }
               else 
               {
                  p[k].end = a[i].end;
                  p[k].sta = a[i].sta;
                  k++;
                  i++;
               }
           }
          else
           {
               p[k].end = a[j].end;
               p[k].sta = a[j].sta;
               k++;
               j++;
           }
       }
       else if(i<=c&&j>rr)
        {
             p[k].end = a[i].end;
             p[k].sta = a[i].sta;
             k++;
             i++;
        }
        else
        {
             p[k].end = a[j].end;
             p[k].sta = a[j].sta;
             k++;
             j++;
        }
    }
   for(k=0,i=ll;i<=rr;k++,i++)
    {
       a[i].end = p[k].end;
       a[i].sta = p[k].sta;
    }
   delete []p;
}
void MergeSort(Meeting a[],int l,int r,int n)
{
    int c;
    if(l<r)
    {
     c=(l+r)/2;//i为中点标志,归左
     MergeSort(a,l,c,n);
     MergeSort(a,c+1,r,n);
     Merge(a,l,c,r,n);
    }
}
int arrangeMeeting(Meeting m[],int kk)
{
   int i,j;
   int used = 1;//初始化使用过的会场
   m[0].num = used;
   for(i = 1; i < kk; i++)//控制外层也就是后面的活动
    {
        for(j = 0; j < i; j++)//控制内层也就是前面的活动
        {
            if(m[j].num != 0 && m[j].end <= m[i].sta)
            {
                m[i].num = m[j].num;
                m[j].num = 0;//防止重复查看安排了的会场
                break;
            }
        }
        if(i == j)//当没有相容的活动
        {
            used++;
            m[i].num = used;
        }
    }
    return used;
}
int main()
{
    int k,i;
    int total = 0;
    Meeting mee[Max];
    ifstream in("text1.txt");
    if(in)
    {
      cout << "请输入待安排的活动数！"<<endl;
      in >> k;
      cout << k << endl;
      cout <<"请输入活动的起止时间！" <<endl;
      for(i = 0; i < k; i++)
      {
        in >> mee[i].sta >> mee[i].end;
        cout << mee[i].sta <<' ' << mee[i].end <<endl;
        mee[i].num = 0;
      }
     in.close();
    }
    MergeSort(mee,0,k-1,k);
    total = arrangeMeeting(mee,k);
    ofstream out("text.txt");
    if(out)
    {
        out << total;
        cout << "最少安排会场数为："<<endl;
        cout << total<<endl;
        out.close();
    }
    return 0;
}


