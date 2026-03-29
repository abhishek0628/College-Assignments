//problem
/*
3. You are given a weighted undirected graph represented as an adjacency list. Your task is to
implement Dijkstra’s algorithm to find the shortest distances from a given source node to all other
nodes in the graph.
Input format:
• The first line contains an integer (n), specifying the number of nodes in the graph.
• The subsequent n lines contain the label of the respective node, followed by the nodes adjacent
to it in ascending order of their labels.
• The subsequent n lines contain the label of the respective node, followed by the weights of the
edges (0 < weight < 100) corresponding to the adjacency list.
• The next line contains an integer (s), specifying the source node.
• All the inputs are separated by a space.
Output format:
• Single line containing the shortest distance from the source node to each node in the graph in
ascending order of their labels (separated by space).
Sample Input 1:
5
1 2
2 1 3 4 5
3 2 4
4 2 3 5
5 2 4
1 5
2 5 10 2 3
3 10 8
4 2 8 5
5 3 5
2
Sample Output 1 :
5 0 10 2 3
Sample Input 2:
8
1 2
2 1 3
3 2 4 5
4 3 5 6
5 3 4 8
6 4 7
7 6 8
8 5 7
1 2
2 2 3
3 3 4 1
4 4 2 5
5 1 2 5
6 5 2
7 2 1
8 5 1
1
Sample Output 2 :
0 2 5 8 6 13 12 11
*/
#include<stdio.h>
