// Given an unsorted array of integers, design an algorithm and implement it using a program  to sort
// an array of elements by dividing the array into two subarrays and combining these subarrays after
// sorting each one of them. Your program should also find number of comparisons and inversions
// during sorting the array.

#include <stdio.h>
void Merge(int [],int,int,int,int*,int*);
void Merge_Sort(int [],int,int,int*,int*);
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
        int arr[n],INV=0,CMP=0;
        printf("Enter The Array: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        Merge_Sort(arr,0,n-1,&CMP,&INV);
        printf("Comparisons: %d \n",CMP);
        printf("Inversions: %d \n",INV);
        printf("Array After Sorting: ");
        Disp(arr,n);
    }   
    return 0;
}

void Merge(int arr[], int l, int m, int h, int* CMP, int* INV) 
{
    int l1, l2, i;
    int b[h];
    for(l1=l,l2=m+1,i=l;l1<=m && l2<=h; i++) 
    {
        (*CMP)++;
        if(arr[l1] <= arr[l2])
        {
            b[i] = arr[l1++];
        }
        else
        {
            b[i] = arr[l2++];
            (*INV)+=(m-l1+1);
        }
    }
   
    while(l1<=m)  
    {  
        b[i++] = arr[l1++];
    }

    while(l2 <= h)   
    {
        b[i++] = arr[l2++];
    }
    for(i = l; i <= h; i++)
    {
        arr[i] = b[i];
    }
}

void Merge_Sort(int arr[], int l, int h, int* cmp, int* inv) 
{
    if(l>=h) 
    {
        return;
    } 
    int m=(l+h)/2;
    Merge_Sort(arr,l,m,cmp,inv);
    Merge_Sort(arr,m+1,h,cmp,inv);
    Merge(arr,l,m,h,cmp,inv);
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