/*************************************************************************
	> File Name: binarySearch.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月21日 星期日 21时04分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
int binarySearch(int a[],int k , int n)
{
    int l = 0;
    int r = n - 1;
   while(l <= r)
    {
        int m = (l + r) / 2;
        if(k == a[m])
        {
           return m;
        }
        else if(k > a[m])
           l = m + 1;
        else
           r = m - 1;
    }
    return -1;
}
int main()
{
    int k = 0;
    int result = 0;
    int a[10] = {2,3,4,5,6,7,8,9,10,11};
    cout << "请输入想要查找的数字!" << endl;
    cin >> k;
    result = binarySearch(a,k,10);
    cout <<result;
    return 0;
}
