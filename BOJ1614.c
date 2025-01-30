#include <stdio.h>

int main(void)
{
    long long num=0;
    char ch=' ';
    int injury=0;
    long long cnt=0;


    scanf("%d%c", &injury, &ch);
    scanf("%lld%c", &cnt, &ch);

    if (injury==5)
    {
        num=8*cnt;

        num+=4;
    }

    else if (injury==1)
    {
        num=8*cnt;
    }
    else 
    {
        num=8*(cnt/2);

        if (cnt%2==0)
        {
            num+=(injury-1);
        }
        else 
        {
            num+=5;
            num+=(4-injury);
        }
    }




    printf("%lld\n",num);
    return 0;


}