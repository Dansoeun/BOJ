#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int visited[100005]={0};
static int dp[100005]={0};


typedef struct node 
{
    int data;
    int parent;
    struct node *next;
}Node; 

Node *makenode(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->parent=data;

    return newnode;
}

void Insert(Node *list[], int i,int data)
{
    Node *newnode=makenode(data);

    if (list[i]==NULL)
    {
        list[i]=newnode;
        return;
    }

    newnode->next=list[i];
    list[i]=newnode;

}


void dfs(Node *list[], int cur)
{
    if (visited[cur]==1)
        return; 
    
    visited[cur]=1;

    Node *temp=list[cur];
    
    while (temp!=NULL)
    {
        if (visited[temp->data]==0)
        {
            
        }
    }

}
void makeTree(Node *list[], int cur, int parent)
{
    Node *temp=list[cur];
    
    while (temp!=NULL)
    {
        if (temp->parent!=parent)
        {
            temp->parent=parent;
            makeTree(list,temp->data,parent);
        }

        temp=temp->next;
    }
}

void CountSubTreeNodes(Node *list[], int cur)
{
    if (visited[cur]==1)
        return;
    dp[cur]=1;
    visited[cur]=1;
    Node *temp=list[cur];

    while (temp!=NULL)
    {
        if (visited[temp->data]==0)
        {
            //visited[temp->data]=1;
            CountSubTreeNodes(list,temp->data);
            dp[cur]+=dp[temp->data];
        }
        temp=temp->next;
    }
}

int main(void)
{
    Node *list[100005];
    int n=0; int r=0; int q=0;
    int u=0; int v=0; char ch=' '; 
    int x=0;

    for(int i=0; i<100005; i++)
    {
        list[i]=NULL;
    }

    scanf("%d %d %d%c",&n, &r, &q, &ch);

    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d%c", &u, &v, &ch);
        Insert(list,u,v);
        Insert(list,v,u);
    }

    CountSubTreeNodes(list,r);
    for(int i=0; i<q; i++)
    {
        scanf("%d%c", &x, &ch);
        printf("%d\n",dp[x]);
    }

    return 0;
}