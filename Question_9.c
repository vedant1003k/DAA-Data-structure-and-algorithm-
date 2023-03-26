/*3. . . Given an unsorted array of positive integers, design an algorithm and implement
it using a program to find whether there are any duplicate elements in the array or not.
(use sorting) (Time Complexity = O(n log n))*/

#include <stdio.h>
int part(int a[], int l, int h, int *s)
{
    int i = l - 1, j = l, pivot = a[h], temp;
    for (j = l; j <= h; j++)
    {
        if (j != h && a[j] == pivot)
        {
            (*s) = 1;
        }
        if (a[j] <= pivot)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    return i;
}
void quick(int a[], int l, int h, int *s)
{
    int j;
    if (l <= h)
    {
        j = part(a, l, h, s);
        quick(a, l, j - 1, s);
        quick(a, j + 1, h, s);
    }
}
int main()
{
    int n, t, i, a[15], s = 0, j;
    printf("enter number of test case ");
    scanf("%d", &t);
    for (j = 0; j < t; j++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        quick(a, 0, n - 1, &s);
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        if (s == 1)
            printf("\nYES\n");
        else
            printf("\nNO\n");

        s = 0;
    }
    return 0;
}