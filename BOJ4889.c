#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
1. { : 0 , } : 1 
2. 스택 쌓고 pop 하면서 1 cnt 먼저 셈
3. 0 나오는 시점부터 0 cnt 세고
4. 0 cnt 끊기면 (= 다음 1 나오기 전까지) 1cnt-0cnt만큼 수행 
5. 근데 0부터 나오면 .. (0cnt-1cnt) + 0cnt개수 (rever할만큼)
*/

int top=-1;

void push(int stack[], int data)
{
    top+=1;
    stack[top]=data;
}

int pop(int stack[])
{
    if (top==-1)
        return -1;

    int result=stack[top];
    top-=1;

    return result;
}

int Abs(int a)
{
    if (a<0)
        return (-a);
    else 
        return a;
}

void SetStack(char data[], int stack[])
{
    int len=strlen(data);

    for(int i=0; i<len; i++)
    {
        if (data[i]=='{')
            push(stack,0);
        else if (data[i]=='}')
            push(stack,1);
    }
}

void Solution(char data[], int t)
{
    int answer=0;
    int cur=0;
    int onecnt=0;
    int zerocnt=0;
    int reverflag=0;
    int stack[2005]={0};

    SetStack(data,stack);

    while (top>=0)
    {
        cur=pop(stack);

        if (cur==0)
        {
            if (onecnt==0)
            {
                reverflag=1;
            }

            if (onecnt>0 && reverflag==1)
            {
                answer+=(Abs(zerocnt-onecnt)+onecnt+zerocnt);
            }

            zerocnt+=1;
        }
        else if (cur==1)
        {
            if (zerocnt>0)
            {

            }

        }
    }

    printf("%d. %d\n", t,answer);
}