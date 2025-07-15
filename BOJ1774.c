

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct 
{
    int x;
    int y;
}Star;

typedef struct 
{
    int start;
    int end;
    double dist;
}DistList;

int static compare(const void *a, const void *b)
{
    DistList *temp_a = (DistList *)a;
    DistList *temp_b = (DistList *)b;

    if (temp_a->dist > temp_b->dist)
        return 1;
    else if (temp_a->dist < temp_b->dist)
        return -1;
    else 
        return 0;
}


double CalculateDist(Star s, Star e)
{
    double cal=pow(s.x-e.x,2)+pow(s.y-e.y,2);
    double result=sqrt(cal);

    return result;
}

void init_parent(int parent[], int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }

}

int GetParent(int parent[], int x)
{
    if (parent[x]==x)
        return x;
    
    return parent[x]=GetParent(parent,parent[x]);
}

int UnionParent(int parent[], int a, int b)
{
    a=GetParent(parent,a);
    b=GetParent(parent,b);

    if (a<b)
    {
        parent[b]=a;
        return a;
    }

    else 
    {
        parent[a]=b;
        return b;
    }
}

double Round(double n)
{
    double result = ((int)(n * 1000 + 0.5)) / 1000.0; 
    return result;
}

void Kruscal(Star space[], DistList li[],int parent[], int n, double answer, int m, int idx)
{
    qsort(li,idx,sizeof(DistList),compare);
    int kr_cnt=0;
    int vertex=0;
    DistList temp;

    while (kr_cnt!=n-m && vertex<idx)
    {
        temp=li[vertex];
        vertex+=1; 

        int s=GetParent(parent,temp.start);
        int e=GetParent(parent,temp.end );

        //printf("temp.start:%d temp.end:%d temp.dist:%.2f\n",temp.start,temp.end,temp.dist);

        if (s!=e)
        {
            //printf("s:%d e:%d\n",s,e);
            UnionParent(parent,s,e);
            answer+=temp.dist;
            kr_cnt+=1;
        }
    }
    //printf("answer:%.3f\n",answer);
    double res=Round(answer);

    printf("%.2f\n",res);


}

int main(void)
{
    Star space[1005];
    DistList li[100005];
    int parent[1005]={0};
    int n=0; int m=0; char ch=' ';
    int a=0; int b=0;
    int idx=0;
    double answer=0;

    scanf("%d %d%c", &n, &m, &ch);

    init_parent(parent,n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        space[i].x=a;
        space[i].y=b;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if (i==j)
                continue;
            li[idx].start=i;
            li[idx].end=j;
            li[idx].dist=CalculateDist(space[i],space[j]);
            idx+=1;
        }
    }


    for(int i=0; i<m; i++)
    {
        scanf("%d %d%c", &a, &b, &ch);
        UnionParent(parent,a,b);
        //answer+=(CalculateDist(space[a],space[b]));
    }

    //printf("init answer:%.2f \n", answer);

    Kruscal(space,li,parent,n,answer,m,idx);


    return 0;
}


