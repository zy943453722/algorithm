#include<iostream>
using namespace std;
#include<stdlib.h>
int Partation(int aa[],int ll,int hh)
{
    int tmp,temp;
    tmp = aa[hh];
    int i = ll - 1;
    for(int j = ll ; j <= hh-1 ; j++)
    {
        if(aa[j] < tmp)
        {
           temp = aa[i+1];
           aa[i+1] = aa[j];
           aa[j] = temp;
           i++;
        }
    }
    temp = aa[i+1];
    aa[i+1] = aa[hh];
    aa[hh] = temp;
    return i+1;
}
int RanPartation(int aa[],int ll,int hh)
{
    int i,temp,j;
    i = rand()%(hh-ll+1)+ll;
    temp = aa[i];
    aa[i] = aa[hh];
    aa[hh] = temp;
    j = Partation(aa,ll,hh);
    return j;
}
int RandomSelect(int aa[],int l,int h,int kk)
{
     int  p;
     if(l == h)
         return aa[l];
     else
    {
        p = RanPartation(aa,l,h);//随机划分的位置
        if(kk == p)
        {
            return aa[p];
        }
         else if(kk<p)
        {
            return RandomSelect(aa,l,p-1,kk);
        }
        else
            return RandomSelect(aa,p+1,h,kk);
    }
}
int main()
{
        int a[6] = {5,3,7,9,11,64};
        int lo = 0;
        int hi = 5;
        int k , result;
        cout<<"请输入想要查找第几位小元素："<<endl;
        cin>>k;
        result =  RandomSelect(a,lo,hi,k-1);
        cout<<result;
        return 0;
}
