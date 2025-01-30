#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

void Floid(int graph[][105], int n)
{
    int distance[105][105]={0};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            distance[i][j]=graph[i][j];
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (distance[i][k]+distance[k][j]<distance[i][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (distance[i][j]<INF)
            {
                printf("%d ", 1);
            }
            else 
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int n=0; char ch=' ';
    int graph[105][105]={0};
    int a=0;

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &a);

            if (a==0)
            {
                graph[i][j]=INF;
            }
            else 
            {
                graph[i][j]=1;
            }
        }
        getchar();
    }

    Floid(graph,n);

    return 0;
}