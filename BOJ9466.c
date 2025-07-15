#include <stdio.h>
#include <stdlib.h>

/*
1. 모든 노드에 대해 탐색
2. visit된 거 일때, 출발 노드와 같으면 전체 -= 현재 방문한 노드 개수 
*/

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

void Insert(Node *list[], int i, int data)
{
    Node *newnode=makenode(data);
    list[i]=newnode;
}
/*
void DFS(Node *list[], int start, int initstart, int visited[], int n,int *cnt)
{
    if (visited[start]==1)
    {
        //팀을 이룬 경우 
        if (initstart==start)
        {
            return;
        }
        //팀을 못 이룬 경우 
        else 
        {
            *cnt=0;
            return;
        }
    }


    visited[start]=1;
    *cnt+=1;
    DFS(list,list[start]->data,initstart,visited,n,cnt);

    if (*cnt==0)
    {
        visited[start]=0;
    }
    
}
*/

void DFS(int linklist[], int start, int initstart, int visited[], int n,int *cnt)
{
    
    if (visited[start]==1)
    {
        //팀을 이룬 경우 
        if (initstart==start)
        {
            return;
        }
        //팀을 못 이룬 경우 
        else 
        {
            *cnt=0;
            return;
        }
    }
    

    visited[start]=1;
    *cnt+=1;

    DFS(linklist,linklist[start],initstart,visited,n,cnt);

    if (*cnt==0)
    {
        visited[start]=0;
    }
    
}


void Solution(int n)
{
    //Node *list[100001];
    int linklist[100001]={0};
    int a=0; char ch=' ';
    int answer=n;
    int cnt=0;
/*
    for(int i=0; i<100001; i++)
    {
        list[i]=NULL;
    }
*/
    for(int i=1; i<=n; i++)
    {
        //list[i]=NULL;
        scanf("%d", &a);
        linklist[i]=a;
    }

    int visited[100001]={0};

    for(int i=1; i<=n; i++)
    {
        cnt=0;

        if (visited[i]==0)
        {
            DFS(linklist,i,i,visited,n,&cnt);
        }
        else if (linklist[i]==i)
        {
            cnt=1;
        }
        //printf("i:%d cnt:%d, answer:%d \n", i, cnt,answer);
        answer-=cnt;
    }

    printf("%d\n",answer);
}

int main(void)
{
    int t=0; int n=0; char ch=' ';

    scanf("%d%c", &t, &ch);

    for(int i=0; i<t; i++)
    {
        scanf("%d%c", &n, &ch);
        Solution(n);
    }

    return 0;

}