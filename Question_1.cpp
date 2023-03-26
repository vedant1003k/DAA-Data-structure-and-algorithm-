/* Given an array of nonnegative integers, design a linear algorithm and implement it using a program to
 find whether given key element is present in the array or not. Also, find total number of comparisons for
  each input case. (Time Complexity = O(n), where n is the size of input)
 */

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
        for (int i = 0; i < n; i++)
        {
            count++;
            if (arr[i] == key)
            {
                flag = 1;
                break;
            }
        }

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