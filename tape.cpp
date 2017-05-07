/*************************************************************************
	> File Name: tape.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月25日 星期二 20时36分56秒
 ************************************************************************/
//磁带最优存储问题
//对于给定的n个文件，每个文件中有b个程序，他们长度分别是a，读取某个程序的时间为t =（1+2+....+n） a*b
//平均时间为总时间/程序总数目
#include<iostream>
#include<fstream>
using namespace std;
#define Max 100
static int b[Max] = {0};
typedef struct tape
{
    int a;
    int b;
}Tape;
void Sort(int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = 0;
    for(i = 0; i < n-1; i++)
    {
        k = i;//k标记最大元素下标
        for(j = i + 1; j < n;j++)
        {
           if(b[j] > b[k])
            {
              k = j;
            }
        }
        if(i != k)
        {
            tmp = b[k];
            b[k] = b[i];
            b[i] = tmp;
        }
    }     
}
double Cal(Tape t[],int nn)
{
    int i = 0;
    double sum = 0.0;
    double time = 0.0;
    for(i = 0; i < nn; i++)
    { 
        b[i] = t[i].a * t[i].b;
        sum += t[i].b;
    }
    Sort(nn);
    for(i = nn - 1; i >= 0; i--)
    {
        time += (i+1) * b[i];
    }
    return time / sum;
}
int main()
{
    int i = 0;
    int n = 0;
    double avg = 0.0;
    Tape tap[Max] = {0};
    ifstream in("text1.txt");
    if(in)
    {
      cout << "请输入有几个文件！" << endl;
      in >> n;
      cout << n << endl;
      cout << "请输入程序长度和读取频数！" << endl; 
      for(i = 0; i < n; i++)
      {
        in >> tap[i].a >> tap[i].b;
        cout << tap[i].a <<' '<< tap[i].b << endl;
      }
      in.close();
    }
    avg = Cal(tap,n);
    ofstream out("text2.txt");
    if(out)
    {
        out << avg;
        out.close();
    }
    cout << "最优平均时间为：" << avg <<endl;
    return 0;
}
