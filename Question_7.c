/* 1. Given an unsorted array of integers, design an algorithm and a program to sort the
array using insertion sort. Your program should be able to find number of comparisons
and shifts ( shifts - total number of times the array elements are shifted from their
place) required for sorting the array.*/

#include <stdio.h>
void Insertion_Sort(int [],int,int *,int *);
void Disp(int [],int );
int main(void)
{
    int t,n,i,k,CP=0,SH=0;
    printf("Enter The Total Number of Test cases: ");
    scanf("%d",&t);
    while(t>0)
    {
        t--;
        printf("Enter The Size Array: ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter The Array: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        Insertion_Sort(arr,n,&CP,&SH);
        printf("Array After Sorting: ");
        Disp(arr,n);
        printf("Comparisons = %d \n",CP);
        printf("Shifts = %d \n",SH);
    }
    return 0;
}

void Insertion_Sort(int arr[],int n,int *CP,int *SH)
{
    int i, temp=0, j;
    for (i = 1; i < n; i++) 
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j]) 
        {
            (*CP)++;
            arr[j + 1] = arr[j];
            j = j - 1;
            (*SH)++;
        }
        arr[j + 1] = temp;
        (*SH)++;
    }
}

void Disp(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}