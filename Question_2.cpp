/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of
 comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input). */

#include <iostream>
using namespace std;
int main()
{
    int test_case;
    cin >> test_case;
    while (test_case)
    {
        int flag = 0;
        int count = 0;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        int low = 0, high = n - 1, mid;
        do
        {
            count++;
            mid = (low + high) / 2;
            if (key == arr[mid])
            {
                flag = 1;
                break;
            }
            (key > arr[mid]) ? (low = mid + 1) : (high = mid - 1);

        } while (low <= high);

        if (flag == 1)
        {
            printf("Present %d\n", count);
        }
        else
        {
            printf("Not present %d\n", count);
        }
        test_case--;
    }
}