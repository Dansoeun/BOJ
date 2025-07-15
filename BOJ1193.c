#include <stdio.h>
#include <stdlib.h>


/*
1. 2n+1 (왕복+1)로 start하는 듯 
2. 
*/

long long GetStart(long long s)
{
    long long res=s*s+2*s;

    return res;
}

void Solution(long long x)
{
    long long start=1;
    long long temp=GetStart(start);
    long long prev=temp;
    long long cur=0;
    long long stand=0;
    long long under=0;
    long long above=0;

    while (temp<x)
    {
        start+=1;
        prev=temp;
        temp=GetStart(start);
    }

    cur=x-prev; 
    stand=start-1;
    start=2*stand-1; //1 , 3, 5 분자 시작점 

    if (cur<=start) // 증가 대각 
    {
        under=cur;
        above=start-(cur-1);
        
    }
    else //감소 대각
    {

        above=cur-start;
        under=start+1-(cur-1);
    }

    printf("%lld/%lld\n",above,under);


}

int main(void)
{
    long long x=0; char ch=' ';
    scanf("%lld%c", &x, &ch);
    Solution(x);
    return 0;

    
}