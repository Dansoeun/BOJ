#include <stdio.h>
#include <stdlib.h>

void PrintDp(int arr[], int n)
{
    for(int i=0; i<=n; i++)
    {
        printf("arr[%d]:%d\n",i,arr[i]);
    }
    printf("\n");
}

void Solution(int n)
{
    int dp[50]={0};
    dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    //PrintDp(dp,n);

    printf("%d\n",dp[n]);
}

int main(void)
{
    int n=0; char ch=' ';

    scanf("%d%c", &n, &ch);
    Solution(n);

    return 0;
}