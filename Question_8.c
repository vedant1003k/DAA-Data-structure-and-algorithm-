/*2. Given an unsorted array of integers, design an algorithm and implement a program
to sort this array using selection sort. Your program should also find number of
comparisons and number of swaps required.*/
#include <stdio.h>
int select(int a[], int n, int *s, int *c)
{
    int i, j, k, temp;
    for (i = 0; i < n; i++)
    {
        for (j = k = i; j < n; j++)
        {
            (*c)++;
            if (a[j] < a[k])
                k = j;
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
        (*s)++;
    }
}
int main()
{
    int n, t, i, a[15], s = 0, c = 0, j;
    printf("enter number of test case ");
    scanf("%d", &t);
    for (j = 0; j < t; j++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        select(a, n, &s, &c);
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n number of swaps are %d \n comparison %d \n", s, c);
        s = 0;
        c = 0;
    }
    return 0;
}