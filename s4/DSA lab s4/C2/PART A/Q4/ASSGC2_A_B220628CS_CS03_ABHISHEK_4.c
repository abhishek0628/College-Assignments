//problem
/*
4. Given a parenthesis representation of a tree. Construct the tree for the given input and check
whether the tree satisfies the red-black tree properties or not. Write a function “checkRedblack-
Tree(root)” to check the tree is red-black tree or not and return return boolean values 1 if it is a
red-black tree otherwise 0.
Input format:
• First line of the input contains a space separated Paranthesis representention of the tree T.
R -¿red and B-¿black
Output format:
• Return the value “1” if it is a red-black tree ,otherwise return “0”
Sample input 1:
(10 B (4 B ( 2 R ( ) ( ) ) (5 R ( ) ( ) ) ) (15 B ( ) ( ) ) )
Sample output 1:
1
Sample input 2:
( 15 B ( 8 B ( 4 R ( ) ( ) ) ( ) ) ( 34 B ( 27 R ( 22 B ( ) ( ) ) ( ) ) ( 63 B ( ) ( ) ) ) )
Sample output 2:
0
*/

//solution
#include<stdio.h>
