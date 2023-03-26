
/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a 
given key element is present in the sorted array or not. For an array a[n], search at the indexes a[0], a[2], a[4],.....,a[2k] and
 so on. Once the interval (a[2k] < key < a[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element 
 key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):  */

#include <iostream>
#include <math.h>
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
        // Jump Search
        int jump = sqrt(n), start = 0, high = jump;
        for (int i = 0; i < n; i += jump)
        {
            count++;
            if (arr[i] == key)
            {
                flag = 1;
                break;
            }
            if (arr[i] < key)
            {
                start = i;
            }
            if (arr[i] > key)
            {
                break;
            }
        }
        for (int i = start; i < n; i++)
        {
            if (arr[i] == key)
                flag = 1;
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
