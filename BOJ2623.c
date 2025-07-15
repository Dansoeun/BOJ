#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int isDegree[1005];

typedef struct
{
    int front;
    int rear;
    int Que[100000];
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

void Insert(Node *list[], int i, int data)
{
    Node *newnode=makenode(data);
    Node *temp=list[i];

    if (list[i]==NULL)
    {
        list[i]=newnode;
        return;
    }
    else 
    {
        newnode->next=list[i];
        list[i]=newnode;
        return;
    }
}

void EnQ(Queue *q, int data)
{
    if (q->front!=q->rear+1)
    {
        q->rear+=1;
        q->Que[q->rear]=data;
    }
}

int DeQ(Queue *q)
{
    if (q->front+1!=q->rear)
    {
        q->front+=1;
        int temp=q->Que[q->front];
        q->Que[q->front]=-1;

        return temp;
    }

    return -1;
}


void topologysort(Node *list[], int n)
{
    int result[10005]={0};
    int visit[10005]={0};
    Node *temp=NULL;
    Queue q;
    q.front=0;
    q.rear=0;
    int x=-1;

    for(int i=1; i<=n; i++)
    {
        if (isDegree[i]==0)
        {
            EnQ(&q, i);
        }
    }

    for(int i=1; i<=n; i++)
    {
        x=DeQ(&q);

        if (x==-1)
        {
            printf("%d\n",0);
            return;
        }
        else 
        {
            if (visit[x]!=1)
            {
                printf("%d\n",0);
                return;
            }
            result[i]=x;
            visit[x]+=1;
            temp=list[x];

            while (temp!=NULL)
            {
                isDegree[temp->val]-=1;

                if (isDegree[temp->val]==0)
                {
                    EnQ(&q,temp->val);
                }
                temp=temp->next;
            }
        
        }

    }

    for(int i=1; i<=n; i++)
    {
        printf("%d\n", result[i]);
    }
}

int main(void) {
    int n = 0, m = 0;
    Node *list[1005];
    char input[5000];
    int visited[1005]={0};

    for (int i = 0; i < 1005; i++) {
        list[i] = NULL;
    }

    scanf("%d %d", &n, &m);
    getchar(); 

    for (int i = 0; i < m; i++) {
        fgets(input, sizeof(input), stdin);
        int nums[100];
        int cnt = 0;
        char *token = strtok(input, " \n");

        while (token != NULL) {
            
            nums[cnt++] = atoi(token);
            token = strtok(NULL, " \n");
        }

        for (int j = 0; j < cnt - 1; j++) {
            Insert(list, nums[j], nums[j + 1]);
            isDegree[nums[j + 1]] += 1;
        }
    }

    topologysort(list, n);

    // 메모리 해제
    for (int i = 0; i < 1005; i++) {
        Node *cur = list[i];
        while (cur != NULL) {
            Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }

    return 0;
}