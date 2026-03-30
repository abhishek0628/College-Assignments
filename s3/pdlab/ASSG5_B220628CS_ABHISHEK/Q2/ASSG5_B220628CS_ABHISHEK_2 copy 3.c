// problem
/*
2. Write a program that uses the Heap-Sort algorithm for sorting a given input sequence of integers
present in an array A in non-decreasing order. Your program must contain the following functions:
(the notation A[i..j] denotes the sub-array of A, contained within the ith and jth indices, both
inclusive).
• A recursive function Max-Heapify(A, i) that takes as input an array A and lets the value at
A[i] “float down” in the max-heap so that the subtree rooted at index i obeys the max-heap
property.
• A function Build-Max-Heap(A) that takes as input an array A and build a max-heap on
the input array A[1...n] where n is equal to A.length.
• A function Heapsort(A) that takes as input an array A and sorts an array A in place.
Input format:
• The first line of the input contains an integer n ∈[1, 105], the size of the array A.
• The second line lists the n elements in A, as space-separated integers in the range [−103
, 103].
Output Format:
• The first line of the output contains the elements of A in sorted order, separated by space.
Sample Input:
8
98 67 56 45 43 23 20 12
Sample Output:
12 20 23 43 45 56 67 98
*/
#include<stdio.h>
void max_heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(i!=largest)
    {
        int t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        max_heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        max_heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int t=arr[i];
        arr[i]=arr[0];
        arr[0]=t;
        max_heapify(arr,i,0);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
