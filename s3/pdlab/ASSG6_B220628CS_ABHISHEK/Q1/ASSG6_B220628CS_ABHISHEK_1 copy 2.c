//problem
/*
1. Write a menu driven program to implement a Stack S of at most n elements using an array
A[0..n−1]. Stack is to be declared as a struct with an attribute top and an array A[0..n−1]
as members. The attribute top indexes the most recently inserted element in the stack. The
stack consists of elements A[0..S.top] where A[0] is the element at the bottom of the stack and
A[S.top] is the element at the top. Your program must contain the following functions: (In function
prototypes, S denotes a stack, and k denotes a character. All operations should run in O(1) time.)
• Main() - repeatedly reads an input character from the menu list through the terminal and
executes menu-driven operations accordingly. The menu list is [ ‘i’, ‘d’, ‘p’ or ‘t’ ]. The
program terminates when ‘t’ is entered.
• Stack-Empty(S) - checks whether the Stack S is empty or not. It returns−1 when S is
empty, else returns 1.
• Stack-Full(S) - checks whether the Stack S is full or not. It returns−1 when S is full, else
returns 1.
• Push(S, k) - inserts k to the top of S and check Stack-Full() inside this function.
• Pop(S) - prints and deletes the most recently inserted element from S (check Stack-Empty()
inside this function).
• Peek(S) - returns the top element of S.
Input Format:
• The first line of the input contains an integer n ∈[0, 105], the capacity of stack S.
• Next line inputs a character from the menu list [ ‘i’, ‘d’, ‘p’, or ‘t’ ] followed by either nothing
or one upper case alphabet.
• Input ‘i’ should be followed by a character C ∈[A..Z] that is separated by a space. In this
operation, the character C is inserted to S by calling the function Push(S, C).
• Input ‘d’ performs the Pop operation on S by calling the function Pop(S).
• Input ‘p’ perform the Peek operation on S by calling the function Peek(S).
• Input ‘t’ is to ‘terminate’ the execution of the program.
Output Format:
• The output (if any) for each input should be printed on a separate line.
• For option ‘i’: Print -1 if S is full.
• For option ‘p’and ‘d’: Print -1 if S is empty.
Sample Input :
5
i D
i H
d
i A
i D
i Z
i K
i X
d
d
d
p
i Y
d
d
d
p
d
t
Sample Output:
H
-1
K
Z
D
A
2
Y
A
D
-1
-1
*/

//solution
#include<stdio.h>
int main()
{
    return 0;
}
