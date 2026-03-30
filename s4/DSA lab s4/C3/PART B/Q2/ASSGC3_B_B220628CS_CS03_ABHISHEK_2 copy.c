//problem
/*
2. Write a Program to compute the Minimum spanning tree of a connected undirected graph G using
Kruskal’s Algorithm
Input format:
• First line contains an integer n ∈ [1, 1000],that denotes the number of vertices in the graph.
• The subsequent n lines contain the label of the respective node followed by the nodes adjacent
to it sorted in ascending order from left to right separated by single space.
• The subsequent n lines contain label of the respective node followed by the weights of the
edges corresponding to the adjacency list separated by single space. The edge weights are real
numbers in the range [-10000, 10000]. Further, no two edges have the same weight.
Output Format:
• Single line containing the sum of the edge weights of the minimum spanning tree.
Sample Input 1:
5
0 1 2 3 4
1 0 2
2 0 1 3
3 0 2 4
4 0 3
0 1 7 10 5
1 1 3
2 7 3 4
3 10 4 2
4 5 2
Sample Output 1:
10
Sample Input 2:
6
0 1 2
1 0 2 4
2 0 1 3 4
3 2 4 5
4 1 2 3 5
5 3 4
0 7 8
1 7 3 6
2 8 3 3 4
3 3 2 2
4 6 4 2 5
5 2 5
Sample Output 2:
17
*/
//solution
#include<stdio.h>
