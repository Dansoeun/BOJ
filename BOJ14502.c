#include <stdio.h>
#include <stdlib.h>

/*
1. 벽은 재귀로 구현
2. 2일 때 BFS 수행, 0이면 2로 바꾸고 queue에 넣기 
3. 마지막 0인 구간만 세기
*/

typedef struct
{
    int x;
    int y;
}Vertex;

int front=0;
int end=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void Enqueue(Vertex que[], Vertex data)
{
    que[end].x=data.x;
    que[end].y=data.y;
    end+=1;
}

Vertex Dequeue(Vertex que[])
{
    Vertex result;
    result.x=que[front].x;
    result.y=que[front].y;

    front+=1;

    return result;
}

int Max(int a, int b)
{
    if (a<b)
        return b;
    else 
        return a;
}

void CopyGraph(int graph[][10], int copy[][10], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            copy[i][j]=graph[i][j];
        }
    }
}

int CountArea(int graph[][10], int n, int m)
{
    int answer=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (graph[i][j]==0)
            {
                answer+=1;
            }
        }
    }

    return answer;
}

void BFS(int graph[][10], int n, int m, int *result)
{
    Vertex que[1000000];
    Vertex cur;
    Vertex temp;
    front=0;
    end=0;
    int areacnt=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (graph[i][j]==2)
            {
                cur.x=i;
                cur.y=j;
                Enqueue(que,cur);
            }
        }
    }

    while (front!=end)
    {
        cur=Dequeue(que);
        graph[cur.x][cur.y]=2;

        for(int i=0; i<4; i++)
        {
            temp.x=cur.x+dx[i];
            temp.y=cur.y+dy[i];

            if (temp.x<0 || temp.x>=n || temp.y<0 || temp.y>=m)
                continue;
            
            if (graph[temp.x][temp.y]==0)
            {
                Enqueue(que,temp);
            }
        }
    }

    areacnt=CountArea(graph,n,m);

    *result=Max(areacnt,*result);
}

void SetWell(int graph[][10], int n, int m, int wellcnt, int *result)
{
    if (wellcnt==3)
    {
        int copy[10][10]={0};
        CopyGraph(graph,copy,n,m);
        BFS(copy,n,m,result);
        return;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (graph[i][j]==0)
            {
                graph[i][j]=1;
                SetWell(graph,n,m,wellcnt+1,result);
                graph[i][j]=0;
            }
        }
    }
}

int main(void)
{
    int n=0; int m=0; char ch=' ';
    int graph[10][10]={0};
    int answer=0;

    scanf("%d %d%c", &n, &m, &ch);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        getchar();
    }

    SetWell(graph,n,m,0,&answer);

    printf("%d\n",answer);
}