//problem
/*
3. You are given a directed simple graph G with n vertices and m edges. A graph is represented by
an adjacency list, where n ≥1 and m ≥0.
Implement a menu-driven program that performs the following operations using Depth-First Search
(DFS) as a sub-routine:
Operations
(a) isDAG(G): Checks whether a topological sort is possible for the given directed acyclic graph G.
A topological sort is a linear ordering of the vertices in a Directed Acyclic Graph (DAG) such
that for every directed edge e1 →e2, vertex e1 appears before e2 in the ordering. Topological
sorting is possible only if the graph is a Directed Acyclic Graph (DAG). The function should
print 1 if topological sort is possible, and−1 if it is not.
(b) countStronglyConnectedComponents(G): Counts the number of strongly connected compon-
ents in the graph. A strongly connected component is a maximal subgraph in which every
vertex is reachable from every other vertex. The function should print the number of strongly
connected components in the graph.
Notes
i. An empty graph with n vertices and 0 edges will results n number of strongly connected
components.
ii. For a single vertex with no edges, topological order is possible and the graph has one
strongly connected component.
Input Format
• The first line contains two integers n (number of vertices, n ≥1) and m (number of edges,
m ≥0).
• The subsequent n lines contain the label of the respective node, followed by a space-separated
nodes adjacent to it in ascending order of their labels.
• Each subsequent line contains a character from {’a’, ’b’, ’x’}.
• Character ’a’ calls the function isDAG(G).
• Character ’b’ calls the function countStronglyConnectedComponents(G).
• Character ’x’ terminates the program.
Output Format
• The output of each command should be printed on a separate line. However, no output is
printed for ’x’.
• For option ’a’: Print 1 if topological sort is possible, and−1 if if it is not.
• For option ’b’: Print the total number of strongly connected components in the graph.
Sample test case 1
Input
6 7
1 2 3
2 4
3 4 5
4 6
5 6
6
a
b
x
Output
1
6
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define V 100  

typedef struct {
    int Matrix[V][V];   
    int revMatrix[V][V];   
    int visited[V];        
    int sortedNodes[V];    
    int v;                 
    int e;                
    int sortIndex;         
    int sccCount;         
} Graph;


void DFS_Sort(Graph *g, int vertex) {
    g->visited[vertex] = 1;
    for (int i = 0; i < g->v; i++) {
        if (g->Matrix[vertex][i] && !g->visited[i]) {
            DFS_Sort(g, i);
        }
    }
    g->sortedNodes[g->sortIndex--] = vertex;
}

void DFS_Reverse(Graph *g, int vertex) {
    g->visited[vertex] = 1;
    for (int i = 0; i < g->v; i++) {
        if (g->revMatrix[vertex][i] && !g->visited[i]) {
            DFS_Reverse(g, i);
        }
    }
}

int CHECK_DAG(Graph *g) {
    memset(g->visited, 0, sizeof(g->visited));
    g->sortIndex = g->v - 1;
    for (int i = 0; i < g->v; i++) {
        if (!g->visited[i]) {
            DFS_Sort(g, i);
        }
    }
    memset(g->visited, 0, sizeof(g->visited));
    for (int i = 0; i < g->v; i++) {
        int vertex = g->sortedNodes[i];
        for (int j = 0; j < g->v; j++) {
            if (g->Matrix[vertex][j] && g->visited[j]) {
                return -1; 
            }
        }
        g->visited[vertex] = 1;
    }
    return 1;  
}
int COUNT_SCCs(Graph *g) {
    memset(g->visited, 0, sizeof(g->visited));
    g->sortIndex = g->v - 1;
    for (int i = 0; i < g->v; i++) {
        if (!g->visited[i]) {
            DFS_Sort(g, i);
        }
    }
    
    for (int i = 0; i < g->v; i++) {
        for (int j = 0; j < g->v; j++) {
            g->revMatrix[i][j] = g->Matrix[j][i];
        }
    }

    memset(g->visited, 0, sizeof(g->visited));
    g->sccCount = 0;
    for (int i = 0; i < g->v; i++) {
        int vertex = g->sortedNodes[i];
        if (!g->visited[vertex]) {
            g->sccCount++;
            DFS_Reverse(g, vertex);
        }
    }
    return g->sccCount;
}

int main() {
    Graph g;  
    scanf("%d %d", &g.v, &g.e);


    memset(g.Matrix, 0, sizeof(g.Matrix));

   
    for (int i = 0; i < g.v; i++) {
        int adjNode;
        while (scanf("%d", &adjNode) && adjNode != 0) {
            g.Matrix[i][adjNode - 1] = 1;
        }
    }

    char command;
    while (1) {
        scanf(" %c", &command);
        switch (command) {
            case 'a':
                printf("%d\n", CHECK_DAG(&g));
                break;
            case 'b':
                printf("%d\n", COUNT_SCCs(&g));
                break;
            case 'x':
                return 0;
        }
    }
    return 0;
}
