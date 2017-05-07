/*************************************************************************
	> File Name: minwiMachine.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月01日 星期一 21时57分55秒
 ************************************************************************/
//最小重量机器设计问题：n个部件，m个供货商，w(i,j)☞i部件在j供货商处的重量，c（i，j）即价格
//求在总价格不超过一个范围条件下，最小w的安排方法
//这是一个排列树
//上界函数c[i][j] + nc <= cc
//约束条件：nw < bestw
#include<iostream>
#include<fstream>
using namespace std;
#define Max 100
class machine
{
    friend void Arrange();
    private:
      int n;//部件数
      int cc;//价格上限
      int m;//供应商数
      int nw;//当前部件总质量
      int nc;//当前价格总量
      int w[Max][Max];//某供应商的某部件重量
      int c[Max][Max];//某供应商的某部件价格
      int bestw;//最优质量
      int bestx[Max];//最优供货商数组
      int x[Max];//当前供货商组
      void backTrack(int i);
};
void machine::backTrack(int i)
{
    int k = 0;
    int j = 0;
    if(i > n)
    {
        if(nw < bestw)
        {
          for(k = 1; k <= n; k++)
          {
            bestx[k] = x[k];
          }
          bestw = nw;
        }
    }
    for(j = 1; j <= n; j++)
    {
      if(c[i][j] + nc <= cc && nw < bestw)
      {
        x[i] = j;
        nc += c[i][j];
        nw += w[i][j];
        backTrack(i+1);
        nc -= c[i][j];
        nw -= w[i][j];
      }
    }
}
void Arrange()
{
    machine mac;
    int i = 0;
    int j = 0;
    mac.nw = 0;
    mac.nc = 0;
    mac.bestw = Max;
    ifstream in("text1.txt");
    if(in)
    {
        cout << "请输入部件数和供应商数及总价格上限！" << endl;
        in >> mac.n >> mac.m >> mac.cc;
        cout << mac.n << ' '<< mac.m << ' ' << mac.cc << endl;
        cout << "请输入各部件在不同供应商的价格和重量" << endl;
        for(i = 1; i <= mac.n; i++)
        {
            for(j = 1; j <= mac.m; j++)
            {
                in >> mac.c[i][j];
                cout << mac.c[i][j];
            }
            cout << endl;
        }
        for(i = 1; i <= mac.n; i++)
        {
            for(j = 1; j <= mac.m; j++)
            {
                in >> mac.w[i][j];
                cout << mac.w[i][j];
            }
            cout << endl;
        }
    }
    in.close();
    for(i = 1; i <= mac.n; i++)
    {
        mac.x[i] = i;
    }
    mac.backTrack(1);
    ofstream out("text2.txt");
    if(out)
    {
        out << mac.bestw << endl;
        cout << mac.bestw << endl;
        for(i = 1; i <= mac.n; i++)
        {
           out << mac.bestx[i] << ' ';
            cout << mac.bestx[i] << ' ';
        }
    }
    out.close();
}
int main()
{
    Arrange();
    return 0;
}
