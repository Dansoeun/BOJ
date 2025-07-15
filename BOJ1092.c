#include <stdio.h>
#include <stdlib.h>

/*
1. 크레인 정렬
2. 박스 정렬
3. 무거운 것부터 크레인 무거운 거대로 집어넣기 
4. 근데 만약에 박스 무게 >크레인 무게 이면 다음 번에 싣기 
*/

static int compare(const void *a, const void *b)
{
    int *temp_a=(int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return 1;
    else if (*temp_a< *temp_b)
        return -1;
    else 
        return 0;
}

void Solution(int crain[], int n, int box[], int m)
{
    int answer=0;
}