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

// solution
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

// #include<stdio.h>
// int findpeak(int arr[],int *cmp,int n)
// {
//     int l=0,h=n-1;
//     if(l<=h)
//     {
//         int mid=l+(h-l)/2;
//         (*cmp)++;

//         if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 ||arr[mid]>arr[mid+1]))
//         {
//             return arr[mid];
//         }
//         (*cmp)++;
//         if(mid>0 && arr[mid-1]>arr[mid])
//         binary(arr,l,mid-1,cmp,n);
//         else
//         binary(arr,mid+1,h,cmp,n);
        
//     }
    
// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int temp=0;
//     int cmp=0;
//     binary(arr,0,n-1,&temp,&cmp,n);
//     printf("%d\n%d",temp,cmp);
//     return 0;
// }

// #include <stdio.h>

// int findPeak(int arr[], int n, int *cmp) {
//     int l = 0, h = n - 1;

//     while (l <= h) {
//         int mid = l + (h - l) / 2;
//         (*cmp)++; // comparison for peak check

//         // Handle edge cases for first and last element
//         if ((mid == 0 || arr[mid] > arr[mid - 1]) && 
//             (mid == n - 1 || arr[mid] > arr[mid + 1])) {
//             return arr[mid];
//         }

//         // If middle element is part of the increasing sequence
//         (*cmp)++; // comparison for arr[mid] < arr[mid+1]
//         if (arr[mid] < arr[mid + 1]) {
//             l = mid + 1; // move right
//         } else {
//             h = mid - 1; // move left
//         }
//     }
//     return -1; // just in case (should never happen for valid mountain)
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     int cmp = 0;
//     int peak = findPeak(arr, n, &cmp);

//     printf("%d\n%d\n", peak, cmp);
//     return 0;
// }
