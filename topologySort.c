#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32005

typedef struct Queue
{
    int front;
    int rear;
    int *data;
}Queue;

int size;
int inDegree[MAX_SIZE];
int node[MAX_SIZE][MAX_SIZE];

void EnQ(Queue *q, int data)
{
    if (q->front==(q->rear+1))
    {
        printf("Queue is full\n");
        return;
    }
    else 
    {
        q->rear=q->rear+1;
        q->data[q->rear]=data;
    }
}

int DeQ(Queue *q)
{
    if (q->front==q->rear)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else 
    {
        q->front=q->front+1;
        return q->data[q->front];
    }
}

void topologySort(void)
{
    int result[MAX_SIZE]={0};
    Queue q;
    q.front=0;
    q.rear=0;
    q.data=malloc(sizeof(int)*MAX_SIZE);
    
    //진입 차수가 0인 노드를 큐에 삽입 
    for(int i=1; i<=size; i++)
    {
        if (inDegree[i]==0)
        {
            EnQ(&q, i);
        }
    }

    //n개의 노드 방문
    for(int i=1; i<=size; i++)
    {
        if (q.front==q.rear)
        {
            printf("사이클 발생\n");
            return;
        }

        int x=DeQ(&q);
        int cnt=0;
        result[i]=x;

        //노드 x의 간선 제거 & inDegree로 EnQ
        for(int y=1; y<=size; y++)
        {
            if (node[x][y]==1)
            {
                node[x][y]=0;

                if (--inDegree[y]==0)
                {
                    EnQ(&q,y);
                }
            }
        }
    }

    for(int i=1; i<=size; i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");
}

int main(void)
{
    int n=0; int m=0; 
    int a=0; int b=0; char ch=' ';

    scanf("%d %d%c", &n, &m, &ch);

    size=n;

    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        node[a][b]=1;
        inDegree[b]+=1;
    }
    /*
    size=8;

    node[1][3]=1;
    inDegree[3]+=1;
    node[2][1]=1;
    inDegree[1]+=1;
    node[2][5]=1;
    inDegree[5]+=1;
    node[3][4]=1;
    inDegree[4]+=1;
    node[3][7] = 1;    
    inDegree[7]++;    
    node[5][4] = 1;    
    inDegree[4]++;    
    node[5][6] = 1;    
    inDegree[6]++;    
    node[6][8] = 1;    
    inDegree[8]++;    
    node[8][7] = 1;    
    inDegree[7]++;
    */
    topologySort();


}