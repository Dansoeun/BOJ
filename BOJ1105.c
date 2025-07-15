#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. 문자열로 숫자 l,r 입력 받음
2. l,r 길이가 같은지 , 큰지 판단 
3. l<r:  r의 첫 인덱스가 8인지 판단, l이 8포함되는지 판단 
4. l=r: l이 8 포함 되는지 중용
4. 각 인덱스마다(자릿수마다) l이 8보다 큰지 판단 -> 작으면 0
*/

void Solution(char left[], char right[])
{
    int r_len=strlen(right);
    int l_len=strlen(left);
    int answer=0;

    if (r_len!=l_len)
    {
        printf("%d\n",0);
        return;
    }
    else 
    {
        for(int i=0; i<r_len; i++)
        {
            if (left[i]==right[i])
            {
                if (left[i]=='8')
                    answer+=1;
            }
            else
                break;
        }
    }

    /*
    for(int i=0; i<r_len; i++)
    {
        if (r_len-i >l_len) //right 수가 아직 더 큰 경우 
        {
            printf("%d\n",0);
            break; // 8절대 안됑..
        }
        else //탐색 인덱스가 같은 경우 
        {
            l_index=left[r_len-l_len+i]-'0';
            r_index=right[i]-'0';

            //printf("i:%d l_index:%d r_index:%d\n", i, l_index, r_index);

            if (l_index==8 && r_index==8 && r_prev==l_prev)
            {
                answer+=1;
            }

            l_prev=l_index;
            r_prev=r_index;

        }
    }*/


    printf("%d\n",answer);
}

/*
2,000,000,000
*/
int main(void)
{
    char left[2000001]={'\0'};
    char right[2000001]={'\0'};

    scanf("%s %s", left, right);
    getchar();

    //printf("input left: %s right:%s, l_len:%ld right_len:%ld \n",left,right,strlen(left),strlen(right));

    Solution(left,right);

    return 0;
}