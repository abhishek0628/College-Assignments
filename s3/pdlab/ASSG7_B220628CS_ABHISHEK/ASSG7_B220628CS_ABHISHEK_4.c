//problem
/*
Q4. You are a software engineer working on an advanced project to create a powerful tool for
manipulating and analyzing mathematical expressions. This tool is essential for engineers and scientists
dealing with complicated mathematical computations.
Your program should provide the following features:
• Infix to Postfix Conversion: Implement a function that converts an infix mathematical
expression to postfix notation.
• Expression Evaluation: Implement a function to evaluate a given postfix mathematical
expression and display the result. It can handle basic arithmetic operations, including addition,
subtraction, multiplication, and division.
• Expression Tree Analysis: Implement functions to display the height of the expression tree and
find the minimum length from the root to any leaf.
Input Format:
• A single line contains the character 'i', followed by a valid infix expression. This expression is a
combination of digits (operands) in the range [0,1000], binary operators '+', '−', '∗', and '/', and
special characters '(' and ')'; each separated by a single space.
Output Format:
• The first line display the postorder traversal of the given infix expression as a space separated
format.
• The second line is a Real number (Keep only two if there are more than two digits after the
decimal point), the result of given expression (Note: If the expression results in an answer
divisible by zero, print 'N').
• The third line is an integer, the height of the expression tree.
• The fourth line is an integer, the minimum length from the root to leaf.
Sample Input 1:
( ( 11 / 92 ) * ( 33 - 45 ) + 57 * 74 ) * ( 85 / 5 )
Sample Output 1:
11 92 / 33 45 - * 57 74 * + 85 5 / *
71681.60
4
2
Sample Input 2:
( 2 - 3 ) * ( 4 / 0 )
Sample Output 2:
2 3 - 4 0 / *
N
2
2
*/

//solution
#include<stdio.h>
int main()
{
    return 0;
}
