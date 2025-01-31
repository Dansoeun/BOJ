#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

/*
1. 모든 start (vertex)에 대해 Dijkstra 수행
2. vertex 선택, visited 처리 되고 나면 ans 갱신 
3. 단, 이전 vertex 기억하기
*/

void init_graph(int graph[][205], int n)
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

int SearchVertex(int dist[], int visited[], int n)
{
    int min=INF;
    int result=-1;

    for(int i=1; i<=n; i++)
    {
        if (visited[i]==0 && min > dist[i])
        {
            result=i;
            min=dist[i];
        }
    }

    return result;
}

int GetParent(int parent[], int x)
{
    if (parent[x]==x)
        return x;
    
    return parent[x]=GetParent(parent,parent[x]);
}

void Dijkstra(int graph[][205], int n, int start, int ans[][205])
{
    int distance[205]={0};
    int visited[205]={0};
    int flag[205]={0};
    int prev=start;
    int vertex=start;

    visited[start]=1;

    for(int i=1; i<=n; i++)
    {
        distance[i]=graph[start][i];
    }

    for(int i=0; i<n-1; i++)
    {
        vertex=SearchVertex(distance,visited,n);
        visited[vertex]=1; 

        if (flag[vertex]==0)
        {
            ans[start][vertex]=vertex;
            flag[vertex]=1;
        }

        for(int j=1; j<=n; j++)
        {
            if (visited[j]==0 && distance[vertex]+graph[vertex][j]<distance[j])
            {
                distance[j]=distance[vertex]+graph[vertex][j];
                //ans[start][j]=vertex;
                ans[start][j]=ans[start][vertex];
                flag[j]=1;
            }
        }

    }
}

void Print(int ans[][205], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (i==j)
                printf("%c ", '-');
            else 
                printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n=0; int m=0; char ch=' ';
    int a=0; int b=0; int c=0; 
    int graph[205][205]={0};
    int ans[205][205]={0};

    scanf("%d %d%c", &n, &m, &ch);
    
    init_graph(graph,n);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);
        graph[a][b]=c;
        graph[b][a]=c;
    }

    for(int i=1; i<=n; i++)
    {
        Dijkstra(graph,n,i,ans);
    }

    Print(ans,n);
    return 0;
}