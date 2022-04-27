/*
12-2 实验10_6_动态分配内存_1

已知正整数n，你要利用malloc函数动态开辟一个长度为n的整型数组，然后读取n个整数存入该数组中。
再将这n个整数全部改为其相反数（例如10的相反数是－10，－10的相反数是10）的10倍，然后将其输出。
最后你要利用free函数将该动态数组所占用的空间释放。

输入格式:
为两行，第一行为一个正整数n，第二行为n个用空格分隔整数。测试用例保证所有整数可以用int存储，且为这n个整数申请内存不会超出内存限制。

输出格式:
输出只有一行，为用计算后的n个整数，这n个整数之间用一个空格分隔。

输入样例:
10
1 2 3 4 5 6 7 8 9 10
输出样例:
-10 -20 -30 -40 -50 -60 -70 -80 -90 -100
*/
#include <stdio.h>
#include <stdlib.h>

int *create(int);
void output(int *, int);

int main(void)
{
    int n,
        *array;
    scanf("%d", &n);

    array = create(n);

    output(array, n);

    free(array);
    return 0;
}

int *create(int n)
{
    int *a = NULL,
        i;
    a = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        *(a + i) *= -10;
    }

    return (int *) a;
}

void output(int *a, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        printf("%d ", *(a + i));
    printf("%d\n", *(a + i));
}