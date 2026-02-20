//problem
/*
1. You are given an adjacency matrix representation of an undirected simple graph G with n vertices
and m edges, where n ≥1 and m ≥0. An undirected simple graph does not contain self-loops or
parallel edges between any two vertices.
Implement a menu-driven program that performs the following operations using Depth-First Search
(DFS) as a subroutine:
Operations
(a) noOfConnectedComponents(G): Calculates and print the total number of connected compon-
ents in the graph G. A connected component is a maximal subgraph where any two vertices
are connected by a simple path.
(b) sizeOfComponents(G): Prints the sizes of all connected components in the graph G, sorted
in non-decreasing order of their sizes. The size of a component is the number of vertices it
contains.
(c) noOfBridges(G): Prints the total number of bridges in the graph G. A bridge (or cut-edge) is
an edge whose removal increases the number of connected components in the graph. If there
are no bridges in the graph, the function should print 0.
(d) noOfArticulationPoints(G): Prints the total number of articulation points in the graph G. An
articulation point (or cut-vertex) is a vertex whose removal increases the number of connected
components. If there are no articulation points, print 0.
Notes
i. A graph with one vertex will always have one connected component and no bridges or
articulation points.
ii. An empty graph with n vertices and 0 edges will result in n connected components.
iii. A fully connected graph has 1 component and no bridges or articulation points.
Input Format
• The first line contains an integer n (number of vertices, n ≥1).
• The next n lines each contain a space separated n integers representing the adjacency matrix
of the graph. The vertices are numbered from 1 to n. A value of 1 at position matrix[i][j]
means there is an edge between vertex i and vertex j, and a value of 0 means there is no edge.
Note that the adjacency matrix is symmetric for undirected simple graph.
• Each subsequent line contains a character from {’a’, ’b’, ’c’, ’d’, ’x’}.
• Character ’a’ calls the function noOfConnectedComponents(G).
• Character ’b’ calls the function sizeOfComponents(G).
• Character ’c’ calls the function noOfBridges(G).
• Character ’d’ calls the function noOfArticulationPoints(G).
• Character ’x’ terminates the program.
Output Format
• The output of each command should be printed on a separate line. However, no output is
printed for ’x’.
• For option ’a’: Print the total number of connected components in the graph.
• For option ’b’: Print the sizes of all connected components in non decreasing order separated
by a space.
• For option ’c’: Print the total number of bridges in the graph. Print 0 if no bridges are
present.
• For option ’d’: Print the total number of articulation points in the graph. Print 0 if no
articulation points are present.
Sample test case 1
Input
5
0 1 0 0 0
1 0 0 0 0
0 0 0 1 0
0 0 1 0 1
0 0 0 1 0
a
b
c
d
x
Output
2
2 3
3
1
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define abhi 20
#define aa 23

#define V 100

typedef struct
{
    int n;
    int matrix[V][V];
    bool visited[V];
    int time;
    int disc[V];
    int low[V];
    int parent[V];
    int bridges_count;
    int articulation_count;
    bool is_articulation[V];
} Graph;


void initGraph(Graph *g, int n)
{
    g->n = n;
    g->time = 0;
    g->bridges_count = 0;
    g->articulation_count = 0;

    for (int i = 0; i < n; i++)
    {
        g->visited[i] = false;
        g->parent[i] = -1;
        g->is_articulation[i] = false;
    }
}

void dfs_connected_components(Graph *g, int v)
{
    g->visited[v] = true;
    for (int i = 0; i < g->n; i++)
    {
        if (g->matrix[v][i] && !g->visited[i])
        {
            dfs_connected_components(g, i);
        }
    }
}

int noOfConnectedComponents(Graph *g)
{
    int count = 0;
    for (int i = 0; i < g->n; i++)
    {
        if (!g->visited[i])
        {
            dfs_connected_components(g, i);
            count++;
        }
    }
    return count;
}

void dfs_size(Graph *g, int v, int *size)
{
    g->visited[v] = true;
    (*size)++;
    for (int i = 0; i < g->n; i++)
    {
        if (g->matrix[v][i] && !g->visited[i])
        {
            dfs_size(g, i, size);
        }
    }
}

void sizeOfComponents(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->visited[i] = false;
    }
    int sizes[V];
    int n = 0;

    for (int i = 0; i < g->n; i++)
    {
        if (!g->visited[i])
        {
            int size = 0;
            dfs_size(g, i, &size);
            sizes[n++] = size;
        }
    }

    for (int j = 1; j < n; j++)
    {
        int key = sizes[j];
        int i = j - 1;
        while (i >= 0 && sizes[i] < key)
        {
            sizes[i + 1] = sizes[i];
            i--;
        }
        sizes[i + 1] = key;
    }

    for (int i = n-1; i >= 0; i--)
    {
        printf("%d ", sizes[i]);
    }
    printf("\n");
}

void dfs_bridge_articulation(Graph *g, int u)
{
    g->visited[u] = true;
    g->disc[u] = g->low[u] = ++g->time;

    for (int v = 0; v < g->n; v++)
    {
        if (g->matrix[u][v])
        {
            if (!g->visited[v])
            {
                g->parent[v] = u;
                dfs_bridge_articulation(g, v);

                g->low[u] = (g->low[u] < g->low[v]) ? g->low[u] : g->low[v];

                if (g->low[v] > g->disc[u])
                {
                    g->bridges_count++;
                }

                if (g->parent[u] != -1 && g->low[v] >= g->disc[u])
                {
                    g->is_articulation[u] = true;
                }
            }
            else if (v != g->parent[u])
            {
                g->low[u] = (g->low[u] < g->disc[v]) ? g->low[u] : g->low[v];
            }
        }
    }
}

int noOfBridges(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->visited[i] = false;
        g->parent[i] = -1;
    }
    g->bridges_count = 0;

    for (int i = 0; i < g->n; i++)
    {
        if (!g->visited[i])
        {
            dfs_bridge_articulation(g, i);
        }
    }

    return g->bridges_count;
}

int noOfArticulationPoints(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->visited[i] = false;
        g->parent[i] = -1;
        g->is_articulation[i] = false;
    }
    g->bridges_count = 0;

    for (int i = 0; i < g->n; i++)
    {
        if (!g->visited[i])
        {
            dfs_bridge_articulation(g, i);
        }
    }

    for (int i = 0; i < g->n; i++)
    {
        if (g->is_articulation[i])
        {
            g->articulation_count++;
        }
    }

    return g->articulation_count;
}
int main()
{
    Graph g;
    int n;

    scanf("%d", &n);
    initGraph(&g, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g.matrix[i][j]);
        }
    }

    char command;
    while (scanf(" %c", &command) == 1)
    {
        if (command == 'a')
        {
            printf("%d\n", noOfConnectedComponents(&g));
        }
        else if (command == 'b')
        {
            sizeOfComponents(&g);
        }
        else if (command == 'c')
        {
            printf("%d\n", noOfBridges(&g));
        }
        else if (command == 'd')
        {
            printf("%d\n", noOfArticulationPoints(&g));
        }
        else if (command == 'x')
        {
            break;
        }
    }

    return 0;
}
