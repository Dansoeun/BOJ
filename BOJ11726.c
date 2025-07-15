#include <stdio.h>

int main(void)
{
    int arr[1005]={0};
    int n=0; char ch=' ';
    scanf("%d%c", &n, &ch);

    arr[1]=1;
    arr[2]=2; 

    for(int i=3; i<=n; i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%10007;
    }

    printf("%d\n",arr[n]);

    return 0;

}