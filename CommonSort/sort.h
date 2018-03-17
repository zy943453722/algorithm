/*************************************************************************
	> File Name: sort.h
	> Author: ZhangYue
	> Mail: zy943453722@gmail.com
	> Created Time: 2018年03月16日 星期五 16时21分15秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
#define MAX 10
typedef struct sqlist{
    int list[MAX];
    int length;
}Sqlist;
void Swap(Sqlist *l, int i, int j)
{
    int temp = l->list[i];
    l->list[i] = l->list[j];
    l->list[j] = temp;
}
#endif

