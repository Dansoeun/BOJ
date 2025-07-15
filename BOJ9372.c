#include <stdio.h>
#include <stdlib.h>
//dfs 로 풀기 

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

    if (list[i]==NULL)
    {
        list[i]=newnode;
    }
    else 
    {
        newnode->next=list[i];
        list[i]=newnode;
    }
}

void InitList(Node *list[], int m)
{
    for(int i=0; i<m; i++)
    {
        list[i]=NULL;
    }
}

void DFS(Node *list[], int start, int visited[], int *answer)
{
    Node *temp=list[start];
    visited[start]+=1;

    while (temp!=NULL)
    {
        if (visited[temp->val]==0)
        {
            visited[temp->val]+=1;
            *answer+=1;
            DFS(list,temp->val,visited,answer);
        }
        temp=temp->next;
    }
}

void Solution(int n, int m)
{
    Node *list[1005];
    InitList(list,1005);
    int answer=0;
    int visited[1005]={0};
    char ch=' ';
    int a=0; int b=0;

    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        Insert(list,a,b);
        Insert(list,b,a);
    }

    DFS(list,1,visited,&answer);
    printf("%d\n",answer);
}

int main(void)
{
    int t=0; char ch=' ';
    int n=0; int m=0;

    scanf("%d%c", &t, &ch);

    for(int i=0; i<t; i++)
    {
        scanf("%d %d%c", &n, &m, &ch);
        Solution(n,m);
    }

    return 0;


}
