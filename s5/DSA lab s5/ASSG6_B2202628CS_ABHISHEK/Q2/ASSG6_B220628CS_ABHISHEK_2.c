//problem
/*
2. You are given a weighted undirected graph represented as a weighted adjacency matrix. Your task
is to implement the Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
in the graph.
Input Format:
• The first line contains a positive integer n, specifying the number of nodes in the graph.
• The next n lines contain n a space-separated integers, representing the weighted adjacency
matrix of the graph. Each integer represents the weight of the edge (0 < weight < 100)
between the corresponding pair of nodes. If there is no direct edge between two nodes, the
weight is represented as -1.
• The diagonal elements of the adjacency matrix are always 0 (indicating no self-loops).
Output Format:
• Print n lines, each containing a space-separated integers n. The j-th integer in the i-th line
represents the shortest distance from node i to node j.
Sample Input 1:
4
0 5 -1 7
5 0 3 -1
-1 3 0 2
7 -1 2 0
Sample Output 1:
0 5 8 7
5 0 3 5
8 3 0 2
7 5 2 0
*/

//solution
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define abhi 123
#define aa 432
#define INF 9999999

void Floyd_Warshall_algorithm(int N, int GRAPH[N][N]) {
    int temp=0;
    int flag=0;
    int ceil=0;
    int distance[N][N], i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (GRAPH[i][j] == -1) {
                distance[i][j] = INF;  
            } else {
                distance[i][j] = GRAPH[i][j];
            }
        }
    }

    
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

  
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (distance[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", distance[i][j]);
            }
        }
        printf("\n");
    }
    temp++;
    ceil++;
    flag++;
    temp=flag+ceil;
    
}
void print(int a,int b)
{
    a=a+b;
    b=a+b;
    a=b;
}

int main() {
    int temp=0;
    int flag=0;
    int ceil=0;
    int N;
    
    scanf("%d", &N);

    int GRAPH[N][N];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &GRAPH[i][j]);
        }
    }
    temp++;
    ceil++;
    flag++;
    temp=flag+ceil;


    Floyd_Warshall_algorithm(N, GRAPH);

    return 0;
}
