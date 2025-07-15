#include <stdio.h>
#include <stdlib.h>

int static compare(const void *a , const void *b)
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

void PrintEating(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("arr[%d]: %d\n",i,arr[i]);
    }
    printf("\n");
}

int BinarySearch(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int mid=0;
    int answer=0;

    while(start<=end)
    {
        mid=(start+end)/2;

        if (arr[mid]>=target)
        {
            break;
        }
        else
        {
            answer=mid;
            start=mid+1;
        }
    }

    printf("target:%d start:%d mid:%d end:%d\n",target,start,mid,end);
    //answer=mid;
    
    return answer;
}

void Solution(int Alife[], int Beating[], int n, int m)
{
    int answer=0;
    qsort(Alife,n,sizeof(int),compare);
    qsort(Beating,m,sizeof(int),compare);
    //PrintEating(Beating,m);

    for(int i=0; i<n; i++)
    {
        answer+=BinarySearch(Beating,m,Alife[i]);
        //printf("answer:%d\n",answer);
    }

    printf("%d\n",answer);
}

int main(void)
{
    int t=0; char ch=' ';
    int n=0; int m=0; 

    scanf("%d%c", &t, &ch);

    for(int i=0; i<t; i++)
    {
        int Alife[20005]={0};
        int Beating[20005]={0};
        scanf("%d %d%c", &n, &m, &ch);

        for(int j=0; j<n; j++)
        {
            scanf("%d", &Alife[j]);
        }
        getchar();

        for(int k=0; k<m; k++)
        {
            scanf("%d", &Beating[k]);
        }
        getchar();

        Solution(Alife,Beating,n,m);
    }

    return 0;
}