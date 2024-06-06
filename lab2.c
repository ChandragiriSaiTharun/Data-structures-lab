/*
-> Write a C program to implement Merge Sort containing
    Name of functions : mergeSort(int arr[], int low, int high),
    merge(int arr[], int low, int mid, int high), printArray(int arr,int n)
    
    Test Cases :
    Input : ------
    Output :
    Initial array elements : 50, 30, 80, 20, 10, 15, 90
    After Sorting : 10, 15, 20, 30, 50, 80, 90
*/
#include<stdio.h>
#include<stdlib.h>

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void merge(int a[],int low,int mid,int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i] = a[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i] = a[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void main()
{
    int arr[7] = {50,30,80,20,10,15,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Initial Array elements : ");
    printArray(arr,n);
    printf("\nAfter Sorting : ");
    mergeSort(arr,0,n-1);
    printArray(arr,n);
}
