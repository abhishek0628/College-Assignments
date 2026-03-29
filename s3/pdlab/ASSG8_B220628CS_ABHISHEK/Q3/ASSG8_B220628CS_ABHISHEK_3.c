//problem
/*
3. The Parenthesis Representation of a binary search tree is recursively defined as given below:
• The string ( ) represents an empty tree.
• The string ( k left-subtree right-subtree ) represents a tree whose root node has key k, left-
subtree is the left subtree of the root node and right-subtree is the right subtree of the root
node following the binary-search-tree property in Parenthesis Representation.
Write a program to create a binary search tree T, delete an existing node from the tree, and print
T in Parenthesis Representation. Your program should contain the following functions:
• Insert(T, k) - inserts the element ’k’ to the BST T.
• Delete(T, k) - deletes an existing element ’k’ from the BST T and place inorder successor.
• Print(T ) - that should take as input a pointer to the root node of the BST and print the
tree in its Parenthesis Representation.
Input format:
• Each line contains a character from ‘i’, ’d’, ‘p’ and ‘e’ followed by at most one integer. The
integers, if given, are in the range [1, 106].
• Character ‘i’ is followed by an integer separated by a single space. A node with this integer
as a key is created and inserted into T in this operation.
• Character ‘d’ is followed by an integer separated by a single space. A node with this integer
as a key is deleted from the T in this operation.
• Character ‘p’ is to print the Parenthesis Representation of the BST T.
• Character ‘e’ is to exit the program.
Output format:
• The output is the space-separated Parenthesis Representation of the BST T. Note: The
integer values, ‘(’ and ‘)’, are separated by exactly one space.
Sample Input:
p
i 10
p
i 20
p
i 5
d 10
p
i 40
i 15
i 25
p
Sample Output:
( )
( 10 ( ) ( ) )
( 10 ( ) ( 20 ( ) ( ) ) )
( 10 ( 5 ( ) ( ) ) ( 20 ( ) ( ) ) )
( 20 ( 5 ( ) ( ) ) ( ) )
( 20 ( 5 ( ) ( 15 ( ) ( ) ) ) ( 40 ( 25 ( ) ( ) ) ( ) ) )
*/

//solution
#include<stdio.h>
int main()
{
    return 0;
}
