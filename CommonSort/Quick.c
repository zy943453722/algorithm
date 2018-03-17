/*************************************************************************
	> File Name: Quick.c
	> Author: ZhangYue
	> Mail: zy943453722@gmail.com
	> Created Time: 2018年03月17日 星期六 10时14分28秒
 ************************************************************************/
/**这里的空间占用主要是递归占用栈空间导致的
 * 快速排序:属于交换排序的一种,另一种是冒泡排序
 * 性能: 空间复杂度:O(logn)-O(n) 时间复杂度:最好：O(nlogn) 平均：O(nlogn) 最坏:O(n^2)
 * 稳定性：不稳定
 * 思路：利用随机选出的元素，依次与其比较，小的放左边，大的放右边，则分隔成了两部分解决
 *       1.先对输入的数据进行洗牌
 *       2.以数据a[j]为中心进行分区，使得a[j]左侧的数据都小于等于a[j]，a[j]右侧的数据都大于等于a[j]
 *       3.分区完后递归排序
 * 解答：设置两个指针，分别指向low-1和low，即头和头后的一个
 *       1.将选出的元素交换到尾部
 *       2.从low依次遍历数组，同时与选出的元素比较，小的话low-1指针后移表示左边空间扩大，同时交换low-1指针和low指针的值
 *          (因为当前low-1指针还没指向小元素，只是指向新的空间)
 *       3.大的话不动
 *       4.直到遍历完成，交换low下标和选出的元素
 *
 */ 
#include<stdio.h>
#include<stdlib.h>
#include "sort.h"

int Random(int high,int low)//设置随机，打乱快排序列，使快排更有效
{
    int i = rand() % (high-low+1) + low;//设置随机值,%10余0-9即除以元素个数+头元素下标
    return i;
}
int Partition(Sqlist *l, int h,int l)//返回随机选取的元素最终的位置
{
    if(l == NULL || h <= 0 || l <= 0)
        return -1;
    int flag = Random();
    Swap(l->list[flag],l->list[h]);//将选取的元素交换到尾部
    int i = l - 1;//控制小于标志元素的空间作用
    for(int j = l; j < h; j++)
    {
        if(l->list[j] < l->list[h])
        {
            i++;
            if(i != j)//之间有掺杂大于标志元素的元素
            {
               Swap(l->list[j],l->list[i]);
            }
        }
    }
    i++;//指向大于标志元素的第一位
    Swap(l->list[h],l->list[i]);//使标志元素顺利进入小于元素的末尾
    return i;
}
void QuickSort(Sqlist *l)
{
    int low = 0;
    int high = l->length - 1;
    if(low >= high)
       return;
    int index = Partition(l,high,low);
    QuickSort(l,index-1,low);//不包含标志元素
    QuickSort(l,high,index+1);
}
