#include <stdio.h>
#include <stdlib.h>

/*
연속 3잔을 마실 수 없으므로,
1. 2번째 전과 현재 잔 
2. 아예 마시지 않는 것
3. 3번째 전 잔과 1번째 전 잔, 지금 잔 
위의 3개중 최대값을 취함
*/
int Max(int a, int b)
{
    if (a>b)
        return a;
    else 
        return b;
}

void Solution(int grape[], int n)
{
    int dp[100005]={0};
    int hap=0;
    dp[1]=grape[1];
    dp[2]=grape[1]+grape[2];

    for(int i=3; i<=n; i++)
    {
        dp[i]=Max(grape[i]+dp[i-2], Max(dp[i-1], dp[i-3]+grape[i]+grape[i-1]));

    }

    printf("%d\n", dp[n]);

}

int main(void)
{
    int grape[10005]={0};
    int n=0; char ch=' ';

    scanf("%d%c", &n, &ch);

    for(int i=1; i<=n; i++)
    {
        scanf("%d%c", &grape[i], &ch);
    }

    Solution(grape,n);

    return 0;
}