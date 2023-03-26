/*3. . . Given an unsorted array of positive integers, design an algorithm and implement
it using a program to find whether there are any duplicate elements in the array or not.
(use sorting) (Time Complexity = O(n log n))*/

#include <stdio.h>
void Quick_Sort(int [],int,int);
int Dup(int [],int);
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
        int arr[n];
        printf("Enter The Array: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        if(Dup(arr,n))
        {
            printf("YES \n");
        }
        else
        {
            printf("NO \n");
        }
    }
    return 0;
}

void Quick_Sort(int arr[],int f,int l)
{  
    int i, j, pivot, temp;
    if(f<l)
    {
        pivot=f;
        i=f;
        j=l;
        while(i<j)
        {
            while(arr[i]<=arr[pivot]&&i<l)
            i++;
            while(arr[j]>arr[pivot])
            j--;
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        Quick_Sort(arr,f,j-1);
        Quick_Sort(arr,j+1,l);
    }
} 

int Dup(int arr[],int n)
{
    int i;
    Quick_Sort(arr,0,n);
    for(i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            return 1;
            break;
        }
    }
    return 0;
}