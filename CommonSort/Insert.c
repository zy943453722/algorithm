/*************************************************************************
	> File Name: Insert.c
	> Author: ZhangYue
	> Mail: zy943453722@gmail.com
	> Created Time: 2018年03月17日 星期六 09时34分47秒
 ************************************************************************/
/**
 * 直接插入排序:属于插入排序的一种，另外一种是shell(希尔)排序  
 * 性能: 空间复杂度:O(1) 时间复杂度: 最好:O(n) 平均:O(n^2) 最坏：O(n^2)
 * 稳定性: 稳定
 * 思路:设置一个哨兵值，用于存放当前i位置的元素，之后依次比较前面的元素和哨兵位置的大小，
 *      若比他大则依次后移，比他小不动。最后将哨兵插入空出来的位置
 *      **实际假定哨兵指前面是有序数组，拿到的哨兵值只是为了插入其中，仍然使其有序
 */ 

#include<stdio.h>
#include<stdlib.h>
#include "sort.h"
void InsertSort(Sqlist *l)
{
    int flag = 0;//设置哨兵值
    for(int i = 1; i <= l->length-1; i++)//因为假定前面数组有序，因此从1开始遍历
    {
        flag = l->list[i];//当前值设为哨兵
        int j = i - 1;//与前面的有序数组作比较
        while(j >= 0 && l->list[j] > flag)
        {
            l->list[j+1] = l->list[j];
            j--;
        }
        l->list[j] = flag;//插入哨兵值
    }
}

