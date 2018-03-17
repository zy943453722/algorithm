/*************************************************************************
	> File Name: Merge.c
	> Author: ZhangYue
	> Mail: zy943453722@gmail.com
	> Created Time: 2018年03月17日 星期六 11时22分03秒
 ************************************************************************/
/**
 * 归并排序：属于归并排序
 * 性能：空间复杂度:O(n) 时间复杂度:最好：O(nlogn) 平均：O(nlogn) 最坏：O(nlogn)
 * 稳定性：稳定
 * 思路：将一个数组递归的分成两半进行排序呢，最后将结果归并起来
 * 解答：1.取一个数组的中点，分成两部分递归分下去，
 *       2.直到分到不可再分之时，调用merge函数进行合并
 *       3.合并的过程需要一段辅助空间即当前分后的子数组的大小
 *       4.比较分成两个数组的首元素，小的放进辅助数组中，依次形成有序，若
 *         某个数组放完了直接把另一个全部复制进去
 *       5.最后将辅助空间中的元素复制回原数组
 */ 
#include<stdio.h>
#include<stdlib.h>
#include "sort.h"
void Merge(Sqlist *l,Sqlist *temp,int lo,int mid,int hi)
{
    if(l->list[mid] <= l->list[mid+1])
       return;//因为本身两边有序，若左边最大的比右边最小的都小，那么说明整个数组是有效的
    int i = lo;
    int j = mid + 1;
    int k = 0;
    while(i <= mid || j <= hi)
    {
        if(i <= mid && j <= hi)
        {
            if(l->list[i] < l->list[j])
            {
                temp->list[k++] = l->list[i++];
            }
            else
            {
                temp->list[k++] = l->list[j++];
            }
        }
        else if(i <= mid)//后面的数组扫描完了，直接把前面的数组放回去
        {
            temp->list[k++] = l->list[i++];
        }
        else
            temp->list[k++] = l->list[j++];
    }
    for(k = 0,i = lo; i <= hi; i++,k++)
    {
        l->list[i] = temp->list[k];
    }
}
void MergeSort(Sqlist *l, Sqlist *temp, int lo, int hi)
{
    if(lo >= hi)
      return;
    int mid = (lo + hi) / 2;
    MergeSort(l,temp,lo,mid);//先分治再合
    MergeSort(l,temp,mid+1,hi);
    Merge(l,temp,lo,mid,hi);
}
void Prepare(Sqlist *l)//用于生成一个辅助数组
{
    Sqlist *temp = (Sqlist*)malloc(sizeof(Sqlist));
    MergeSort(l,temp,0,l->length - 1);
    free(temp);
    temp = null;
}
