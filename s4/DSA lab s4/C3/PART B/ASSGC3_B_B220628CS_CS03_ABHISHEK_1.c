//problem
/*
1. Write a Program to compute the Minimum spanning tree of a connected undirected graph G using
Prim’s algorithm . Print the sequence with which edges are picked by algorithm and total edge
weight of spanning tree. The goal is to implement the following functions:
(a) Sequence(x) : Print sequence in which edges will be picked if x is starting node.
(b) Total weight() : Print total cost of the minimum spanning tree.
Input format:
• First line contains an integer n ∈ [1, 1000], that denotes the number of vertices in the graph.
• The subsequent n lines contain an Adjacency matrix of size (n * n) . If two nodes are directly
connected by an edge, it is denoted by a positive integer in the matrix; else it is denoted by
0. The positive integer corresponds to the weight on the edge. Assume that all edge weights
will be distinct.
• Each line of input is a character from the menu list [’s’,’t’,’x’].
• Input ’s’ calls the function Sequence(x).
• Input ‘t’ calls the function Total weight().
• Input ‘x’ terminates the execution of the program.
• All the inputs in a line are separated by space.
Output format:
• Line contains an integer representation of the total edge weight of the spanning tree or , Line
contains sequence of integer representing sequence of edges.
Sample Input 1:
6
0 2 0 3 7 0
2 0 1 0 8 0
0 1 0 4 0 5
3 0 4 0 0 6
7 8 0 0 0 0
0 0 5 6 0 0
t
s(1)
x
Sample Output 1:
18
1 2 1 0 0 3 2 5 0 4
Sample Input 2:
5
0 1 5 0 0
1 0 2 0 0
5 2 0 3 6
0 0 3 0 4
0 0 6 4 0
t
s(1)
x
Sample Output 2:
10
1 0 1 0 2 3 3 4
*/

//solution
#include<stdio.h>
