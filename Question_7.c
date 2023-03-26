/* 1. Given an unsorted array of integers, design an algorithm and a program to sort the
array using insertion sort. Your program should be able to find number of comparisons
and shifts ( shifts - total number of times the array elements are shifted from their
place) required for sorting the array.*/

#include <stdio.h>
#define n 8
int main()
{
    int a[n], comparisons = 0, shifts = 0;
    printf("enter the array elements");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        //printf("hello");-23 65 -31 76 46 89 45 32
        int temp = a[i];
        int j = i - 1;
        shifts++;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
            shifts++;
            comparisons++;
        }
        a[j + 1] = temp;
    }
    printf("sorted array is:- ");
    for (int k = 0; k < n; k++)
        printf("%d  ", a[k]);
    printf("\nTotal no of comparisons are:- %d\nTotal no. of shifts are:- %d", comparisons, shifts);
}