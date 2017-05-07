/*************************************************************************
	> File Name: work.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月06日 星期四 14时50分22秒
 ************************************************************************/
//流水线作业调度问题：
//有1,2,3,4项任务，其中每项任务都需要雕刻和刷漆2个步骤。
//故：
//任务名：    1    2     3    4
//雕刻：      5    10    6    8（小时）
//刷漆：      7    3    12    5
#include<iostream>
using namespace std;
#include<string.h>
static int num[4] = {0};
typedef struct work
{
   int num;
   int job1;
   int job2;
}Work;
int time(Work aa[],Work bb[],int m,int n)
{
   int i,j,k;
    j = aa[0].job1;//加工第一个任务的雕刻不等待
    k = j + aa[0].job2;//加工第一个任务的刷漆也不等待
   for(i = 1; i < m;i++ )
    {
      j += aa[i].job1;
      if(k > j)
        k += aa[i].job2;//加工不需要等待
      else
        k = j + aa[i].job2;//加工需要等待
    }
    for(i = 0; i < n; i++)
    {
        j += bb[i].job1;
        if(k > j)
           k += bb[i].job2;
        else
          k = j + bb[i].job2;
    }
   return k;
}
void selectsort2(work bb[],int s,int m)
{
    int i,j,k;
    int tmp[20],temp[20];
    for(i = 0; i < m - 1; i++)
    {
         k = i;//k标记最大元素下标
         for(j = i + 1; j < m; j++)
            if(bb[j].job2 > bb[k].job2)
                 k = j;
         if(i!=k)
        {
             memcpy(tmp,&bb[i],sizeof(Work));
             memcpy(temp,&bb[k],sizeof(Work));
             memcpy(&bb[i],temp,sizeof(Work));
             memcpy(&bb[k],tmp,sizeof(Work));        
        }
    }  
    for(i = s,j = 0; i < s + m; i++,j++)
    {
        num[i] = bb[j].num;   
    }
}
void selectsort1(Work aa[],int n)
{
     int i,j,k;
     int tmp[20],temp[20];
     for(i = 0;i < n-1; i++)
    {
         k = i;//k标记最小元素下标
         for(j = i+1; j < n;j++)
             if(aa[j].job1 < aa[k].job1)
                 k = j;
          if(i!=k)
        {
             memcpy(tmp,&aa[i],sizeof(Work));
             memcpy(temp,&aa[k],sizeof(Work));
             memcpy(&aa[i],temp,sizeof(Work));
             memcpy(&aa[k],tmp,sizeof(Work));
        }
    }
   for(i = 0; i < n; i++ )
    {
        num[i] = aa[i].num;
    } 
}
int Flowshop(Work pro[])
{
  int i,t;
  int j = 0;
  int k = 0;
  Work a[4];//放工作1小的
  Work b[4];//放工作2小的
  for(i = 0; i < 4; i++)
    {
        if(pro[i].job1 < pro[i].job2)
        {  
          a[j].num = pro[i].num; 
          a[j].job1 = pro[i].job1;
          a[j].job2 = pro[i].job2;
         j++;
        }
        else
        {
          b[k].num = pro[i].num;
          b[k].job1 = pro[i].job1;
          b[k].job2 = pro[i].job2;
          k++;
        }
    }
   selectsort1(a,j);
   selectsort2(b,j,k);
   t = time(a,b,j,k);
   return t;
}
int main()
{
  Work product[4];
  int i,Time;
  cout<<"请输入每个产品各工序所需时间！"<<endl;
  for(i = 0; i < 4; i++)
    {
      product[i].num = i + 1;
      cin >> product[i].job1;
      cin >> product[i].job2;
    }
  Time = Flowshop(product);
  cout << "安排好的最优调度方案是："<<endl;
  for(i = 0; i < 4; i++)
    {
        cout << num[i]<<' ';
    }
    cout<<endl;
   cout<<"总调度时间为："<<endl;
   cout<<Time;
  return 0;
}

