/*************************************************************************
	> File Name: subsetSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月30日 星期日 09时39分36秒
 ************************************************************************/
//子集和问题：用子集树，输入集合大小，输入目标值，输入集合中的元素
//输出哪几个元素能够获得最终解
//约束条件：当前选中集合元素 + 即将要选的元素 <= 目标值
#include<iostream>
#include<fstream>
using namespace std;
#define Max 100
class subset
{
    friend void subsetSum();
 private:
    int n;//集合内元素数目
    int sub[Max];//集合元素
    int x[Max];//当前解集合
    int bestx[Max];//最优解集合
    int sum;//当前解的值
    int count;//有无解的标志
    int c;//目标和
    void backTrack(int i);
};
void subset::backTrack(int i)
{
    int j = 0;
    if(i > n)//到达叶节点
    {
       if(sum == c && count == 0)
        {
           count++;
           for(j = 1; j <= n; j++)
            {
              bestx[j] = x[j]; 
            }
        }
        return;
    }
    else
    {
       if(sum + sub[i] <= c)//搜索左子树
        {
            x[i] = 1;
            sum += sub[i];
            backTrack(i+1);
            sum -= sub[i];
        }
        x[i] = 0;
        backTrack(i+1);
    }
}
void subsetSum()
{
   subset s;
    int i = 0;
    ifstream in("text1.txt");
    if(in)
    {
      cout << "请输入集合内元素数目和目标值：" << endl;
      in >> s.n >> s.c;
      cout << s.n <<' '<< s.c << endl;
      cout << "请输入元素" << endl;
      for(i = 1; i <= s.n; i++)
        {
            in >> s.sub[i];
            cout << s.sub[i] <<' ';
        }
        cout << endl;
    }
    in.close();
    for(i = 1; i <= s.n; i++)
    {
        s.x[i] = 0;
    }
  s.sum = 0;
  s.count = 0;
  s.backTrack(1);
    if(s.count == 1)
    {
     cout << "找到的子集为：" << endl;
     ofstream out("text2.txt");
     if(out)
     {
        for(i = 1; i <= s.n; i++)
        {
            cout << s.bestx[i] << ' ';
            if(s.bestx[i] == 1)
            {
                out << s.sub[i] << ' ';
            }
        }
     }
    out.close();
    }
    else
      cout << "NO Solution!"<<endl;
}
int main()
{
    subsetSum();
    return 0;
}
