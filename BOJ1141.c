#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int static compare(const void *a, const void *b)
{
    char *temp_a=(char *)a;
    char *temp_b=(char *)b; 
    int a_len=strlen(temp_a);
    int b_len=strlen(temp_b);

    if (a_len > b_len)
        return 1;
    else if (a_len < b_len)
        return -1;
    else 
        return 0;
}

void PrintList(char list[][100], int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%3s\n", list[i]);
    }
    printf("\n");
}

int MatchWord(char list[][100], char rule[], int start, int n)
{
    int result=0;

    for(int i=start+1; i<n; i++)
    {
        if (strncmp(rule,list[i],strlen(rule))==0)
        {
            result+=1;
            break;
        }
    }

    return result;
}

void Solution(char list[][100], int n)
{
    qsort(list,n,sizeof(char)*100,compare);
    //PrintList(list,n);
    int answer=1; 
    int temp=0;

    for(int i=0; i<n-1; i++)
    {
        temp=MatchWord(list,list[i],i,n);

        /*if (temp>=2)
        {
            answer-=temp;
            answer+=1;
        }
        else 
        {
            answer-=temp;
        }*/

        if (temp==0)
            answer+=1;
    }

    if (answer<0)
    {
        printf("%d\n",1);
        return;
    }

    printf("%d\n",answer);
}

int main(void)
{
    int n=0; char ch=' ';
    char list[100][100]={'\0'};

    scanf("%d%c", &n, &ch);

    for(int i=0; i<n; i++)
    {
        fgets(list[i],100,stdin);
        list[i][strlen(list[i])-1]='\0';
    }

    //PrintList(list,n);
    Solution(list,n);

    return 0;
}