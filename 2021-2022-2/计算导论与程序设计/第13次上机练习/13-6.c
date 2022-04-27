/*
13-6 实验10_10_动态数组进阶

已知正整数n，n的范围不确定。从键盘读入n个字符串，每个字符串的长度小于1000，要保存到动态数组中。
为了能访问到所有的字符串，需要建立一个长度为n的动态指针数组，用于保存n个字符数组的内存地址。
在读入每个字符串时，用一个长度为1000的字符数组作为缓冲数组，将字符串读入并求出长度后，
再动态分配空间，将缓冲数组中的字符串复制到新分配的动态空间中，并将动态空间的首地址保存到指针数组中。
读完n个字符串后你要将这n个字符串按照ASCII码顺序升序排序，然后再打印到屏幕上。
字符串中可能包含大小写字母“A-Z”、“a—z”与空格字符。每个字符串以换行符结束输入。

输入格式:
输入一个正整数n，代表待排序字符串的个数。然后输入n个字符串，每个字符串至少包含一个字符，占一行。

输出格式:
排序后的n个字符串，每个字符串占一行。

输入样例:
10
Bb b
zzz zzz
aab bbccc
aaabbaaa
abb bbb
ccidfjD
Aidj idj
Ccidf jD
sidfjijE EE
kkkkkk
输出样例:
Aidj idj
Bb b
Ccidf jD
aaabbaaa
aab bbccc
abb bbb
ccidfjD
kkkkkk
sidfjijE EE
zzz zzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char **, char *, int);
void sort(char **, int);
void output(char **, int);

int main(void)
{
    int n;
    char ch[1000];
    char **p;
    scanf("%d", &n);
    getchar();

    p = (char **) malloc(sizeof(char *) * n);

    input(p, ch, n);
    sort(p, n);
    output(p, n);

    return 0;
}

void input(char **p, char *ch, int n)
{
    int m, i;
    for (i = 0; i < n; i++)
    {
        gets(ch);
        m = (int) strlen(ch) + 1;
        p[i] = (char *) malloc(sizeof(char) * m);
        strcpy(p[i], ch);
    }
}

void sort(char **p, int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(p[j], p[j + 1]) > 0)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
}

void output(char **p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        puts(*(p + i));
        free(*(p + i));
    }
    free(p);
}