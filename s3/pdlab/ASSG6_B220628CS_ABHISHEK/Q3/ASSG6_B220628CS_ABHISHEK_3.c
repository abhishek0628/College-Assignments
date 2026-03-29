//problem
/*
3. Write a menu-driven program to implement a Queue Q using an array A[0..n−1]. Queue is to be
declared as a struct with three attributes, namely head, tail and array A[0..n−1]. The attribute
Q.head indexes its head and Q.tail indexes the next location at which a newly arriving element will
be inserted into the queue. The elements in the queue reside in locations Q.head, Q.head+1,....,
Q.tail-1, where the location 0 immediately follows location n-1 in a circular order.Your program
must contain the following functions: (in function prototypes, Q denotes a Queue and S denotes a
string of characters. All operations should run in O(1) time.)
• Main() - repeatedly reads an input character from the menu list through the terminal and
execute menu-driven operations accordingly. The menu list is [ ‘i’, ‘d’, ‘f ’, ‘e’ ‘t’ ] from the
terminal and calls the appropriate function until character ‘t’is entered.
• QueueFull(Q) - checks whether the Queue is full or not. It returns−1 when Q is full, else
returns 1.
• QueueEmpty(Q) - checks whether the Queue is empty or not. It returns−1 when Q is
empty, else returns 1.
• Enqueue(Q, S) - inserts the element S to the tail of Q and also check QueueFull() inside
this function.
• Dequeue(Q) - prints and deletes the element from the head of Q and also check QueueEmpty()
inside this function.
Input format:
• The first line of the input contains an integer n ∈[0, 105], the size of the array A.
• The next lines should begin with an input character from the menu list [ ‘i’, ‘d’, ‘f ’ , ‘e’, ‘t’ ]
followed by either nothing or one string of characters.
• Input ‘i’ should be followed by an alphanumeric string S ∈[A−Z, a−z, 0−9] of at most
20 characters separated by a space. In this operation, string S is inserted to the tail of Q by
calling the function Enqueue(Q, S).
• Input ‘d’ performs the Dequeue operation on Q by calling the function Dequeue(Q).
• Input ‘f ’ checks whether the Queue is full or not by calling the function QueueFull(Q).
• Input ‘e’ is to check whether the Queue is empty or not by calling the function QueueEmpty(Q).
• Input ‘t’ ‘terminate’ the program.
Output Format:
• The output (if any) of each input should be printed on a separate line.
• For option ‘i’and ‘f ’: Print−1 if Q is full.
• For option ‘d’and ‘e’: Print−1 if Q is empty.
• For option ‘f ’: Print 1 if Q is not full.
• For option ‘e’, Print 1 if Q is not empty.
Sample Input
5
i Abc20
i Xyz38
d
d
d
e
i Nit40
e
i IIT35
i IIM42
f
i Fix33
i Calc27
f
d
t
Sample Output
Abc20
Xyz38
-1
-1
1
1
-1
Nit40
*/

//solution
#include<stdio.h>
int main()
{
    return 0;
}
