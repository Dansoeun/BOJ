#include <stdio.h>
#include <stdlib.h>

static int visited[100005]={0};
static int cnt=1;

void PrintGraph(int graph[][100001], int idx[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<idx[i]; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void TestPrint(int graph[][100001], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

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

int CountElement(int graph[], int n)
{
    int cnt=0;

    for(int i=0; i<n; i++)
    {
        if (graph[i]!=0)
            cnt+=1;
        else 
            break;
    }

    return cnt;
}

void DFS(int graph[][100001], int n, int start, int order[])
{
    visited[start]=1;
    order[start]=cnt;

    for(int i=0; i<n; i++)
    {
        if (graph[start][i]==0)
            return;
        
        if (visited[graph[start][i]]==0)
        {
            cnt+=1;
            DFS(graph,n,graph[start][i],order);
        }
    }

}

void Solution(int graph[][100001], int idx[],int n, int start)
{
    int element=0;
    int order[100001]={0};

    for(int i=1; i<=n; i++)
    {
        element=CountElement(graph[i],n);
        qsort(graph[i],element,sizeof(int),compare);
    }

    //PrintGraph(graph,idx,n);
    //TestPrint(graph,n);
    DFS(graph,n,start,order);

    for(int i=1; i<=n; i++)
    {
        printf("%d\n",order[i]);
    }

}

int main(void)
{
   int graph[100001][100001]={0};
   int idx[100001]={0};
   int n=0; int m=0; int start=0; char ch=' ';
   int a=0; int b=0; 

   scanf("%d %d %d%c", &n, &m, &start, &ch);

   for(int i=0; i<m; i++)
   {
        scanf("%d %d%c", &a, &b, &ch);
        graph[a][idx[a]]=b;
        graph[b][idx[b]]=a;
        idx[a]+=1;
        idx[b]+=1;
   }

   //TestPrint(graph,n);
   //PrintGraph(graph,idx,n);
   Solution(graph,idx,n,start);

    return 0;
}