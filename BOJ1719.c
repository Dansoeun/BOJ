#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

/*
1. 플로이드-워셜 실행
2. 거리값 갱신할 때, 노드 번호도 따로 갱신 
*/

void init_graph(int graph[][205], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (graph[i][j]==0)
                continue;
            else 
                graph[i][j]=INF;
        }
    }
}

void Print(int node[][205], int graph[][205], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (i==j)
                printf("%c ", '-');
            else 
                printf("%d ", node[i][j]);
        }
        printf("\n");
    }
}

int SearchVertex(int dist[] , int visited[], int n)
{
    int result=-1;
    int min=INF;

    for(int i=1; i<=n; i++)
    {
        if (visited[i]==0 && min > dist[i])
        {
            min=dist[i];
            result=i;
        }
    }

    return result;
}

void Dijkstra(int graph[][205], int n, int start , int node[][205])
{
    int dist[205]={0};
    int visited[205]={0};
    int vertex=0;

    visited[start]=1;

    for(int i=1; i<=n; i++)
    {
        dist[i]=graph[start][i];
    }

    for(int i=0; i<n-1; i++)
    {
        vertex=SearchVertex(dist,visited,n);
        visited[vertex]=1;
        node[start][vertex]=vertex;

        for(int j=1; j<=n; j++)
        {
            if (graph[vertex][j]+dist[vertex]<dist[j])
            {
                dist[j]=dist[vertex]+graph[vertex][j];
                node[start][j]=vertex;
            }
        }
    }
}

void Init_dist(int dist[205][205],int graph[][205], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
}

void Floid(int graph[][205], int n)
{
    int node[205][205]={0};
    int dist[205][205]={0};

    for(int k=1; k<=n; k++)
    {
        Init_dist(dist,graph,n);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if (dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    node[i][j]=k;
                }
            }
        }
    }

    Print(node,graph,n);

}

int main(void)
{
    int n=0; int m=0; char ch=' ';
    int graph[205][205]={0};
    int a=0; int b=0; int c=0; 

    scanf("%d %d%c", &n, &m, &ch);

    init_graph(graph,n);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);
        graph[a][b]=c;
        graph[b][a]=c;
    }

    Floid(graph,n);
    return 0;
}