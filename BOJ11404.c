#include <stdio.h>
#include <stdlib.h>
#define INF 999999999

void init_graph(int graph[][105], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (i==j)
                graph[i][j]=0;
            else 
                graph[i][j]=INF;
        }
    }
}

void PrintDist(int dist[][105], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (i==j || dist[i][j]==INF)
                printf("%d ", 0);
            else 
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Floid(int graph[][105], int n, int dist[][105] )
{
    //distance 배열 초기화 
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    //모든 정점을 한 번에 한 개씩 중간 정점으로 사용용
    for(int k=1; k<=n; k++)
    {
        //모든 정점을 시작점으로 사용
        for(int i=1; i<=n; i++)
        {
            //모든 정점을 목적지로 사용 
            for(int j=1; j<=n; j++)
            {
                if (dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    PrintDist(dist,n);

}

int main(void)
{
    int n=0; char ch=' ';
    int m=0;
    int a=0; int b=0; int c=0;
    int graph[105][105]={0};
    int dist[105][105]={0};

    scanf("%d%c", &n, &ch);
    scanf("%d%c", &m, &ch);

    init_graph(graph,n);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);

        if (graph[a][b]>c)
        {
            graph[a][b]=c;
        }
    }

    Floid(graph,n,dist);

    return 0;
}