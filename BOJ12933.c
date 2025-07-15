#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. q 시작하고 uack가 있는지를 확인해야할 듯 
2. q 시작하고 uack가 끝나는 동안 다른 q가 들어오고 완성되면 개체수 +=1

*/

//q 시작하고 uack가 있는지를 

void AddSound(int duck[], int flag, int standard)
{
    for(int i=1; i<=flag; i++)
    {
        if (duck[i]==standard)
        {
            duck[i]+=1;
            return;
        }
    }
}

void CountSound(int duck[], int *flag, char cur, int *answer)
{
    int temp=0;
    if (cur=='u')
    {
        AddSound(duck,*flag,1);
    }

    else if (cur=='a')
    {
        AddSound(duck,*flag,2);
    }
    else if (cur=='c')
    {
        AddSound(duck,*flag,3);
    }
    else if (cur=='k')
    {
        AddSound(duck,*flag,4);
    }

    for(int i=1; i<=*flag; i++)
    {
        if (duck[i]==5)
        {
            if (*flag==1 && *answer>=1)
            {
                duck[i]=0;
                *flag-=1;
                return;
            }

            *answer+=1;
            duck[i]=0;
            temp+=1; //실질적으로 끝난 애들 수 
            //*flag-=1;
        }
    }
    *flag-=temp;

}

void Solution(char input[])
{
    int duck[3000]={0}; //flag index마다 맞는 알파벳 개수 cnt+=1
    int answer=0;
    int flag=0; //q로 시작하는 개수

    for(int i=0; i<strlen(input); i++)
    {
        if (input[i]=='q')
        {
            flag+=1;
            duck[flag]+=1;
        }

        else 
        {
            CountSound(duck,&flag,input[i],&answer);
        }
    }

    if (answer==0)
    {
        printf("%d\n",-1);
        return;
    }

    printf("%d\n", answer);
}

int main(void)
{
    char input[3000]={'\0'};

    scanf("%s", input);

    Solution(input);

    return 0;
}