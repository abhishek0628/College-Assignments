#include<stdio.h>
#include<stdlib.h>
#define inf 9999
#define N 100
void floyd_warshall(int n,int graph[N][N])
{
    int distance[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            distance[i][j]=graph[i][j];

        }
    }
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(distance[i][k]+distance[k][j]<distance[i][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",distance[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int graph[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    floyd_warshall(n,graph);
    return 0;

    
}