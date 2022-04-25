/*
13-5 实验10_9_指针数组进阶

已知正整数n，n的范围是1—100。你要从键盘读入n个字符串，每个字符串的长度不确定，但是n个字符串的总长度不超过100000。
你要利用字符指针数组将这n个字符串按照ASCII码顺序进行升序排序，然后再打印到屏幕上。
字符串中可能包含ASCII码中的任意字符，每个字符串以换行符结束输入。

要求：不允许定义如char str[100][100000];这样的二维数组，因为会极大的浪费内存空间。
你应定义char str[100000];这样的存储空间，将n个字符串连续的存储在一维字符空间内，
然后将这n个字符串的起始位置保存在字符指针数组中，再进行排序操作。

输入格式:
输入一个正整数n，代表待排序字符串的个数，n不超过100，然后是n个字符串，每个字符串的长度不确定，
但至少包含1个字符。n个字符串的总长度不会超过100000。

输出格式:
排序后的n个字符串，每个字符串占一行。

输入样例:
4
Where there is hope ,there is a way.
Welcome Beijing.
Nice idea.
Have fun.
输出样例:
Have fun.
Nice idea.
Welcome Beijing.
Where there is hope ,there is a way.
*/
#include <stdio.h>
#include <string.h>

void input(char *, char *[], int);
void sort(char *[], int);

int main(void)
{
    char str[100100],
        *a[100];
    int n,
        i;
    scanf("%d", &n);
    getchar();

    input(str, a, n);

    sort(a, n);

    for (i = 0; i < n; i++)
        puts(a[i]);

    return 0;
}

void input(char *str, char *a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        gets(str);
        a[i] = str;
        str += strlen(str) + 1;
    }
}

void sort(char *a[], int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}