//problem
/*
1. Write a program to compute the Minimum Spanning Tree (MST) of a connected, simple undirected
graph G using Prim’s algorithm. The program should print the sequence of edges picked by the
algorithm and the total edge weight of the spanning tree. Note that the vertices are labeled from
0 to n−1.
Implement the following functions:
(a) Sequence(x): Print the sequence in which edges will be picked if x is the starting node.
(b) TotalWeight(): Print the total cost of the minimum spanning tree.
Input Format
• The first line contains an integer n ∈[2, 1000], denoting the number of vertices in the graph.
• The subsequent n lines contain an adjacency matrix of size n ×n. If two nodes are directly
connected by an edge, it is denoted by a positive integer in the matrix; otherwise, it is denoted
by 0. The positive integer corresponds to the weight of the edge. Assume that all edge weights
will be distinct.
• Next line consists of a character from the list [’s’, ’b’, ’e’].
• Input ’s’ followed by a positive integer separated by a space calls the function Sequence(x).
• Input ’b’ calls the function TotalWeight().
• Input ’e’ terminates the execution of the program.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘e’.
• For character ’s’: Print each edge as a pair of vertices separated by a space followed by the
corresponding edge weight in parentheses.
• For character ’b’: Print an integer representing the total edge weight of the minimum span-
ning tree.
Sample test case 1
Input:
6
0 2 0 3 7 0
2 0 1 0 8 0
0 1 0 4 0 5
3 0 4 0 0 6
7 8 0 0 0 0
0 0 5 6 0 0
s 1
b
e
Output:
1 2 (1) 1 0 (2) 0 3 (3) 2 5 (5) 0 4 (7)
18
*/

//solution
#include<stdio.h>
#include<stdlib.h>

void printSequence(int vertices, int parent[], int adj_matrix[][vertices], int path[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(parent[path[i]] == -1)
        {
            continue;
        }
        printf("%d %d (%d) ", parent[path[i]], path[i],adj_matrix[parent[path[i]]][path[i]]);
    }
    printf("\n");
}

void weightOfMst(int vertices, int parent[], int adj_matrix[][vertices])
{
    int sum = 0;
    for(int i = 0; i < vertices; i++)
    {
        if(parent[i] == -1)
        {
            continue;
        }
        sum += adj_matrix[i][parent[i]];
    }
    printf("%d\n", sum);
}

int minKey(int vertices, int key[], int curr_mst[], int path[], int* j)
{
    int min = 9999;
    int min_index;
    for(int v = 0; v < vertices; v++)
    {
        if(curr_mst[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    path[(*j)++] = min_index;
    return min_index;
}

void primMst(int vertices, int adj_matrix[][vertices], int vertex, int flag)
{
    int parent[vertices];
    int key[vertices];
    int curr_mst[vertices];
    int path[100];
    int j = 0;

    for(int i = 0; i < vertices; i++)
    {
        key[i] = 9999;
        curr_mst[i] = 0;
    }
    key[vertex] = 0;
    parent[vertex] = -1;

    for(int count = 0; count < vertices; count++)
    {
        int u = minKey(vertices, key, curr_mst, path, &j);
        curr_mst[u] = 1;
        for(int v = 0; v < vertices; v++)
        {
            if(adj_matrix[u][v] && curr_mst[v] == 0 && adj_matrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj_matrix[u][v];
            }
        }
    }
    if(flag == 1)
    {
        printSequence(vertices, parent, adj_matrix, path, j);
    }
    else
    {
        weightOfMst(vertices, parent, adj_matrix);
    }
}

int main()
{
    int vertices;
    scanf("%d", &vertices);
    int adj_matrix[vertices][vertices];
    int flag = 0;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    while(1)
    {
        char ch;
        int vertex;
        scanf("%c", &ch);
        if(ch == 'b')
        {
            primMst(vertices, adj_matrix, 0, 0);
        }
        else if(ch == 's')
        {
            char c = getchar();
            scanf("%d", &vertex);
            primMst(vertices, adj_matrix, vertex, 1);
        }
        else if(ch == 'x')
        {
            break;
        }
    }
    return 0;
}