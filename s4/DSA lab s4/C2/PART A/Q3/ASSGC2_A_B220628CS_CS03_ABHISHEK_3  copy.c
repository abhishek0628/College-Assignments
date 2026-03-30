//problem
/*
3. Write a program to Create a Red Black Tree from the given input. Your program should include
the following function:
• InsertinRedBlack(struct Node* root,key): Inserts a new node with the ‘key’ into the tree and
prints parenthesized representation (with corresponding colors) of the created red-black tree.
NOTE: A Red-Black tree is a self-balancing binary search tree where every node obeys the fol-
lowing rules:
• Every node is either red or black.
• The root is always black.
• There are no two adjacent red nodes (A red node cannot have a red parent or red child).
• All paths from a node to descendant nodes contain the same number of black nodes.
Input Format:
• Each line of the input contains a positive integer ‘key’ or a character ‘e’.
• If the input is a positive integer then Call function InsertinRedBlack(root, key).
• If ‘e’ is encountered, terminate the program.
Output format:
• For each line of the input, the corresponding line of the output should contain the Parenthesis
Representation (key value followed by the color) of the current tree.
Sample Input 1:
15
8
27
34
4
63
22
e
Sample output 1:
(15 B ( ) ( ) )
(15 B ( 8 R ( ) ( ) ) ( ) )
(15 B ( 8 R ( ) ( ) ) ( 27 R ( ) ( ) ) )
(15 B ( 8 B ( ) ( ) ) ( 27 B ( ) ( 34 R ( ) ( ) ) ) )
(15 B ( 8 B( 4 R ( ) ( ) ) ( ) ) ( 27 B ( ) ( 34 R ( ) ( ) ) ) )
(15 B ( 8 B( 4 R ( ) ( ) ) ( ) ) (34 B ( 27 R ( ) ( ) ) ( 63 R ( ) ( ) ) ) )
( 15 B ( 8 B ( 4 R ( ) ( ) ) ( ) ) ( 34 B ( 27 B ( 22 R ( ) ( ) ) ( ) ) ( 63 B ( ) ( ) ) ) )
Sample input 2:
10
4
15
2
5
e
Sample output 2:
(10 B ( ) ( ) )
(10 B (4 R ( ) ( ) ) ( ) )
(10 B (4 R ( ) ( ) ) (15 R ( ) ( ) ) )
(10 B (4 B ( 2 R ( ) ( ) ) ( ) ) (15 B ( ) ( ) ) )
(10 B (4 B ( 2 R ( ) ( ) ) (5 R ( ) ( ) ) ) (15 B ( ) ( ) ) )
*/
//solution
#include<stdio.h>
