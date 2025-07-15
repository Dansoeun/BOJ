#include <stdio.h>
#include <stdlib.h>
#define INF 9999999
/*
1. 1번 노드에서 출발하는 데이크스트라 
2. 방문하면 부모가 1과 같은지 확인 (UnionFind 수행)
*/

typedef struct 
{
    int start;
    int end;
}Vertex;

void init_graph(int graph[][1005], int n)
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

void init_parent(int parent[], int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
}

int GetParent(int parent[], int x)
{
    if (parent[x]==x)
        return x;
    
    return parent[x]=GetParent(parent,parent[x]);
}

int UnionParent(int parent[], int a,int b)
{
    if (a<b)
    {
        parent[b]=a;
        return a;
    }

    else 
    {
        parent[a]=b;
        return b;
    }

}

int SearchVertex(int distance[], int visited[], int n)
{
    int min=INF;
    int result=-1;

    for(int i=1; i<=n; i++)
    {
        if (distance[i]<min && visited[i]==0)
        {
            min=distance[i];
            result=i;
        }
    }

    return result;
}


void Dijkstra(int graph[][1005], int parent[], int n)
{
    int distance[1005]={0};
    int visited[1005]={0};
    Vertex list[1005];
    int idx=0;
    int cur=1;
    int prev=1;
    visited[cur]=1;

    for(int i=1; i<=n; i++)
    {
        distance[i]=graph[cur][i];

        if (graph[cur][i]!=INF)
        {
            parent[i]=1;
        }
    }

    for(int i=0; i<n-1; i++)
    {
        cur=SearchVertex(distance,visited,n);
        visited[cur]=1;
        list[idx].start=cur; 
        list[idx].end=parent[cur];
        idx+=1;

        for(int j=1; j<=n; j++)
        {
            if (distance[j] > graph[cur][j]+distance[cur] && visited[j]==0)
            {
                distance[j]=graph[cur][j]+distance[cur];
                parent[j]=cur;
            }
        }
        prev=cur;
    }

    printf("%d\n",idx);

    for(int i=0; i<idx; i++)
    {
        printf("%d %d\n",list[i].start, list[i].end);
    }
}

int main(void)
{
    int n=0; int m=0; char ch=' ';
    int graph[1005][1005]={0};
    int parent[1005]={0};
    int a=0; int b=0; int c=0; 

    scanf("%d %d%c", &n, &m, &ch);

    init_graph(graph,n);
    init_parent(parent,n);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);

        if (graph[a][b]>c)
        {
            graph[a][b]=c;
            graph[b][a]=c;
        }
        //graph[a][b]=c;
        //graph[b][a]=c;
    }

    Dijkstra(graph,parent,n);
}