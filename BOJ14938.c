#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

/*
1. 플로이드-워셜 진행 
2. 거리가 m보다 작으면 합하기 
*/

int static compare(const void *a, const void *b)
{
    int *temp_a=(int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return 1;
    else if (*temp_a < *temp_b)
        return -1;
    else 
        return 0;
}

void init_graph(int graph[][105], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (i==j)
                continue;
            else 
                graph[i][j]=INF;
        }
    }
}

int SearchVertex(int distance[], int visited[], int n)
{
    int min=INF;
    int result=-1;

    for(int i=1; i<=n; i++)
    {
        if (visited[i]==0 && distance[i]<min)
        {
            min=distance[i];
            result=i;
        }
    }

    return result;
}

/*
void Dijkstra(int graph[][105], int item[], int ans[], int n, int m, int start)
{
    int visited[105]={0};
    int distance[105]={0};
    int vertex=0;
    int hap=0;
    int dist=0;

    for(int i=1; i<=n; i++)
    {
        distance[i]=graph[start][i];
    }

    visited[start]=1;
    hap+=item[start];

    for(int i=0; i<n-1; i++)
    {
        vertex=SearchVertex(distance,visited,n);
        visited[start]=1;
        dist+=distance[vertex];

        if (dist>m)
            break;
        
        hap+=item[vertex];
        for(int j=1; j<=n; j++)
        {
            if (visited[j]==0 && graph[vertex][j]+distance[vertex]<distance[j])
            {
                distance[j]=graph[vertex][j]+distance[vertex];
            }
        }
    }

    ans[start]=hap;
}
*/

void Floid(int graph[][105], int item[], int ans[], int n, int m)
{
    int dist[105][105]={0};
    int hap=0;
    int answer=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if (dist[i][k]+dist[k][j] < dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        hap=0;
        hap+=item[i];

        for(int j=1; j<=n; j++)
        {
            if (dist[i][j]<=m && i!=j)
            {
                hap+=item[j];
            }
        }
        ans[i]=hap;

        if (hap>answer)
        {
            answer=hap;
        }
    }

    printf("%d\n",answer);


}

int main(void)
{
    int n=0; int m=0; int r=0; char ch=' ';
    int item[105]={0};
    int graph[105][105]={0};
    int ans[105]={0};
    int a=0; int b=0; int c=0;

    scanf("%d %d %d%c", &n, &m, &r, &ch);
    init_graph(graph,n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &item[i]);
    }
    getchar();

    for(int i=0; i<r; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);
        graph[a][b]=c;
        graph[b][a]=c;
    }

    Floid(graph,item,ans,n,m);

    return 0;

}