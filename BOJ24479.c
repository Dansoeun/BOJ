#include <stdio.h>
#include <stdlib.h>

static int visited[100005]={0};
static int cnt=1;

typedef struct node 
{
    int data;
    struct node *next;
}Node;

Node *makenode(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
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

Node *SearchNode(Node *list[], int i, int visited[])
{

}

void PrintIndex(Node *list[], int i)
{
    Node *temp=list[i];

    printf("i:%d\t",i);

    while (temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Insert(Node *list[], int i, int data)
{
    Node *newnode=makenode(data);

    //하나도 없었을 때
    if (list[i]==NULL)
    {
        list[i]=newnode;
        return;
    }

    //걍 젤 적을 때 
    if (data < list[i]->data)
    {
        newnode->next=list[i];
        list[i]=newnode;
    }

    else 
    {
        Node *temp=list[i];
        Node *prev=list[i];

        while (temp->next!=NULL)
        {
            if (temp->data < data) //input이 기존보다 큰 경우 계속 옮기기 
            {
                prev=temp;
                temp=temp->next;
            }
            else //input이 현재보다 크거나 같을 때 .. 
            {
                newnode->next=temp;
                prev->next=newnode;
                return;
            }
        }

        temp->next=newnode;
    }
    //PrintIndex(list,i);

}

void PrintList(Node *list[], int n)
{
    Node *temp=NULL;
    printf("\n");
    for(int i=1; i<=n; i++)
    {
        printf("i:%d \t",i);
        temp=list[i];

        while (temp!=NULL)
        {
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    printf("\n");
}


int CountElement(Node *list[], int i)
{
    int cnt=0;
    Node *temp=list[i];

    while (temp!=NULL)
    {
        cnt+=1;
        temp=temp->next;
    }

    return cnt;
}

void DFS(Node *list[], int start, int order[])
{
    Node *temp=list[start];
    visited[start]=1;
    order[start]=cnt;

    if (list[start]==NULL)
        return;
    
    while (temp!=NULL)
    {
        if (visited[temp->data]==0)
        {
            cnt+=1;
            DFS(list,temp->data,order);
        }

        temp=temp->next;
    }
}

void Solution(Node *list[], int n, int start)
{
    int order[100005]={0};
    int element=0;

    /*for(int i=1; i<=n; i++)
    {
        SortMerge(list,i,list[i]);
    }
    */

    PrintList(list,n);
    //DFS(list,start,order);

    for(int i=1; i<=n; i++)
    {
        if (order[i]!=0)
            printf("%d\n",order[i]);
        else 
            printf("%d\n",0);
    }
}



int main(void)
{
    Node *list[100001];
    int n=0; int m=0; int start=0; char ch=' ';
    int a=0; int b=0;

    for(int i=0; i<100001; i++)
    {
        list[i]=NULL;
    }

    scanf("%d %d %d%c", &n, &m, &start, &ch);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        Insert(list,a,b);
        Insert(list,b,a);

        PrintList(list,n);
    }

    Solution(list,n,start);
    

    return 0;
}