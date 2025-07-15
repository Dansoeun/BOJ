#include <stdio.h>
#define MAX 500005
/*
1. 문자열 탐색 (동시에 R,B 추적)
2. 오른쪽으로 이동하는 것뿐만 아니라 , 왼쪽으로도 모는 경우를 생각해야됨 
3. 왼쪽->오른쪽 탐색 , 오른쪽으로 밀다가 여태 민 것 , 이제 밀 것 개수 세서 적은 쪽으로 밀기 
4. 두개 비교해서 최솟값 출력 
5. 첫 스타트/마지막 스타트가 탐색하고자 하는 공과 일치하는지 확인 (몰기위함함)
*/

int Min(int a, int b)
{
    if (a<b)
        return a;
    else 
        return b;
}

/*
int RedSolution(char list[], int n)
{
    char prev=list[0];
    int rcount=0;
    int cur_r_cnt=500005;
    int prev_r_cnt=500005;
    int start_rcnt=0;
    int end_rcnt=0;
    int res=0;

    if (prev=='R')
        cur_r_cnt=1;

    for(int i=1; i<n; i++)
    {
        if (list[i]=='R')
        {
            if (cur_r_cnt==500005)
                cur_r_cnt=0;
            cur_r_cnt+=1;
        }

        else if (list[i]!=prev && prev=='R')
        {
            res=Min(prev_r_cnt,cur_r_cnt);

            if (prev_r_cnt==500005)
            {
                prev_r_cnt=0;
                prev_r_cnt=cur_r_cnt;

            }

            if (prev_r_cnt!=res)
                prev_r_cnt+=res;
            
            if (prev_r_cnt==cur_r_cnt)
            
            cur_r_cnt=0;
        }

        printf("i:%d prev_r_cnt:%d cur_r_cnt:%d\n",i,prev_r_cnt,cur_r_cnt);

        prev=list[i];
    }

    printf("r: prev_r:%d cur_r:%d\n", prev_r_cnt, cur_r_cnt);

    if (prev_r_cnt>0 && cur_r_cnt>0)
        res=Min(prev_r_cnt,cur_r_cnt);
    else 
        res=prev_r_cnt;

    //printf("rcount: %d\n",res);

    return res;
}
*/

int RedSolution(char list[], int n, int rtotal)
{
    int sflag=0;
    int eflag=0;
    int start_r=0;
    int end_r=0;
    int res=0;

    if (list[0]=='R')
    {
        sflag=1;

        for(int i=0; i<n; i++)
        {
            if (list[i]=='R')
            {
                start_r+=1;
            }
            else 
                break;
        }
    }

    if (list[n-1]=='R')
    {
        eflag=1;

        for(int i=n-1; i>=0; i--)
        {
            if (list[i]=='R')
            {
                end_r+=1;
            }
            else 
                break;
        }
    }

    //printf("start_r:%d end_r:%d\n",start_r,end_r);
    res=Min(rtotal-start_r,rtotal-end_r);

    return res;
}

int BlueSolution(char list[], int n, int btotal)
{
    int sflag=0;
    int eflag=0;
    int start_b=0;
    int end_b=0;
    int res=0;

    if (list[0]=='B')
    {
        sflag=1;

        for(int i=0; i<n; i++)
        {
            if (list[i]=='B')
                start_b+=1;
            else 
                break;
        }
    }

    if (list[n-1]=='B')
    {
        eflag=1;

        for(int i=n-1; i>=0; i--)
        {
            if (list[i]=='B')
                end_b+=1;
            else 
                break;
        }
    }

    //printf("start_B:%d end:%d\n",start_b,end_b);
    res=Min(btotal-start_b,btotal-end_b);

    return res;
    

}

int main(void)
{
    char list[500005]={'\0'};
    int n=0; char ch=' ';
    int bcount=0;
    int rcount=0;
    int answer=0;
    int rtotal=0;
    int btotal=0;

    scanf("%d%c", &n, &ch);
    scanf("%s", list);

    for(int i=0; i<n; i++)
    {
        if (list[i]=='R')
            rtotal+=1;

        if (list[i]=='B')
            btotal+=1;
    }

    bcount=BlueSolution(list,n,btotal);
    rcount=RedSolution(list,n,rtotal);

    //printf("rcount:%d bcount:%d\n",rcount,bcount);

    answer=Min(bcount,rcount);

    printf("%d\n",answer);
}