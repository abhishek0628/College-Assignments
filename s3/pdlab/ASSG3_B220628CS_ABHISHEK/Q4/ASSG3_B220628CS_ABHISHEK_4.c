//problem
/*
4. Imagine you're an employee at TechCorp, tasked by your manager ‘Alex’ to analyze sales data.
This data contains information about various products and their sales figures. Your goal is to
identify the K best-selling products by arranging them in descending order of sales. To achieve
this, ‘Alex’ suggests using a special method, which parallels the process of sorting and
prioritizing tasks in an office environment. As you apply this technique to the sales figures, the
top-performing products gradually come into focus. Once sorted, you present the list of K top-
selling products to Alex, showcasing your analytical skills and efficiency in tackling real-world
challenges using sorting strategies.
Input Format:
● The first line contains the no of products. N ∈ [1,1000] and K<N, separated by a space
● The second line contains the sales figures of the products. Arr[i], where Arr[i] ∈ [0,10^4]
Output Format:
● One line containing the K highest sales figures in descending order.
Sample Input:
5 2
12 5 787 1 23
Sample Output:
787 23
*/
#include<stdio.h>
void k_heighst(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int max=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[max])
            {
                max=j;
            }
        }
        int temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
    }
}
void printarray(int arr[],int k)
{
    for(int i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    k_heighst(arr,n);
    printarray(arr,k);
    return 0;
}