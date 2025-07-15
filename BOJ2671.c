#include <stdio.h>
#include <string.h>
#include <ctype.h>

//100+1+
int State1(char input[], int start)
{
    //100+1+
    int idx=1;
    int idx2=0;
    char prev='1';
    int cnt=0;
    //printf("\nstate1\n");

    for(int i=start+1; i<strlen(input); i++)
    {
        cnt+=1;
        //printf("i:%d cur_char:%c idx:%d idx2:%d\n",i,input[i],idx,idx2);
        if (input[i]=='0' && idx==1 && idx2==0) //10
        {
            idx+=1;
            continue;
        }

        else if (input[i]=='0' && idx>1 && idx2==0) //100+
        {
            idx+=1;
            continue;
        }

        else if (input[i]=='1' && idx>2) //100+1+
        {
            idx2+=1;
        }

        else if (input[i]=='0' && idx>2 && idx2>=1)
        {
            return i; //완료되었으니, 마지막 지점 반환 
        }

        else 
            return -1; //error

    }

    if (idx>=2 && idx2>=1)
        return 0;
    else 
        return -1;

}

//01
int State2(char input[], int start)
{
    int flag2=0;
    int idx=0;

    if (input[start+1]=='1' && input[start]=='0')
    {
        return (2); //01, 다음 것
    }
    else 
    {
        return -1;
    }

}

void RE(char input[])
{
    int flag1=0; //100+1+
    int flag2=0; // 01
    char prev=' ';
    int i=0;

    if (strlen(input)<2)
    {
        printf("NOISE\n");
        return;
    }
    
    while (i<strlen(input))
    {
        //printf("i:%d, strlen:%ld start_char:%c \n",i,strlen(input),input[i]);
        if (input[i]=='1')
        {
            flag1=State1(input,i);

            if (flag1==-1)
            {
                printf("NOISE\n");
                return;
            }

            else if (flag1==0)
            {
                printf("SUBMARINE\n");
                return;
            }

            else if (input[flag1-1]=='1' && input[flag1+1]=='0' && flag1<strlen(input) && input[flag1-2]=='1')
            {
                i=flag1-1;
            }

            else 
            {
                i=flag1;
            }
        }

        else if (input[i]=='0')
        {
            flag2=State2(input,i);

            if (flag2==-1)
            {
                printf("NOISE\n");
                return;
            }

            i+=flag2;
        }
    }

    printf("SUBMARINE\n");
    return;
}

int main(void)
{
    char input[200]={'\0'};

    scanf("%s", input);
    RE(input);

    return 0;
}