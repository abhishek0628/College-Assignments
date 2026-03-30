//problem
/*
3. In the magical world of Althoria, alchemists are researching an elusive elixir with mystical properties.
They've discovered a series of runes that correspond to different ingredients and their potencies.
However, the runes are scattered and need to be rearranged to unlock the secret formula. Each rune
has a numeric value representing its potency. The alchemists believe that the most potent runes should
appear at the beginning of the sequence, gradually decreasing in potency. Your task is to help the
alchemists sort the runes in this manner so they can decipher the formula and unlock the elixir's
secrets.
Implement a function that takes an array of rune potencies and sorts them using the selection sort
algorithm in descending order of potency.
Input Format:
● The first line contains the number of runes N∈[1,10^3].
● Second line consists of their potencies separated by one space each. Potencies lie in the range ∈
[1, 10^3].
Output Format:
● A Single line in which potencies are sorted in descending order.
Sample Input:
6
46 72 18 4 96 32
Sample Output:
96 72 46 32 18 4
*/

//solution
#include<stdio.h>
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
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
    bubblesort(arr,n);
    printarray(arr,n);
    return 0;
}