/*************************************************************************
	> File Name: hanoi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 18时59分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
int count = 0;
void move(int n ,char x ,char y)
{  
        cout<<"移动盘子"<<n<<"从"<<x<<"到"<<y<<endl;
        count++;
}
void hanoi(int nn,char a,char b,char c)
{
    int i;
    if(nn==1)
     {
         move(1,a,b);
         move(2,a,c);
         move(1,b,c);
     }
     else{
         hanoi(nn-1,a,b,c);
         move(2*(nn-1)+1,a,b);
         hanoi(nn-1,c,a,b);
         move(2*nn,a,c);
         hanoi(nn-1,b,c,a);
         move(2*(nn-1)+1,b,c);
         hanoi(nn-1,a,b,c);
         }
}
int main()
{
    int n,num;
    char a = 'A';
    char b = 'B';
    char c = 'c';
    cout<<"请输入想要输入的盘子个数(偶数)："<<endl;   
    cin >> n ;
    if(n%2!=0||n==0)
     cout<<"输入错误，请重输！";
    num = n/2;
    hanoi(num,a,b,c);
    cout<<"移动的次数是："<<count<<endl;
    return 0;
}
