#include <stdio.h>
#include <stdlib.h>

/*
1. 정렬 후, 일단 중복없이 순위 할당
2. 중복된 사항에 대해서는 젤 적은 등수부터 순차적 할당
3. 예상 등수가 전체 인원보다 클 수 있음 
*/

long long Abs(int a)
{
    if (a<0)
        return (-a);
    else 
        return a;
}

int static compare(const void *a, const void *b)
{
    int *temp_a= (int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return 1;
    else if (*temp_a < *temp_b)
        return -1;
    else 
        return 0;
}

int static rever_compare(const void *a, const void *b)
{
    int *temp_a=(int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return -1;
    else if (*temp_a < *temp_b)
        return 1;
    else 
        return 0;
}

void Solution(int wish[], int n, int cnt[])
{
    int rank[500005]={0};
    int repeat[500005]={0};
    int idx=0;
    int cur=0;
    long long answer=0;

    qsort(wish,n,sizeof(int),compare);

    for(int i=0; i<n; i++)
    {
        if (wish[i]<=n && repeat[wish[i]]==0)
        {
            repeat[wish[i]]+=1;
            wish[i]=0;
            cnt[wish[i]]-=1;
        }
        else 
        {
            rank[idx]=wish[i];
            idx+=1;
        }
    }

    qsort(rank,idx,sizeof(int),compare);

    for(int i=1; i<=n; i++)
    {
        if (cur==idx)
            break;
        
        if (repeat[i]==0)
        {
            answer+=(Abs(rank[cur]-i));
            cur+=1;

        }
    }


    printf("%lld\n",answer);


}

int main(void)
{
    int n=0; char ch=' ';
    int wish[500005]={0};
    int cnt[500005]={0};
    int a=0;

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        scanf("%d%c", &wish[i], &ch);
        cnt[wish[i]]+=1;
    }

    Solution(wish,n,cnt);
    return 0;
}