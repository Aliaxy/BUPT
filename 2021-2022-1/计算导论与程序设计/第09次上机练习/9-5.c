/*
9-5 实验7_7_连续子序列

已知两个由正整数组成的无序序列A、B，每个序列的元素个数未知，但至少有一个元素。
你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，B是A的连续子序列；
假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。

输入格式:
依次输入两个乱序的正整数序列A、B，序列中元素个数未知，但每个序列至少有一个元素，并以输入“-1”结束（-1不算序列中元素），
每个序列占一行。两个数列的长度均不超过1000。

输入保证合法，且所有整数均可用int存储。

输出格式:
如果序列B是序列A的连续子序列，则输出“ListB is the sub sequence of ListA.”，否则输出“ListB is not the sub sequence of ListA.”。

输入样例:
5 4 3 2 1 -1
3 2 1 -1
输出样例:
ListB is the sub sequence of ListA.
*/
#include <stdio.h>

int read(int[]);
int operate(int[], int[], int, int);
void print(int);

int main(void)
{
    int arrA[1000],
        arrB[1000],
        na = read(arrA),
        nb = read(arrB);

    print(operate(arrA, arrB, na, nb));

    return 0;
}

int read(int a[])
{
    int i = 0;
    scanf("%d", &a[i]);
    while (a[i] != -1)
    {
        i++;
        scanf("%d", &a[i]);
    }
    return i;
}

int operate(int a[], int b[], int na, int nb)
{
    int i, j, flag = 1;
    for (i = 0; i < na - nb + 1 && flag; i++)
    {
        if (a[i] == b[0])
        {
            for (j = 1; j < nb && flag; j++)
                if (a[i + j] != b[j])
                    flag = 0;
            flag = !flag;
        }
    }

    return flag;
}

void print(int flag)
{
    if (flag)
        printf("ListB is not the sub sequence of ListA.");
    else
        printf("ListB is the sub sequence of ListA.");
}