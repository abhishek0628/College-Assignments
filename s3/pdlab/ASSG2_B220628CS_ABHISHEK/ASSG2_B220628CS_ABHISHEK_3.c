//problem
/*
3. You are given an array of ‘n’ integers (both positive and negative) so that the sequence strictly
increases until it reaches a peak, and then strictly decreases. This is known as a mountain array.
You are given such an array. The peak element is an element at position ‘i’ such that:
arr[ i-1 ] < arr[ i ] and arr[ i+1 ] < arr[ i ]
You are asked to use the best known algorithm to minimize the number of comparisons done by
your program on an average to find the peak (Hint: Binary Search).
Along with the peak element, you should also print the number of comparisons done by your
program for finding the peak.
Input Format:
• First line contains the number of elements ’n’ in the array n ∈[1, 103].
• Second line contains the elements in the array arr ∈[−103
, 103].
Output Format:
• an integer containing the peak element.
• an integer indicating the number of comparisons done by the program
Sample Input 1:
9
1 3 5 6 7 8 5 3 2
Sample Output 1:
8
6
Sample Input 2:
5
1 2 3 4 5
Sample Output 2:
5
5
*/

//solution
#include <stdio.h>
void binary(int arr[], int l, int h, int n)
{
    int cmp = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        
        if (mid == n - 1)
        {
            
            if (arr[mid - 1] < arr[mid])
            {
                cmp++;
                printf("%d\n", arr[mid]);
                printf("%d", cmp);
                return;
            }
        }
        if(mid==0)
        {
            if(arr[mid]>arr[mid+1])
            {
                cmp++;
                printf("%d\n",arr[mid]);
                printf("%d",cmp);
            }
            
        }
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            cmp=cmp+2;
            printf("%d\n", arr[mid]);
            printf("%d", cmp);
            return;
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
        {
            cmp=cmp+2;
            l = mid + 1;
        }
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
        {
            cmp=cmp+2;
            h = mid - 1;
        }
        
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    binary(arr, 0, n - 1,n);
    return 0;
}