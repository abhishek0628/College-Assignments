//problem
/*
You are given an undirected graph G. Implement the following functions using DFS as a sub-routine.
(a) noOfConnectedComponents(G): Print the total number of connected components in the graph.
A connected component is a maximal subgraph in which every pair of vertices are connected
by a simple path.
(b) sizeOfComponents(G): Print the sizes of all connected components in the graph, sorted in
increasing order of their sizes. The size of a component is the number of vertices it contains.
(c) noOfBridges(G): Print the number of bridges in the graph. If there are no bridges, print -1. A
bridge is an edge whose removal increases the number of connected components in the graph.
(d) noOfArticulationPoints(G): Print the number of articulation points in the graph. If there are
no articulation points, print -1. An articulation point is a vertex whose removal increases the
number of connected components in the graph
Input format:
• The first line contains an integer (m) specifying the number of nodes in the graph.
• The subsequent next m lines contain the label of the respective node, followed by the nodes
adjacent to it in ascending order of their labels.
• Each line of input is a character from the menu list [’n’,’s’,’b’,’a’,’t’]..
• Input ‘n’ calls the function noOfConnectedComponents(G).
• Input ’s’ calls the function sizeOfComponents(G).
• Input ‘b’ calls the function noOfBridges(G).
• Input ‘a’ calls the function noOfArticulationPoints(G).
• Input ‘t’ terminates the execution of the program.
• All the inputs in a line are separated by space.
Output format:
• A line may contain -1.
• The output of the result of any menu is printed in a new line.
Sample Input 1:
5
1 2
2 1
3 4
4 3 5
5 4
n
s
b
a
t
Sample Output 1:
2
2 3
3
1
Sample Input 2:
8
1 2
2 1 3
3 2 4
4 3 5 6
5 4
6 4 7
7 6 8
8 7
Sample Output 2:
1
8
7
5
*/

//solution
#include<stdio.h>
