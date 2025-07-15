#include <stdio.h>

void Print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}
void Switch(int arr[] , int idx, int n)
{
    for(int i=idx; i<idx+3; i++)
    {
        if (i>=n)
            break;
        else 
        {
            if (arr[i]==0)
                arr[i]=1;
            else if (arr[i]==1)
                arr[i]=0;
        }
    }
}

void Solution(int arr[], int n, int target[])
{
    int answer=0;

    for(int i=0; i<n; i++)
    {
        if (target[i]==arr[i])
            continue;
        else 
        {
            Switch(arr,i,n);
            answer+=1;
        }
        //Print(arr,n);
    }
    printf("%d\n",answer);
}

int main(void)
{
    int n=0; char ch=' ';
    int arr[1000005]={0};
    int target[1000005]={0};

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &target[i]);
    }
    getchar();

    Solution(arr,n,target);

    return 0;
}