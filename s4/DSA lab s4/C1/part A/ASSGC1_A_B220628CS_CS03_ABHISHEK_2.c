//problem
/*
2. A Singly linked list L is a data structure in which the objects are arranged in a linear order.
Each node of a Singly linked list L is an object with an attribute key and one pointer attribute,
next. Given a node x in the list, x.next points to its successor in the linked list. An attribute
L.head points to the first node of the list.
Write a menu driven program to implement an unsorted Singly linked list L. Your program
must contain the following functions:
Your main() function shall read the choice from the console and call the following functions appro-
priately: Your program must contain the following functions:
• Main() - repeatedly reads a character ‘a’, ‘r’, ‘d’, ‘p’, ‘s’ from the terminal and calls the
sub-functions appropriately until character ‘e’ is entered.
• CREATE-NODE(k) - creates a new node with key k and pointer next of node points to
NULL. This procedure returns a pointer to the new node.
• LIST-INSERT(L, x) - inserts x as the last node of L.
• LIST-DELETE(L, i) - deletes the node at index i from L and print the deleted key value.
The position is determined by its index, considering first node at index 1. If i is not found in
L, then print−1
• LIST-Rduplicate(L) - Remove duplicates: This function will remove duplicates from the
list L and after removal the updated list L is printed.
• LIST-Pal(L): Function is used to check whether the linkedlist L is palindrome or not.The
function will return Y (if it is a palindrome) otherwise N.
(In case of even length linkedlist , the first node is considered as middle node).
• LIST-DISPLAY(L) - prints the list L
Note:- For every INSERT operation, the node x is created by calling CREATE-NODE() function.
Input format:
• Each line contains a character from ‘a’, ‘r’, ‘d’, ‘p’, ‘s’, ‘e’ followed by zero, one or two
integers. The integers, if given, are in the range [−106
, 106].
• Character ‘a’ is followed by an integer separated by space. In this operation, the node with
this integer as key is inserted to the tail of L.
• Character ‘r’ is followed by an integer i separated by space. In this operation, the node at
index i is deleted from L and the deleted node’s key value is printed. Considering first node
at index 1, if i is not found in L, then print−1
• Character ‘d’ This operation will remove duplicates from the list L and after removal the
updated list L is printed.
• Character ‘p’ is f to check whether the linkedlist L is palindrome or not.The function will
return Y (if it is a palindrome) otherwise N.
(In case of even length linkedlist , the first node is considered as middle node).
• Character ‘s’ This operation is to print the list L.
• Character ‘e’ is to ‘exit’ from the program.
Output Format:
• The output (if any) of each command should be printed on a separate line.
• For options ‘r’, ‘d’ , ‘p’ and ‘s’ if a node with the input key is not present in L or L is empty,
then print−1.
Sample Input 1:
a 1
a 2
a 2
a 1
a 5
a 6
r 6
r 5
p
d
s
Sample Output 1:
6
5
Y
1 2
1 2
Sample Input 2:
a 1
a 3
a 7
a 8
a 2
a 5
a 3
r 2
r 3
p
d
s
Sample Output 2:
3
8
N
1 7 2 5 3
1 7 2 5 3
*/

//solution
#include<stdio.h>
