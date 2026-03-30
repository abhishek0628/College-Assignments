//problem
/*
2. Write a program to create a Special Binary Search Tree T (as specified in question1) with
distinct keys (with values in the range [1, 106]) and perform the below specified operations. Reuse
the definitions and required functions from Question1 to complete this question. Input should be
read from console and output should be shown in console.
Your program should include the following functions.
• Main() - repeatedly reads a character ‘a’, ‘d’, ‘c’, ‘r’, ‘p’ or ‘e’ from the console and calls the
sub-functions appropriately until character ‘e’ is entered.
• Create-Node(k) - creates a new node of the tree with the key value ’k’ and returns a pointer
to the new node. All the pointer attributes of the new node are set to NIL.
• Insert(T, k) - inserts the node with key value ’k’ into the BST T.
Note: The caller of this function is assumed to create the node using the Create-Node()
function with key value ’k’.
• Delete(T, k) - deletes the node with key value k from the BST T . If a node with the input
key is not present in T , then print -1. Note: The caller of this function is assumed to invoke
Search() function to locate the node with key value k.
• Successor(T, k) - finds the successor of the node with key k in the BST T and prints the
key value of the successor node. Successor of the node I is the node that comes after node I
in the inorder traversal of the tree T.
• Predecessor(T, k) - finds the predecessor of the node with key k in the BST T and prints
the key value of the predecessor node. Predecessor of the node I is the node that comes before
node I in the inorder traversal of the tree T.
• Preorder(T ) - performs recursive preorder traversal of the BST T and prints the key value
in the nodes of T in preorder.
Note1 : If a node with the input key is not present in T , then print -1. Note 2 : If the T is
empty, then print -1.
Note 1 : Successor of the node I is the node that comes after node I in the inorder traversal of
the tree T
of the tree T
Note 2 : Predecessor of the node I is the node that comes before node I in the inorder traversal
Input format:
• Each line contains a character from ‘a’, ‘d’, ‘c’, ‘r’, ‘p’, or ‘e’ followed by at most one integer.
The integers, if given, are in the range [1, 106].
• Character ‘a’ is followed by an integer separated by space. In this operation, a node with this
integer as key is created and inserted into T by calling the function Insert().
• Character ‘d’ is followed by an integer separated by space. In this operation, the node with
this integer as key is deleted from T and the deleted node’s key is printed calling the function
Delete().
• Character ‘c’ is followed by an integer separated by space. This operation is to find successor
of the node with this integer as key in T by calling the function Successor().
• Character ‘r’ is followed by an integer separated by space. This operation is to find predecessor
of the node with this integer as key in T by calling the function Predecessor().
• Character ‘p’ is to perform preorder traversal of T by calling the function Preorder().
• Character ‘e’ is to exit the program.
Output Format:
• The output (if any) of each command should be printed on a separate line.
• For option ‘d’, print the deleted node’s key. If a node with the input key is not present in T
, then print -1.
• For option ‘c’, if the successor is present in T , then print the data in the successor node. If
successor is not present in T, then print -1.
• For option ‘r’, if the predecessor is present in T , then print the data in the predecessor node.
If predecessor is not present in T, then print -1.
• For option ‘p’, print the key value in the nodes of T obtained from preorder traversal. Print
-1 if T is empty.
Sample Input:
a 50
d 20
a 30
a 60
a 20
a 40
c 30
r 40
p
e
Sample Output:
-1
20
50
50 60 30 40 20
*/
#include<stdio.h>
int main()
{
    return 0;
}
