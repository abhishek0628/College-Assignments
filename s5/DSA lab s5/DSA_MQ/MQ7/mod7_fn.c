
#include <stdio.h>
#define MAX 1000
#define INF 9999

int n, budget, source;
int cost[MAX][MAX];
int visited[MAX];
int minCost;

void prim() {
    int key[MAX], parent[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[source] = 0;
    minCost = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        minCost += key[u];

        for (int v = 0; v < n; v++) {
            if (cost[u][v] != INF && !visited[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &budget);
    scanf("%d", &source);
    source--;  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    char command;
    while (scanf(" %c", &command)) {
        if (command == 'c') {
            prim();
            printf("%d %s\n", minCost, (minCost <= budget) ? "no" : "yes");
        } else if (command == 'e') {
            break;
        }
    }

    return 0;
}
