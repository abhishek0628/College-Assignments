//problem
/*
3. You are given an integer N representing the number of nodes in the graph . The graph is represented
by adjacency list .The next N lines represent an adjacency list where first integer is node itself and
next integers are the nodes adjacent to it in ascending order . The goal is to implement the following
using a Depth-First Search (DFS) traversal algorithm:
• All path(Node1,Node2): Print all paths from a given source to a destination vertex. Sep-
arate each path with a new line , otherwise print -1 if no path exists between nodes.
NOTE - paths are printed in sorted order
• valid tree():This function checks if the given graph is a tree or not. A valid tree has the
following properties:
(a) There are no cycles (loops) in the graph.
(b) Every vertex is reachable from the root vertex.
(c) There are no isolated vertices (vertices not connected to the rest of the graph).
function prints 1 if the given graph is a tree else -1
Input format:
• The first line contains an integer N specifying the number of nodes in the graph.
• Next “N” lines are sequence of integers where first integer is node itself and next integers in
that line are representing nodes which are adjacent to that node.
• Each line of input is a character from the menu list [’a’,’t’,’x’].
• Input ’a’ calls the function All path(Node1,Node2).
• Input ‘t’ calls the function valid tree()
• Input ‘x’ terminates the execution of the program.
• All the inputs in a line are separated by space.
Output format:
• A line may contain -1 or 1.
• The output of the result of any menu is printed in a new line.
Sample Input 1:
6
0 1 3 5
1 0 2 5
2 1 3 4
3 0 2
4 2
5 0 1
t
a 1 4
a 0 1
x
Sample Output 1 :
-1
1 0 3 2 4
1 2 4
1 5 0 3 2
0 1
0 3 2 1
0 5 1
Sample Input 2:
8
0 1 7
1 0 2
2 1 3 4 5 6
3 2
4 2
5 2
6 2
7 0
a 6 7
a 0 6
t
x
Sample Output 2 :
6 2 1 0 7
0 1 2 6
1
*/

//solution
#include<stdio.h>
