#include <iostream>

using namespace std;
#include<stdlib.h>
#include <time.h>
void Merge(int a[],int ll,int c,int rr)
{
    int i,j,k=0;
    int *p;
    p=new int[rr-ll+1]();
    //int p[9]={0};
    i=ll;
    j=c+1;
    while(i<=c||j<=rr)
    {
        if(i <= c && j<= rr)
       {
          if( a[i] < a[j] )
            p[k++] = a[i++];
          else
            p[k++] = a[j++];
       }
       else if(i<=c&&j>rr)
           p[k++] = a[i++];
        else
          p[k++] = a[j++];

    }
   for(k=0,i=ll;i<=rr;k++,i++)
    {
       a[i]=p[k];
    }
    delete []p;
}
void MergeSort(int a[],int l,int r)
{
    int c;
    if(l<r)
    {
     c=(l+r)/2;//i为中点标志,归左
     MergeSort(a,l,c);
    MergeSort(a,c+1,r);
     Merge(a,l,c,r);
    }
}
int main()
{
       int i,r=7,l=0;
       //srand(time(NULL));
       int a[8]={8,5,7,0,5,1,2,14};
       MergeSort(a,l,r);
       for(i=0;i<=7;i++)
       {
        cout<<a[i]<<endl;
       }
    return 0;
}
