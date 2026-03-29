//problem
/*
1. Imagine you are a software developer working on a project that involves optimizing search algo-
rithms for large datasets. Your team is tackling a specific problem of finding missing elements in
ascending sequences. You receive a task to write a program for the following problem:
Given an ascending sequence, denoted by an array ’A’, its size ‘n’ and an integer ’k’, the objective is
to determine the k-th missing contiguous element (k-th element in the sequence of missing elements)
in this sequence. If the k-th missing element is not there for the sequence, the program should
output -1. Additionally, you are asked to print the total number of array cells probed(accessed) by
your program during the search process to prove that you have written the most efficient code for
the problem.
Hint: (You can use Binary Search for minimizing the no of probes taken by your program on
an average).
Input Format:
• The first line is an integer n ∈[1, 106].
• The second line contains ’n’ integer numbers within the range ∈[1, 105] separated by a space
, representing the array elements.
• The third line of the input is an integer k ∈[1, 109]
Output Format:
• A single line contains two integer values separated by a space, representing k-th missing
number and the number of array probes done by the program.
Sample Input 1:
6
1 2 3 6 8 10
3
Sample Output 1:
7 3
Sample Input 2:
5
4 9 10 14 19
5
Sample Output 2:
6 3

*/

//solution
#include<stdio.h>
void search(int *arr,int l,int h,int k)
{
    int prob=0;
    int missing=0;
    int count=0;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if()
    }

}
int main()
{
    return 0;
}