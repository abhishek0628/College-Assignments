//problem
/*
2. You are given a positive integer N . Print all integers from 1 to N without using any of the looping
constructs.
Input Format:
• The first line is a positive integer N ∈[1, 103].
Output Format:
• A single line of integers from 1 to N each separated by a single space between them.
Sample Input:
5
Sample Output:
1 2 3 4 5
*/

//solution
#include<stdio.h>
void print(int n)
{
    if(n==0)return;
    print(n-1);
    printf("%d ",n);
}
int main()
{
    print(5);
    return 0;

}