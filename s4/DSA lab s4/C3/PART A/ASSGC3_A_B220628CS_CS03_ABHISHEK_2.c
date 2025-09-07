//problem
/*
2. Given a directed graph containing N nodes as an adjacency matrix,implement the following using
a Breadth-First Search(BFS) traversal algorithm:
• Is Topological sort possible(): This function checks whether topological sort can be done on
the graph or not. A topological sort is a linear ordering of the vertices in a Directed Acyclic
Graph (DAG) such that for every directed edge e1− > e2 , vertex e1 appears before e2 in
the ordering. Topological sort is possible if and only if the graph is a DAG.This function will
print 1 if a topological sort is possible, -1 otherwise.
• Number of strongly components(): This function analyzes the graph defined by the edges and
calculates the number of connected components.
Input format:
• The first line contains an integer N specifying the number of nodes in the graph.
• Each line of input is a character from the menu list [’t’,’c’,’x’].
• Input ’t’ calls the function Is Topological sort possible().
• Input ‘c’ calls the function Number of strongly components()
• Input ‘x’ terminates the execution of the program
• All the inputs in a line are separated by space.
Output Format:
• A line may contain -1 or 1.
• The output of the result of any menu is printed in a new line.
Sample Input 1:
6
0 1 1 0 0 0
0 0 1 0 1 0
0 0 0 1 0 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
t
c
x
Sample Output 1:
1
6
Sample Input 2:
6
0 1 1 1 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 1 0 1
0 0 0 0 0 0
t
c
x
Sample Output 2:
1
4
*/

//solution
#include<stdio.h>
