/*************************************************************************
	> File Name: car.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月10日 星期一 16时59分20秒
 ************************************************************************/
//汽车加油问题
//输入加满油后可行驶公里数和加油站数，且输入每个加油站之间的距离
//ex：7 7
//         1 2 3 4  5  1  6  6
//目的地：0 1 3 6 10 15 16 22 28终点（上下对应）
#include<iostream>
#include<fstream>
using namespace std;
#define Max 100
static int num = 0;
void Car(int aa[],int nn,int kk)
{
   int i,s;
    for(i = 0; i <= kk; i++)
    {
        if(aa[i] > nn)
        {
            cout << "走不到终点" << endl;
            return;
        }
    }
    for(i = 0,s = 0; i <= kk; i++)
    {
        s += aa[i];
        if(s > nn)
        {
            num++;
            s = aa[i];
        }
    }
}
int main()
{
    int i,n,k;
    int a[Max] = {0};
    ifstream in("text1.txt");
    if(in)
    {
      cout << "请输入一次加满油后行驶距离和加油站数：" <<endl;
      in >> n >> k;
      cout << n <<' ' << k << endl;
      cout << "请输入相邻2个加油站之间的距离：" <<endl;
      for(i = 0; i < k + 1; i++)
      {
         in >> a[i];
         cout << a[i] << ' ';
      }
     cout <<endl;
     in.close();
    }
    Car(a,n,k);
    ofstream out("text.txt");
     if(out)
     {
        out << num;
        out.close();
     }
      cout << "加油次数最少为："<< num << endl;
      return 0;
}

