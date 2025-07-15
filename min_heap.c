#include <stdio.h>
#define MAX_SIZE 1001

typedef struct 
{
    int heap[MAX_SIZE];
    int size;
}Heap;

void min_heap_insert(Heap *h, int item)
{
    h->size+=1;
    int i=h->size; //마지막 위치에서 +1

    /*루트노드가 아니고, 삽입할 값이 적절한 위치를 찾을 때까지 */
    while ((i!=1) && item<h->heap[i/2])
    {
        h->heap[i]=h->heap[i/2]; /*자식노드와 부모노드 교환환*/
        i/=2; /*한 레벨 위로 */
    }

    h->heap[i]=item; //새로운 노드 삽입 
}

int min_heap_delete(Heap *h)
{
    int result=h->heap[1];
    int temp=h->heap[h->size];
    h->size-=1;

    int parent=1;
    int child=2;

    while (child<=h->size)
    {
        /*왼쪽 자식과 오른쪽 자식 중 더 작은 노드 */
        if (child<h->size && h->heap[child] > h->heap[child+1])
        {
            child+=1;
        }

        /*마지막 노드가 자식보다 작으면 종료*/
        if (temp<h->heap[child])
            break;

        /*부모 노드와 자식 노드 교환*/
        h->heap[parent]=h->heap[child];
        /*한 레벨 아래로 이동동*/
        parent=child;
        child*=2;
    }

    /*마지막 노드를 재설정한 위치에 삽입*/
    h->heap[parent]=temp;

    return result;
}