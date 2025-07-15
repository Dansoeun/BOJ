#include <stdio.h>
#include <stdlib.h>

int static compare(const void *a, const void *b)
{
    int *temp_a=(int *)a;
    int *temp_b=(int *)b;

    if (*temp_a > *temp_b)
        return 1;
    else if (*temp_a < *temp_b)
        return -1;
    else 
        return 0;
}

//arr 정렬된 채 사용 
int BinarySearch(int arr[], int start,int end ,int target, int n)
{
    int mid=0;

    while (start<=end)
    {
        mid=(start+end)/2;

        if (arr[mid]==target)
            return mid;
        else if (arr[mid]<target)
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    return -1;

}