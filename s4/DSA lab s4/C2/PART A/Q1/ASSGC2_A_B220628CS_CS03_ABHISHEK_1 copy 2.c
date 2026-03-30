//problem
/*
1. You are given a sequence of operations to perform on an AVL tree. Each operation is represented
by a character followed by its respective parameters. The operations are as follows: [ i , x , p , s ,
e]
Input format:
• Each line contains a character from ‘i’, ‘x’, ‘p’, ‘s’, ‘e’ followed by zero or one integers. The
integers, if given, are in the range ∈ [1, 106].
• i: AVL insert(T, key) - Insert the given key into the AVL tree T.
• x: AVL find(T, key) - Search for the given key in the AVL tree T. If the key is found, print
the path from the root to the node containing the key; otherwise, print -1.
• p: AVL preorder(T) - Print the preorder traversal of the AVL tree T.
• s: AVL cal(T) - Given a point, calculate the total number of left and right rotations required
to balance the AVL tree T at that point. left rotation, right rotation separated by space
• e: Exit - Terminate the sequence of operations.
NOTE : key ∈ [1, 106]
Output format:
For
• x : sequence of integers with space separated them representing path
• p : sequence of integers with space separated them representing preorder.
• s : two integer representing total number of left rotaions and right rotaions
Sample Input 1:
4
i 10
i 20
i 30
s
i 40
p
i 50
i 5
i 1
s
x 10
x 56
e
Sample Output 1:
1 0
20 10 30 40
2 1
20 5 10
-1
Sample Input 2:
i 167
i 34
i 121
s
i 56
i 198
i 73
i 112
p
x 112
s
e
Sample Output 2:
1 1
121 56 34 73 112 167 198
121 56 73 112
2 1
*/

//solution

#include<stdio.h>
