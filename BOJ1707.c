#include <stdio.h>
#include <stdlib.h>

int front=0;
int qend=0;

typedef struct node
{
    int value;
    int color;
    struct node *next;
}Node;

Node *makenode(int value)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->value=value;
    newnode->color=-1;
    newnode->next=NULL;

    return newnode;
}

void Init_list(Node *list[], int n)
{
    for(int i=1; i<=n; i++)
    {
        list[i]=NULL;
    }
}

void Insert(Node *list[], int value, int i)
{
    Node *newnode=makenode(value);

    if (list[i]==NULL)
    {
        list[i]=newnode;
        return;
    }

    Node *temp=list[i];

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
}


void Enqueue(int que[], int value)
{
    que[qend]=value;
    qend+=1;
}

int Dequeue(int que[])
{
    int result=que[front];
    front+=1;

    return result;
}
/*
void DFS(Node *list[], int start, int visited[], int *color)
{
    visited[start]=1;
    Node *temp=list[start];
    temp=temp->next;
    
    while (temp!=NULL)
    {
        if (visited[temp->value]==0)
        {
            visited[temp->value]=1;
            temp->color=*color;
            list[temp->value]->color=*color;
            //printf("value:%d color:%d answer:%d start color:%d, start:%d\n",temp->value,*color,*answer,list[start]->color,start);
            ChangeColor(color);
            DFS(list,temp->value,visited,color);
        }
        temp=temp->next;
    }
}

*/

void BFS(Node *list[], int start, int visited[] ,int *answer)
{
    int que[20005]={0};
    int color=0;
    front=0;
    qend=0;
    //int visited[20005]={0};
    Enqueue(que,start);
    int vertex=start;
    Node *temp=NULL;
    visited[start]=1;
    list[start]->color=color;

    while (front!=qend)
    {
        vertex=Dequeue(que);
        temp=list[vertex];
        
        while (temp!=NULL)
        {
            //printf("cur:%d vertex:%d cur color:%d vertex color:%d\n",temp->value,vertex,temp->color,list[vertex]->color);

            if (visited[temp->value]==0)
            {
                list[temp->value]->color=1-list[vertex]->color;
                Enqueue(que,temp->value);
                visited[temp->value]=1;
            }

            else 
            {
                if (list[temp->value]->color==list[vertex]->color)
                {
                    *answer=-1;
                    return;
                }
            }

            temp=temp->next;
        }

        if (*answer==-1)
            return;

    }
}

int main(void)
{
    Node *list[20005];
    int k=0; char ch=' ';
    int v=0; int e=0;
    int s=0; int end=0;
    int color=0;
    int answer=0;

    scanf("%d%c", &k, &ch);
    //Init_list(list,20005);

    for(int i=0; i<k; i++)
    {
        scanf("%d %d%c", &v, &e, &ch);
        Init_list(list,v);
        int visited[20005]={0};
        color=0;
        answer=0;

        for(int j=0; j<e; j++)
        {
            scanf("%d %d%c", &s, &end, &ch);
            Insert(list,end,s);
            Insert(list,s,end);
        }

        //DFS(list,1,visited,&color);
        BFS(list,1,visited,&answer);

        if (answer==0)
        {
            printf("YES\n");
        }
        else 
        {
            printf("NO\n");
        }
    }

    /*for(int i=0; i<20005; i++)
    {
        free(list[i]);
    }*/

    return 0;
}