#include <stdio.h>
#include <stdlib.h>
#define INF 999999

void init_graph(int graph[][500], int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if (i==j)
                continue;
            graph[i][j]=INF;
        }
    }
}

void PrintFloyd(int dist[][500], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (dist[i][j]==INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void FloyWarshall(int graph[][500], int dist[][500],int n)
{

    //입력 그래프를 바탕으로 dist 배열 초기화 
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    //모든 정점을 한번에 한 개씩 중간 정점으로 사용
    for(int k=1; k<=n; k++)
    {
        //모든 정점을 시작점으로 사용 
        for(int i=1; i<=n; i++)
        {
            //모든 정점을 목적지로 사용 
            for(int j=1; j<=n; j++)
            {
                // i에서 j로 가는 기존 거리와 i에서 k를 거쳐 j로 가는 거리를 비교하여 더 작은 값을 선택
                if (dist[i][k]==0)
                {
                    if (dist[i][j]==1 && dist[j][k]==1)
                    {
                        dist[i][k]=1;
                    }

                    else if (dist[i][j]==-1 && dist[j][k]==-1)
                    {
                        dist[i][k]=-1;
                    }
                }

            }
        }
    }
}

void Solution(int dist[][500], int n)
{
    int s=0; char ch=' ';
    int a=0; int b=0;

    scanf("%d%c", &s, &ch);

    for(int i=0; i<s; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);

        printf("%d\n", dist[a][b]);
    }
}

int main(void)
{
    int n=0; int k=0; char ch=' ';
    int graph[500][500]={0};
    int dist[500][500]={0};
    int a=0; int b=0; 

    scanf("%d %d%c", &n, &k, &ch);

    //init_graph(graph,n);
    // 0을 init 값
    for(int i=0; i<k; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        graph[a][b]=-1; // 먼저 일어난 거 적게 할당 
        graph[b][a]=1; //나중에 일어난 거 
    }

    FloyWarshall(graph,dist,n);
    //PrintFloyd(dist,n);
    Solution(dist,n);

    return 0;
}