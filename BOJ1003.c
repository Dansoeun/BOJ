#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int zero;
    int one;
}Count;


int main(void)
{
    int t=0; char ch=' ';
    int n=0;

    scanf("%d%c", &t, &ch);

    Count dp[45];
    dp[0].one=0;
    dp[0].zero=1;
    dp[1].one=1;
    dp[1].zero=0;

    for(int i=2; i<=40; i++)
    {
        dp[i].one=dp[i-1].one+dp[i-2].one;
        dp[i].zero=dp[i-1].zero+dp[i-2].zero;
    }

    for(int i=0; i<t; i++)
    {
        scanf("%d%c", &n, &ch);
        printf("%d %d\n",dp[n].zero, dp[n].one);
    }

    return 0;
}