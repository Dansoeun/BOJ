#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. 단순 배열 원소 추가 .. ? 
2. 리스트에 원소 추가해서 해야할듯 
*/
typedef struct Dpair
{
    char pair[100];
    int inter;
    struct Dpair *next;
}Dpair;

Dpair* makepair(char input[], int inter)
{
    Dpair *newpair=(Dpair *)malloc(sizeof(Dpair));
    strcpy(newpair->pair,input);
    newpair->next=NULL;
    newpair->inter=inter;

    return newpair;
}

int Insert(Dpair** list, char input[], int inter)
{
    Dpair *temp = *list;

    while (temp != NULL)
    {
        if (strcmp(temp->pair, input) == 0 && temp->inter == inter)
            return 0;  // 중복 발견
        temp = temp->next;
    }

    // 중복이 없으므로 새 노드 삽입
    Dpair *newpair = makepair(input, inter);
    newpair->next = *list;
    *list = newpair;
    return 1;
}

void Solution(char input[])
{
    int len=strlen(input);
    int interval=1;
    char compose[100]={'\0'};
    char start=' ';
    char next=' ';
    int res=0;
    int j=0;
    Dpair* list=NULL;

    if (len<4)
    {
        printf("%s is surprising.\n", input);
        return;
    }

    //i가 interval 역할 
    while (interval<len-1)
    {
        for(int j=0; j<len; j++)
        {
            start=input[j];
            compose[0]=start;

            if (j+interval>=len)
                break;
            else 
            {
                next=input[j+interval];
                compose[1]=next;
                res=Insert(&list,compose,interval);
                //printf("compose:%s res:%d interval:%d\n",compose,res,interval);

                if (res==0)
                {
                    printf("%s is NOT surprising.\n",input);
                    return;
                }

            }

        }
        interval+=1;
    }

    printf("%s is surprising.\n", input);
    free(list);
}

int main(void)
{
    char input[100]={'\0'};

    while (strcmp(input,"*")!=0)
    {
        scanf("%s", input);

        if (strcmp(input,"*")==0)
        {
            break;
        }
        Solution(input);
    }
    return 0;
}