#include<stdio.h>
#include<stdlib.h>
#define nodes 100
#define inf 9999
struct edge
{
    int vertex;
    int weight;
};
struct adjlist
{
    struct edge edges[nodes];
    int size;
};
struct adjlist graph[nodes];
int visits[nodes];
int distance[nodes];
int n;
void dijikstra(int source)
{
    for(int i=0;i<n;i++)
    {
        distance[i]=inf;
        visits[i]=0;
    }
    distance[source]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        for(int j=0;j<n;j++)
        {
            if(!visits[j]&&(u==-1 || distance[j]<distance[u]))
            {
                u=j;
            }

        }
            if(distance[u]==inf)
            {
                break;
            }
            visits[u]=1;
        for(int j=0;j<graph[u].size;j++)
        {
            int v=graph[u].edges[j].vertex;
            int weight=graph[u].edges[j].weight;
            if(distance[u]+weight<distance[v])
            {
                distance[v]=distance[u]+weight;
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
        int node ;
        scanf("%d",&node);
        for(int j=0;j<graph[node-1].size;j++)
        {
            int weight;
            scanf("%d",&weight);
            graph[i].edges[j].weight=weight;
        }


    }
    int source;
    scanf("%d",&source);
    dijikstra(source-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",distance[i]);
    }
    return 0;

}