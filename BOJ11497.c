#include <stdio.h>
#include <stdlib.h>

int Abs(int n)
{
    if (n<0)
        return (-n);
    else 
        return n;
}

int static compare(const void *a, const void *b)
{
    int *temp_a=(int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return 1;
    else if (*temp_a < *temp_b)
        return -1;
    else 
        return 0;
}

void PrintArr(int arr[], int n)
{
    for(int i=0; i<=n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int GetDiff(int arr[], int n)
{
    if (n%2==1)
    {
        int temp=arr[1]-arr[0];
        int answer=arr[1]-arr[0];
    
        for(int i=1; i<n-1; i++)
        {
            temp=Abs(arr[i]-arr[i+1]);
    
            if (temp>answer)
                answer=temp;
        }
    
        return answer;
    }
    else 
    {
        int temp=arr[2]-arr[1];
        int answer=0;

        for(int i=1; i<n; i++)
        {
            temp=Abs(arr[i]-arr[i+1]);

            //printf("arr[%d]:%d arr[%d]:%d temp:%d answer:%d\n",i,arr[i],i+1,arr[i+1],temp,answer);

            if (temp>answer)
                answer=temp;
        }


        return answer;
    }

}

void Solution(int arr[], int n)
{
    qsort(arr,n,sizeof(int),compare);
    int result[100005]={0};
    result[n/2]=arr[n-1];
    int flag=0;
    int right=1;
    int left=-1;
    int answer=0;

    for(int i=n-2; i>=0; i--)
    {
        if (flag==0)
        {
            result[n/2+right]=arr[i];
            flag=1;
            right+=1;
        }
        else if (flag==1)
        {
            result[n/2+left]=arr[i];
            left-=1;
            flag=0;
        }
    }

    answer=GetDiff(result,n);
    printf("%d\n",answer);
}

int main(void)
{
    int t=0; char ch=' ';
    int n=0; 
    int arr[10005]={0};

    scanf("%d%c", &t ,&ch);

    for(int i=0; i<t; i++)
    {
        scanf("%d%c", &n, &ch);

        for(int j=0; j<n; j++)
        {
            scanf("%d", &arr[j]);
        }
        getchar();
        Solution(arr,n);
    }

    return 0;
}