/*2. Given an unsorted array of integers, design an algorithm and implement a program
to sort this array using selection sort. Your program should also find number of
comparisons and number of swaps required.*/

#include <stdio.h>
void Selection_Sort(int [],int,int *);
void Disp(int [],int );
int main(void)
{
    int t,n,i,k,CP=0;
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
        Selection_Sort(arr,n,&CP);
        printf("Array After Sorting: ");
        Disp(arr,n);
        printf("Comparisons = %d \n",CP);
        printf("Swaps = %d \n",n-1);
    }
    return 0;
}

void Selection_Sort(int arr[],int n,int *CP)
{
int i,j,pos=0,min=0;
    for (i = 0; i < n-1; i++) 
    {
        min = arr[i];
        pos = i ;
        for(j=i+1;j<n;j++) 
        {
            (*CP)++;
            if(min>arr[j])
            {
                min=arr[j];
                pos=j;
            }
        }
        if(i!=pos)
        {
            arr[pos]=arr[i];
            arr[i]=min;
        }
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