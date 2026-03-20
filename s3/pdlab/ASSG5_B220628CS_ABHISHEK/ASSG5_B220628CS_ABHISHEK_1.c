// problem
/*
1. Write a program that uses the Merge-Sort algorithm for sorting a given input sequence of
integers present in an array A. Your program must contain the following functions. (In what
follows, the notation A[p..r] denotes the sub-array of A, contained within the pth and rth indices,
both inclusive.)
• A recursive function Merge-Sort(A, p, r) that takes as input an array A and sorts the
elements in the sub-array A[p..r].
• A function Merge(A, p, q, r) that takes as input an array A in which the sub-arrays A[p..q]
and A[q + 1..r] are sorted. It then merges these sub-arrays such that the sub-array A[p..r] is
sorted.
• Print(A, n) - A function that takes as input an array A, the size of the array, and prints its
contents in order, with a single space separating the elements. This function should only be
called from the main() function.

Input format:
• The first line of the input contains an integer n ∈[0, 105], the size of the array A.
• The second line lists the n elements in A, as space-separated integers in the range [−103
, 103].
Output Format:
• The first line of the output contains the elements of A in sorted order, separated by space.
Note:
• In particular, to split an array A[p..r] into two sub-arrays, the Merge-Sort() function should
compute an index q ∈[p, r] such that A[p..q] contains ⌈n/2⌉elements, and A[q +1..r] contains
⌊n/2⌋elements).
Sample Input 1:
10
23 76 89 3 8 0 789 123 889 25
Samle Output 1:
0 3 8 23 25 76 89 123 789 889
Sample Input 2:
10
90 89 78 67 56 45 34 23 12 11
Sample Output 2:
11 12 23 34 45 56 67 78 89 90
*/
#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int left[n1];
    int right[n2];
    for(int i=l;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=arr[m+j+1];
    }
    int k=l,i=0,j=0;
    while(i<n1&& j<n2)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        
        k++;
    }

    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r)
{
    
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
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
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
