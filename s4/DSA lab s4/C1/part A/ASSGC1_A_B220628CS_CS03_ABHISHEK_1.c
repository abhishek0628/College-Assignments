//problem
/*
1. You have given mathematical expressions which have some duplicate parentheses. The expressions
consist of lowercase alphabets and operators (+, -, *, /, ˆ , %) without space, Your goal is to
identify and flag expressions that have duplicate parentheses. Duplicate parentheses occur when
the same subexpression is enclosed by multiple sets of parentheses. It’s important to note that a
single alphabet or operator by itself is also considered a valid expression. Hint: use stack
Input format:
• The first line is an integer where n ∈[1, 106].
• The second line contains valid mathematical expressions of size ’n’
Output format:
• The output consists of a single line with an integer value ( 0 or 1 )
0 representing the absence of duplicate parentheses
1 representing the presence of duplicate parentheses
Sample Input 1:
15
(a+b)%(c+(a-b))
Sample Output 1:
0
Sample Input 2:
7
(a+(b))
Sample Output 2:
1
*/
//solution
#include<stdio.h>
