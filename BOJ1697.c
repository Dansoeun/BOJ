#include <stdio.h>
#include <stdlib.h>

int front=0;
int end=0;

typedef struct 
{
    int x;
    int time;
}Coord;

void Enqueue(Coord que[], Coord data)
{
    que[end].x=data.x;
    que[end].time=data.time;
    end+=1;
}

Coord Dequeue(Coord que[])
{
    Coord result;
    result.x=que[front].x;
    result.time=que[front].time;

    front+=1;

    return result;
}
void BFS(int x, int target)
{
    Coord que[100010];
    int visited[200000]={0};
    front=0;
    end=0;
    Coord cur;
    Coord temp;
    int diff_x=0;
    int multi_x=0;
    int add_x=0;

    cur.x=x;
    cur.time=0;

    if (x>=0 && x<=100000)
        Enqueue(que,cur);

    while (front!=end)
    {
        cur=Dequeue(que);
        //printf("cur.x:%d cur.time:%d\n",cur.x,cur.time);
        diff_x=cur.x-1;
        add_x=cur.x+1;
        multi_x=cur.x*2;

        if (cur.x<0 || cur.x>100000)
            continue;

        if (cur.x==target)
        {
            printf("%d\n",cur.time);
            return;
        }

        temp.time=cur.time+1;

        if (diff_x>=0 && diff_x<=100000 && visited[diff_x]==0)
        {
            temp.x=diff_x;
            visited[diff_x]=1;
            Enqueue(que,temp);
        }

        if (add_x>=0 && add_x<=100000 && visited[add_x]==0 )
        {
            temp.x=add_x;
            visited[add_x]=1;
            Enqueue(que,temp);
        }

        if (multi_x>=0 && multi_x<=100000 && visited[multi_x]==0)
        {
            temp.x=multi_x;
            visited[multi_x]=1;
            Enqueue(que,temp);
        }

        if (end>=100000)
        {
            end=0;
        }

        if (front>=100000)
        {
            front=0;
        }
    }

    printf("cur.x:%d cur.time:%d\n",cur.x,cur.time);
}

int main(void)
{
    int x=0; int target=0; char ch=' ';

    scanf("%d %d%c", &x, &target, &ch);
    int temp=1;


    BFS(x,target);
    return 0;
}