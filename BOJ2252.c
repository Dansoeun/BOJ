#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32005

int inDegree[MAX_SIZE];
typedef struct Queue 
{
    int front;
    int rear;
    int data[MAX_SIZE];
}Queue;

typedef struct node
{
    int val;
    struct node *next;
}Node;

Node *makenode(int val)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=NULL;

    return newnode;
}

void Insert(Node *list[], int i, int val)
{
    Node *newnode=makenode(val);
    newnode->next=list[i];
    list[i]=newnode;
}

void EnQ(Queue *q, int data)
{
    if (q->front!=(q->rear+1))
    {
        q->rear=q->rear+1;
        q->data[q->rear]=data;
    }
}

int DeQ(Queue *q)
{
    if (q->front!=q->rear)
    {
        q->front+=1;

        int temp=q->data[q->front];

        return temp;
        
    }
}

void topologySort(Node *list[], int n)
{
    int result[MAX_SIZE]={0};
    Queue q;
    q.front=0;
    q.rear=0;

    for(int i=1; i<=n; i++)
    {
        if (inDegree[i]==0)
        {
            EnQ(&q,i);
        }
    }

    for(int i=1; i<=n; i++)
    {
        int x=DeQ(&q);
        int cnt=0;
        result[i]=x;

        Node *temp=list[x];

        while (temp!=NULL)
        {
            inDegree[temp->val]-=1;

            if (inDegree[temp->val]==0)
            {
                EnQ(&q,temp->val);
            }

            temp=temp->next;
        }
    }

    for(int i=1; i<=n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main(void)
{
    int n=0; int m=0; 
    int a=0; int b=0; char ch=' ';

    scanf("%d %d%c", &n, &m, &ch);

    Node *list[32005];

    for(int i=0; i<32005; i++)
        list[i]=NULL;
    
    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        Insert(list,a,b);
        inDegree[b]+=1;
    }

    topologySort(list,n);

    for(int i=0; i<32005; i++)
        free(list[i]);
    return 0;
}