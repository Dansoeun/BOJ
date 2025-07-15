#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int front=0;
int end=0;

typedef struct 
{
    int x;
    int y;
}Vertex;

/*
1. 탐색하면서 상하좌우 해당하면 queue에 넣음 (BFS 계속 시행)
2. 끊기면 DFS로 그래프 not visited 찾을 때까지 탐색 
*/
void Enqueue(Vertex que[],  Vertex data)
{
    que[end].x=data.x;
    que[end].y=data.y;
    end+=1;
}

Vertex Dequeue(Vertex que[])
{
    Vertex result;
    result=que[front];
    front+=1;

    return result;
}

//flag: 적록색 약 먹었는지 여부
//0 : 안 먹음 , 1 : 먹음 
/*
int BFS(Vertex que[], int visited[][105], char graph[][105], char mode,int flag, int n)
{
    Vertex cur;
    Vertex temp;

    while (front!=end)
    {
        cur=Dequeue(que);

        for(int i=0; i<4; i++)
        {
            temp.x=cur.x+dx[i];
            temp.y=cur.y+dy[i];

            if (temp.x>=n || temp.x <0 || temp.y>=n || temp.y<0)
                continue;
    
            if (visited[temp.x][temp.y]==0 && flag==0)
            {
                if (graph[temp.x][temp.y]==mode)
                {
                    Enqueue(que,temp);
                    visited[temp.x][temp.y]=1;
                }
            }

            else if (visited[temp.x][temp.y]==0 && flag==1)
            {
                if (mode=='R' || mode=='G')
                {
                    Enqueue(que,temp);
                    visited[temp.x][temp.y]=1;
                }

                else if (mode=='B')
                {
                    Enqueue(que,temp);
                    visited[temp.x][temp.y]=1;
                }
            }
        }
    }

    return 1;

}

int DFS(Vertex que[], int visited[][105], char graph[][105],int flag ,int n)
{
    int answer=0;
    Vertex cur;
    char mode[5]={'R','G','B'};
    //printf("dfs init\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //printf("dfs i:%d j:%d\n",i,j);
            if (visited[i][j]==0)
            {
                printf("dfs i:%d j:%d answer:%d\n",i,j,answer);
                cur.x=i;
                cur.y=j;
                Enqueue(que,cur);
                visited[i][j]=1;
                answer+=BFS(que,visited,graph,mode[0],flag,n);
                //answer+=1;
            }
        }
    }

    printf("R answer:%d\n",answer);
    

    return answer;
}
*/

void BFS(char graph[][105], int visited[][105], int n, char mode, Vertex start)
{
    Vertex que[10005];
    front=0;
    end=0;
    Vertex cur;
    Vertex temp;
    Enqueue(que,start);

    while (front!=end)
    {
        cur=Dequeue(que);
        visited[cur.x][cur.y]=1;

        for(int i=0; i<4; i++)
        {
            temp.x=cur.x+dx[i];
            temp.y=cur.y+dy[i];

            if (temp.x<0 || temp.x >=n || temp.y<0 || temp.y>=n)
                continue;
            
            if (visited[temp.x][temp.y]==0 && graph[temp.x][temp.y]==mode)
            {
                Enqueue(que,temp);
                visited[temp.x][temp.y]=1;
            }

        }
    }
}

void REDBFS(char graph[][105], int visited[][105], int n, char mode, Vertex start)
{
    Vertex que[10005];
    front=0;
    end=0;
    Vertex cur;
    Vertex temp;
    Enqueue(que,start);

    while (front!=end)
    {
        cur=Dequeue(que);
        visited[cur.x][cur.y]=1;

        for(int i=0; i<4; i++)
        {
            temp.x=cur.x+dx[i];
            temp.y=cur.y+dy[i];

            if (temp.x<0 || temp.x >=n || temp.y<0 || temp.y>=n)
                continue;
            
            if (visited[temp.x][temp.y]==0)
            {
                if (mode=='R' || mode=='G')
                {
                    if (graph[temp.x][temp.y]!='B')
                    {
                        Enqueue(que,temp);
                        visited[temp.x][temp.y]=1;
                    }
                }
                else 
                {
                    if (graph[temp.x][temp.y]==mode)
                    {
                        Enqueue(que,temp);
                        visited[temp.x][temp.y]=1;
                    }
                }
            }

        }
    }
}

int NoMedicine(char graph[][105], int n)
{
    int visited[105][105]={0};
    int answer=0;
    Vertex start;
    //printf("red medicine\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (visited[i][j]==0)
            {
                visited[i][j]=1;
                start.x=i;
                start.y=j;
                BFS(graph,visited,n,graph[i][j],start);
                answer+=1;
            }
        }
    }
    
    //answer=DFS(que,visited,graph,1,n);

    return answer;
}

int RedMedicine(char graph[][105], int n)
{
    int visitied[105][105]={0};
    int answer=0;
    Vertex start;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (visitied[i][j]==0)
            {
                visitied[i][j]=1;
                start.x=i;
                start.y=j;
                REDBFS(graph,visitied,n,graph[i][j],start);
                answer+=1;
            }
        }
    }

    return answer;
}

void PrintGraph(char graph[][105], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n=0; char ch=' ';
    char graph[105][105]={'\0'};
    int red_ans=0;
    int no_ans=0;

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        scanf("%s", graph[i]);
        getchar();
    }

    //PrintGraph(graph,n);
    red_ans=RedMedicine(graph,n);
    no_ans=NoMedicine(graph,n);

    printf("%d %d\n",no_ans,red_ans);


    return 0;
}