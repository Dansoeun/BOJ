#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int dist;
    struct node *next;
}Node;

Node *makenode(int value, int dist)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->value=value;
    newnode->dist=dist;
    newnode->next=NULL;

    return newnode;
}

void Insert(Node *list[], int i, int value, int dist)
{
    Node *newnode=makenode(value,dist);
    Node *temp=NULL;

    if (list[i]==NULL)
    {
        list[i]=newnode;
        return;
    }

    temp=list[i];

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;

    return;
}

void PrintGraph(Node *list[], int n)
{
    Node *temp=NULL;

    for(int i=1; i<=n; i++)
    {
        printf("%d:\t",i);

        temp=list[i];

        while (temp!=NULL)
        {
            printf("[value:%d dist:%d] -> ",temp->value,temp->dist);
            temp=temp->next;
        }
        printf("\n");
    }

    printf("\n");
}

void LeftDist(Node *list[], int i, int *ans)
{
    Node *temp=list[i];

    while (temp!=NULL)
    {
        *ans+=(temp->dist);
        temp=list[temp->value];
    }
}

void RightDist(Node *list[], int i, int *ans)
{
    Node *cur=list[i];

    if (list[i]==NULL)
        return;

    while(cur->next!=NULL)
    {
        cur=cur->next;
    }

    while (cur!=NULL)
    {
        *ans+=(cur->dist);

        cur=list[cur->value];

        if (cur==NULL)
            return;

        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
    }

}

int CalDist(Node *list[], int i)
{
    if (list[i]==NULL)
        return 0;
    
    int left=list[i]->value;
    int right=0;
    int l_len=0;
    int r_len=0;
    int answer=0;
    Node *temp=list[i];

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    right=temp->value; //왼, 오 시작 child 설정, 젤 큰 거
    
    //printf("start:%d left:%d right:%d\n",i,left,right);
    if (right==0)
        return 0;

    l_len=list[i]->dist;
    r_len=temp->dist;

    LeftDist(list,left,&l_len);
    RightDist(list,right,&r_len);

    //printf("start:%d left:%d right:%d l_len:%d r_len:%d\n",i,left,right,l_len,r_len);
    answer=l_len+r_len;

    return answer;
}

void DFS(Node *list[], int i, int visited[], int *answer)
{
    Node *temp=list[i];
    visited[i]=1;
    int cur_dist=0;

    while (temp!=NULL)
    {
        if (visited[temp->value]==0)
        {
            cur_dist=CalDist(list,temp->value);
            //printf("start:%d cur_dist:%d answer:%d\n\n",temp->value,cur_dist,*answer);

            if (cur_dist>*answer)
            {
                *answer=cur_dist;
            }

            DFS(list,temp->value,visited,answer);
            visited[temp->value]=1;
        }

        temp=temp->next;
    }
}

int main(void)
{
    int n=0; char ch=' ';
    int a=0; int b=0; int c=0; 
    int answer=0;
    Node *list[10001];
    int visited[10005]={0};

    for(int i=0; i<10001; i++)
    {
        list[i]=NULL;
    }

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d %d%c", &a, &b, &c, &ch);
        Insert(list,a,b,c);
    }
    PrintGraph(list,n);

    //DFS(list,1,visited,&answer);

    printf("%d\n",answer);

    return 0;

}