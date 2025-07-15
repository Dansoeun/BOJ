#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    int depth;
    struct node *next;
}Node;

Node *makenode(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->depth=0;
    newnode->next=NULL;

    return newnode;
}



void DFS(Node *list[],int cur, int curdepth, int parent,int visited[])
{
    Node *temp=list[cur];

    while (temp!=NULL)
    {
        if (visited[temp->data]==0)
        {
            

        }
    }

}