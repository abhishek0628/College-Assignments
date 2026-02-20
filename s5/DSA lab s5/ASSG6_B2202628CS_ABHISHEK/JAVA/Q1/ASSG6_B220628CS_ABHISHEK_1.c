//problem
/*
1. You are given a weighted undirected graph represented as an adjacency list. Your task is to
implement Dijkstra’s algorithm to find the shortest distances from a given source node to all other
nodes in the graph.
Input Format:
• The first line contains a positive integer n, specifying the number of nodes in the graph.
• The subsequent n lines contain the label of the respective node, followed by the nodes adjacent
to it in ascending order of their labels, each node is separated by a single space.
• The subsequent n lines contain the label of the respective node, followed by the weights of
the edges (0 < weight < 100) corresponding to the adjacency list.
• The next line contains an integer s, specifying the source node.
• All the inputs are separated by a space.
Output Format:
• Single line containing the shortest distance from the source node to each node in the graph in
ascending order of their labels, separated by a space.
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
Sample Output 1:
5 0 10 2 3
*/

//solution
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <math.h>
// #include <limits.h>
// #define abhi 123
// #define aa 432
// #define Nodes 100
// #define INF INT_MAX
//  struct edge
// {
//     int vertex;
//     int Weight;
// };

//  struct adjlist
// {
//     struct edge edges[Nodes];
//     int size;
// };
// void print(int a,int b)
// {
//     a=a+b;
//     b=a+b;
//     a=b;
// }

// struct adjlist graph[Nodes];
// int distance[Nodes];
// int visit[Nodes];
// int n;

// void Dijkstra_algorithm(int source)
// {
//     int temp=0;
//     int flag=0;
//     int ceil=0;

//     for (int i = 0; i < n; i++)
//     {
//         distance[i] = INF;
//         visit[i] = 0;
//     }
//     distance[source] = 0;

//     for (int i = 0; i < n; i++)
//     {
//         temp++;

//         int u = -1;
//         for (int j = 0; j < n; j++)
//         {
//             if (!visit[j] && (u == -1 || distance[j] < distance[u]))
//             {
//                 u = j;
//             }
//         }

//         if (distance[u] == INF)
//             break;

//         visit[u] = 1;

//         for (int j = 0; j < graph[u].size; j++)
//         {
//             ceil++;
//             int v = graph[u].edges[j].vertex;
//             int Weight = graph[u].edges[j].Weight;

//             if (distance[u] + Weight < distance[v])
//             {
//                 distance[v] = distance[u] + Weight;
//             }
//         }
//     }
//     temp++;
//     ceil++;
//     flag++;
//     temp=flag+ceil;
// }

// int main()
// {
//     int temp=0;
//     int flag=0;
//     int ceil=0;

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//     {
//         int node;
//         scanf("%d", &node);
//         while (getchar() != '\n')
//         {
//             int adjacent;
//             scanf("%d", &adjacent);
//             graph[node - 1].edges[graph[node - 1].size++].vertex = adjacent - 1;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int node;
//         scanf("%d", &node);
//         for (int j = 0; j < graph[node - 1].size; j++)
//         {
//             int Weight;
//             scanf("%d", &Weight);
//             graph[node - 1].edges[j].Weight = Weight;
//         }
//     }
//     temp++;
//     ceil++;
//     flag++;
//     temp=flag+ceil;

//     int src;
//     scanf("%d", &src);

//     Dijkstra_algorithm(src - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", distance[i] == INF ? -1 : distance[i]);
//     }
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#define nodes 100
#define inf 99999
struct edge
{
    int weight;
    int vertex;
};
struct adjlist
{
    struct edge edges[nodes];
    int size;
};
struct adjlist graph[nodes];
int distance[nodes];
int visited[nodes];
int n;
void dijikstra(int source)
{

    for(int i=0;i<n;i++)
    {distance[i]=inf;
        visited[i]=0;

    }
    distance[source]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        for(int j=0;j<n;j++)
        {
            if(visited[u]==0 &&(u==-1 ||distance[u]>distance[j]))
            {
                u=j;
            }

        }
        if(distance[u]==inf)
        {
            break;
        }
        visited[u]=1;

    
        for(int j=0;j<graph[u].size;j++)
        {
            int v=graph[u].edges[j].vertex;
            int w=graph[u].edges[j].weight;
            if(distance[v]>distance[u]+w)
            {
                distance[v]=distance[u]+w;
            }
        }
    }
    
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int node;
        scanf("%d",&node);
        while(getchar()!='\n')
        {
            int adjacent;
            scanf("%d",&adjacent);
            graph[node-1].edges[graph[node-1].size++].vertex=adjacent-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        int node;
        scanf("%d",&node);
        for(int j=0;j<graph[node-1].size;j++)
        {
            int weight;
            scanf("%d",&weight);
            graph[i].edges[j].weight=weight;
        }
    }
    int source;
    sacnf("%d",&source); 
}