#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32005

/*
1. 기본 베이스는 위상정렬
2. 단, 위상 정렬 중 선택지가 여러 개일 때 먼저 푸는 것이 좋은 문젤를 반드시 먼저 풀어야함
3. -> 쉬운 문제부터 정렬해서 넣어야함 
*/

static int isDegree[MAX_SIZE];

typedef struct node 
{
    int val;
    struct node *next;
}Node;

typedef struct
{
    int front;
    int rear;
    int Que[MAX_SIZE];
}Queue;

typedef struct 
{
    int heap[MAX_SIZE];
    int size;
}Heap;

void min_heap_insert(Heap *h, int item)
{
    h->size+=1;
    int i=h->size; 

    while ((i!=1) && item< h->heap[i/2])
    {
        h->heap[i]=h->heap[i/2];
        i/=2;
    }

    h->heap[i]=item;
}

int min_heap_delete(Heap *h)
{
    int result=h->heap[1];
    int temp=h->heap[h->size];
    h->size-=1;

    int parent=1;
    int child=2;

    while (child<=h->size)
    {
        if (child< h->size && h->heap[child] > h->heap[child+1])
        {
            child+=1;
        }

        if (temp<h->heap[child])
            break;

        h->heap[parent]=h->heap[child];
        parent=child;
        child*=2;
    }

    h->heap[parent]=temp;

    return result;
}


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

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
}

static int compare(const void *a, const void *b)
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

void EnQ(Queue *q, int data)
{
    if (q->front!=(q->rear+1))
    {
        q->rear=q->rear+1;
        q->Que[q->rear]=data;
        //qsort(q->Que + q->front + 1, q->rear - q->front, sizeof(int), compare);
    }
}

int DeQ(Queue *q)
{
    //qsort(q.Que + q.front + 1, q.rear - q.front, sizeof(int), compare);
    qsort(q->Que + q->front + 1, q->rear - q->front, sizeof(int), compare);
    if (q->front!=q->rear)
    {
        q->front+=1;

        int temp=q->Que[q->front];

        return temp;
    }
}

void topologySort(Node *list[], int n)
{
    int result[MAX_SIZE]={0};
    /*
    Queue q;
    q.front=0;
    q.rear=0;
    */
    Heap h;
    h.size=0;
    int x=-1;
    int max_degree=32005;


    for(int i=1; i<=n; i++)
    {
        if (isDegree[i]==0)
        {
            min_heap_insert(&h,i);
            //EnQ(&q,i);
        }
    }

    for(int i=1; i<=n; i++)
    {
        //x=DeQ(&q);
        x=min_heap_delete(&h);
        result[i]=x;

        Node *temp=list[x];

        while (temp!=NULL)
        {
            isDegree[temp->val]-=1;

            if (isDegree[temp->val]==0)
            {
                min_heap_insert(&h,temp->val);
                //EnQ(&q,temp->val);
            }

            temp=temp->next;
        }
        //qsort(q.Que + q.front + 1, q.rear - q.front, sizeof(int), compare);
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
    Node *list[MAX_SIZE];

    for(int i=0; i<MAX_SIZE; i++)
    {
        list[i]=NULL;
    }

    scanf("%d %d%c", &n, &m, &ch);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        Insert(list,a,b);
        isDegree[b]+=1;
    }

    topologySort(list,n);

    for(int i=0; i<MAX_SIZE; i++)
    {
        free(list[i]);
    }

    return 0;
}