// Given an unsorted array of integers, design an algorithm and implement it using a program  to sort 
// an array of elements by  partitioning the array into two subarrays based on a pivot element such 
// that  one  of  the  sub  array  holds  values  smaller  than  the  pivot  element  while  another  sub array 
// holds values greater than the pivot element. Pivot element should be selected randomly from the 
// array. Your program should also find number of comparisons and swaps required for sorting the 
// array.

#include <stdio.h>
int Div(int [],int,int,int*,int*);
void Qsort(int [],int,int,int*,int*);
void Disp(int [],int);
int main()
{
    int t,n,i;
    printf("Enter The Total Number of Test cases: ");
    scanf("%d",&t);
    while(t>0)
    {
        t--;
        printf("Enter The Size Array: ");
        scanf("%d",&n);
        int arr[n],SW=0,CMP=0;
        printf("Enter The Array: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        Qsort(arr,0,n-1,&SW,&CMP);
        printf("Array After Sorting: ");
        Disp(arr,n);
        printf("Number of Comparisons: %d\n", CMP);
        printf("Number of Swaps: %d\n", SW);
        
    }   
    return 0;
} 

int Div(int arr[], int low, int high, int* CMP, int* SW) 
{
    int temp;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        (*CMP)++;
        if (arr[j] <= pivot) 
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            (*SW)++;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    (*SW)++;
    return i+1;
}

void Qsort(int arr[], int low, int high, int* CMP, int* SW) 
{
    if (low < high) 
    {
        int PI = Div(arr, low, high, CMP, SW);
        Qsort(arr, low, PI-1, CMP, SW);
        Qsort(arr, PI+1, high, CMP, SW);
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