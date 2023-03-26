/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x, int *count)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            (*count)++;
            int i = mid - 1;
            while (i >= l && arr[i] == x)
            {
                (*count)++;
                i--;
            }
            i = mid + 1;
            while (i <= r && arr[i] == x)
            {
                (*count)++;
                i++;
            }
            return mid;
        }
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, count);

        return binarySearch(arr, mid + 1, r, x, count);
    }

    return -1;
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    while (test_case--)
    {
        int n, key;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &key);
        int count = 0;
        int result = binarySearch(arr, 0, n - 1, key, &count);
        if (result == -1)
        {
            printf("Key not present\n");
        }
        else
        {
            printf("key present  - %d\n", count);
        }
    }
    return 0;
}
