//problem
/*
1. Given two integer arrays A and B, implement the following functions on them using hashing:
(a) union(A,B) or union(B,A): prints the union of the elements of A and B (or B and A) in the
order of appearance of elements in A followed by B (or B followed by A).
(b) intersection(A,B) or intersection(B,A): prints the intersection of the elements of A and B
(or B and A) in the order of appearance of elements in A followed by B (or B followed by A).
(c) setDifference(A,B) or setDifference(B,A): prints the set difference of the elements of A and
B (or B and A) in the order of appearance of elements in A (or B).
Input Format:
• The first line contains two integers m and n (space-separated), which tell the size of input
arrays A and B.
• The second line contains m positive integers (space-separated) in input array A.
• The third line contains n positive integers (space-separated) in input array B.
The remaining inputs are as follows:
• Each line of input contains three characters separated by a space: the first character from the
menu list [’u’,’i’,’s’,’e’], the second, and third characters specify the arrays A, B, or (B,A).
• Input ‘u’ followed by ‘A’ ‘B’( or ‘B’ ‘A’) calls the function union(A,B) or union(B,A), which
prints the union of the elements of A and B (or B and A) in the order of appearance of
elements in A followed by B (or B followed by A).
• Input ‘i’ followed by ‘A’ ‘B’( or ‘B’ ‘A’) calls the function intersection(A,B) or intersec-
tion(B,A), which prints the intersection of the elements of A and B (or B and A) in the order
of appearance of elements in A (or B).
• Input ’s’ followed by ‘A’ ‘B’( or ‘B’ ‘A’) calls the function setDifference(A,B) or setDiffer-
ence(B,A), which prints the set difference of the elements of A and B (or B and A) in the
order of appearance of elements in A (or B).
• Input ‘e’ terminates the execution of the program.
Output Format:
• A line may contain -1 if there are no elements to print.
• The output of the result of any menu is printed in a new line with a space between each
integer.
Constraints:
• Do not use sorting.
• Do not consider duplicate elements.
• The hash table size should not be greater than 2*max(m, n). Use open addressing for
handling collisions in hashing.
• 1<=A[i],B[i] <=100
Sample Input 1:
5 6
1 2 3 4 5
2 5 1 6 7 8
u A B
u B A
i A B
i B A
s A B
2
s B A
e
Sample Output 1:
1 2 3 4 5 6 7 8
2 5 1 6 7 8 3 4
1 2 5
2 5 1
3 4
6 7 8
Sample Input 2:
6 7
1 1 2 2 3 3
3 3 2 2 1 6 5
u A B
u B A
i A B
i B A
s A B
s B A
e
Sample Output 2:
1 2 3 6 5
3 2 1 6 5
1 2 3
3 2 1
-1
6 5
*/

//solution
