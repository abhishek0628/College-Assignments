//problem
/*
4. You are given a weighted undirected graph represented as a weighted adjacency matrix. Your task
is to implement the Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
in the graph.
Input format:
• The first line contains an integer (n), specifying the number of nodes in the graph.
• The next n lines contain n space-separated integers, representing the weighted adjacency
matrix of the graph. Each integer represents the weight of the edge (0 < weight < 100)
between the corresponding pair of nodes. If there is no direct edge between two nodes, the
weight is represented as -1.
• The diagonal elements of the adjacency matrix are always 0 (indicating no self-loops).
Output format:
• Print n lines, each containing n space-separated integers. The j-th integer in the i-th line
represents the shortest distance from node i to node j.
Sample Input 1:
4
0 5 -1 7
5 0 3 -1
-1 3 0 2
7 -1 2 0
Sample Output 1 :
0 5 8 7
5 0 3 5
8 3 0 2
7 5 2 0
Sample Input 2:
5
0 3 -1 7 -1
3 0 2 -1 -1
-1 2 0 5 1
7 -1 5 0 6
-1 -1 1 6 0
Sample Output 2 :
0 3 5 7 6
3 0 2 7 3
5 2 0 5 1
7 7 5 0 6
6 3 1 6 0
*/
//solution
#include<stdio.h>
