#include <stdio.h>

void Print(int li[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("i:%d val:%d\n",i,li[i]);
    }
}

int Max(int a, int b)
{
    if (a<b)
        return b;
    else 
        return a;
}

void Solution(int list[],int sum[] ,int n)
{
    int dp[100005]={0};
    int hap=0;
    int temp=0;
    int prev=0;
    int answer=list[0];

    sum[0]=list[0];
    dp[0]=list[0];

    for(int i=1; i<n; i++)
    {
        sum[i]=dp[i-1]+list[i];

        if (sum[i]>=list[i])
        {
            dp[i]=sum[i];
        }
        else
        {
            dp[i]=list[i];
            sum[i]=dp[i];
        }
    }

    //Print(dp,n);

    prev=dp[0];

    for(int i=1; i<n; i++)
    {
        prev=Max(dp[i],prev);
    }

    printf("%d\n",prev);
    

}

int main(void)
{
    int n=0; char ch=' ';
    int list[100005]={0};
    int sum[100005]={0};

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &list[i]);

        if (i==0)
        {
            sum[i]=list[i];
        }
        else 
        {
            sum[i]=sum[i-1]+list[i];
        }
        
    }
    getchar();

    Solution(list,sum,n);

}