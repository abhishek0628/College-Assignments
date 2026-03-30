//problem
/*
2. You work for an online bookstore that recently migrated its inventory to a new system. However,
during the migration process, the books in the inventory got jumbled up, and they need to be sorted
again. The bookstore manager has asked you to use the insertion sort algorithm to sort the books by
their ISBN (International Standard Book Number), which is a unique identifier for each book. Take
ISBN in an integer array arr[] and then sort the given array using insertion sort.
Input format:
• The first line of the input contains an integer n ∈ [1, 10^3], the size of the array ‘arr’ representing
the number of books.
• The second line lists the n elements in ‘arr’, as space-separated integers in the range [1 , 10^3]
representing the unsorted ISBN of the books.
Output Format:
• The first line of the output contains the elements of ‘arr’ in sorted order, separated by space.
Sample input:
5
4 1 3 9 7
Sample Output:
1 3 4 7 9
*/
#include<stdio.h>
void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 &&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
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
    insertionsort(arr,n);
    printarray(arr,n);
    return 0;
}