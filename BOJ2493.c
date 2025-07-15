#include <stdio.h>

int top=-1; 

typedef struct 
{
    int value;
    int index;
}Data;

void Push(Data stack[], int data, int idx)
{
    top+=1;
    stack[top].value=data;
    stack[top].index=idx;

}

Data Pop(Data stack[])
{
    Data res;
    res.value=stack[top].value;
    res.index=stack[top].index;

    stack[top].value=-1;
    stack[top].index=-1;
    top-=1;

    return res;

}


void Solution(int list[], int n)
{
    Data stack[500005];
    Data temp;
    int result[500005]={0};

    for(int i=0; i<n; i++)
    {
        if (top==-1)
        {
            Push(stack,list[i],i+1);
            result[i]=0;
        }

        else if (stack[top].value > list[i])
        {
            result[i]=stack[top].index;
            Push(stack,list[i],i+1);
        }
        else 
        {
            while (stack[top].value < list[i] && top>-1)
            {
                temp=Pop(stack);
            }

            if (top==-1)
            {
                Push(stack,list[i],i+1);
                result[i]=0;
            }
            else 
            {
                result[i]=stack[top].index;
                Push(stack,list[i],i+1);
            }
        }

    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

}

int main(void)
{
    int n=0;
    char ch=' ';
    int list[500005]={0};

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &list[i]);
    }
    getchar();

    Solution(list,n);

    return 0; 
}