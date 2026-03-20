//problem
/*
2. You are given an adjacency matrix representation of an undirected simple graph G with n vertices
and m edges, where n ≥1 and m ≥0. An undirected simple graph does not contain self-loops or
parallel edges between any two vertices.
Implement a menu-driven program that performs the following operations using Breadth-First
Search (BFS) as a subroutine:
Operations
(a) isBipartite(G): Checks whether the given graph G is bipartite or not. A bipartite graph is a
graph whose vertices can be partitioned into two disjoint sets so that every edge connects a
vertex in one set to a vertex in the other. The function should print 1 if the graph is bipartite,
and−1 if it is not.
(b) hasCycle(G): Checks if the graph G contains a cycle. A cycle is a path that starts and ends
at the same vertex, with no repeated edges. The function should print 1 if a cycle is present,
and−1 if no cycle is present in G.
(c) isTree(G): Checks if the given graph G is a valid tree. A valid tree is a connected acyclic
graph. The function should print 1 if the graph is a tree, and−1 if it is not. Note that a valid
tree must have exactly n−1 edges.
Notes
i. A single vertex with no edges is a bipartite graph and a tree, but it contains no cycles.
ii. A disconnected graph cannot be a tree, but it may still be bipartite or contain cycles.
Input Format
• The first line contains an integer n (number of vertices).
• The next n lines each contain a space separated n integers representing the adjacency matrix
of the graph. A value of 1 at position matrix[i][j] means there is an edge between vertex i and
vertex j, and a value of 0 means there is no edge. The matrix is symmetric for undirected
graph.
• Each subsequent line contains a character from {’a’, ’b’, ’c’, ’x’}.
• Character ’a’ calls the function isBipartite(G).
• Character ’b’ calls the function hasCycle(G).
• Character ’c’ calls the function isTree(G).
• Character ’x’ terminates the program.
Output Format
• The output of each command should be printed on a separate line. However, no output is
printed for ’x’.
• For option ’a’: Print 1 if the graph is bipartite, and−1 if it is not.
• For option ’b’: Print 1 if the graph contains a cycle, and−1 if G does not contain a cycle.
• For option ’c’: Print 1 if the graph is a tree, and−1 if it is not.
Sample test case 1
Input
4
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
a
b
c
x
Output
-1
1
-1
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 100

typedef struct {
    int n; 
    int adjacency_matrix[V][V];
} Graph;




void initGraph(Graph *g, int n) {
    g->n = n;
}


bool bfs_check_bipartite(Graph *g, int start, int *color) {
    int queue[V];
    int front = 0, rear = 0;

    
    queue[rear++] = start;
    color[start] = 0;

    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < g->n; v++) {
            if (g->adjacency_matrix[u][v]) {
                if (color[v] == -1) { 
                    color[v] = 1 - color[u]; 
                    queue[rear++] = v; 
                } else if (color[v] == color[u]) {
                    return false; 
                }
            }
        }
    }
    return true; 
}
bool isBipartite(Graph *g) {
    int color[V];
    for (int i = 0; i < g->n; i++) {
        color[i] = -1; 
    }

    for (int i = 0; i < g->n; i++) {
        if (color[i] == -1) { 
            if (!bfs_check_bipartite(g, i, color)) {
                return false; 
            }
        }
    }
    return true; 
}



bool bfs_check_cycle(Graph *g, int start, bool *visited, int parent) {
    int queue[V];
    int front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < g->n; v++) {
            if (g->adjacency_matrix[u][v]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue[rear++] = v;
                } else if (v != parent) {
                    return true; 
                }
            }
        }
    }
    return false; 
}
bool hasCycle(Graph *g) {
    bool visited[V] = {false};
    
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            if (bfs_check_cycle(g, i, visited, -1)) {
                return true; 
            }
        }
    }
    return false; 
}

int countEdges(Graph *g) {
    int edgeCount = 0;
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adjacency_matrix[i][j]) {
                edgeCount++;
            }
        }
    }
    return edgeCount;
}
bool isTree(Graph *g) {
    if (g->n == 1) return true; 

  
    if (g->n - 1 != countEdges(g)) {
        return false; 
    }

    bool visited[V] = {false};
    if (hasCycle(g)) {
        return false; 
    }

    bfs_check_cycle(g, 0, visited, -1); 
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    Graph g;
    int n;

    scanf("%d", &n);
    initGraph(&g, n);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g.adjacency_matrix[i][j]);
        }
    }

    char command;
    while (scanf(" %c", &command) == 1) {
        if (command == 'a') {
            printf("%d\n", isBipartite(&g) ? 1 : -1);
        } else if (command == 'b') {
            printf("%d\n", hasCycle(&g) ? 1 : -1);
        } else if (command == 'c') {
            printf("%d\n", isTree(&g) ? 1 : -1);
        } else if (command == 'x') {
            break;
        }
    }

    return 0;
}
