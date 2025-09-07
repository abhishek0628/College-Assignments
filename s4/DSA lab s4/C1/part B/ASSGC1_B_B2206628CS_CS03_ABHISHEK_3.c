//problem
/*
3. Given the PARENTHESIS REPRESENTATION of a binary search tree(BST) T with n nodes
(where n ∈[1,103]). Write a menu driven program to implement the operations outlined below:
(a) PrintRangeValues(T, k1,k2):This function takes two key values k1 and k2 (k1 ̸= k2) that
specify the range of key values as input arguments and prints the key values of the nodes that
are in the given range(inclusive of k1 and k2).
(b) Ancestors(T,k): This function takes key value k as an input argument and prints all the
ancestors of k in T where k ∈ [1,106] ( order starting from the node itself up to the root).
Ancestor of a node x: We call any node y on the unique simple path from the root of the binary
tree to x an ancestor of x. Please note that x is also an ancestor of itself.
Input Format:
• First line of the input contains a space separated Parenthesis Representation of the tree T
with key values ∈[1, 106].
• Next each line contains a character ‘p’ (followed by an integer) or ’a’ (followed by two integers).
• Character ‘p’ followed by two integer values (key values) is to print the key values of the nodes
that are in the given range.
• Character ‘a’ followed by one integer value(key value) is to print all the ancestors of k in BST.
Output Format:
• The output (if any) of each command should be printed on a separate line.
Sample Input 1:
7(5(2)(6))(9(8)(10))
p 5 8
a 8
Sample Output 1:
5 6 7 8
8 9 7
Sample Input 2:
8(5()(6))(10()(11))
a 6
p 8 11
Sample Output 2:
6 5 8
8 10 11
*/

//solution
