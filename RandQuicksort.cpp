/*************************************************************************
	> File Name: RandQuicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月22日 星期一 17时29分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 10

int RandParTation(int a[], int lo, int hi);
int ParTation(int a[], int lo, int hi);

int RandParTation(int a[], int lo, int hi)
{
	int x = rand() % (hi - lo + 1) + lo;
	int q = 0;
	swap(a[x], a[hi]);
	q = ParTation(a, lo, hi);
	return q;
}

void QuickSort(int a[], int lo, int hi)
{
	int p = 0;
	if(lo <= hi)
	{
		p = RandParTation(a, lo, hi);
		QuickSort(a, lo, p - 1);
		QuickSort(a, p + 1, hi);
	}
}

int ParTation(int a[], int lo, int hi)
{
	int tmp = a[hi];
	int i = lo - 1;
	int j = lo;
	for(j = lo; j <= hi - 1; ++j)
		if(a[j] < tmp)
		{
			swap(a[i + 1], a[j]);
			i++;
		}
	swap(a[hi], a[i + 1]);
	return i+1;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int i = 0;
	int a[MAX] = {2, 3, 53, 564, 23, 43, 4, 32, 34, 8};
	QuickSort(a, 0, MAX-1);
	for(i = 0; i < MAX; ++i)
		cout<<a[i]<<endl;
	return 0;
}
