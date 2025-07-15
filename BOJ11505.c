#include <stdio.h>
#define NUMBER 1000003
#define MOD 1000000007

typedef long long ll;

ll a[NUMBER]={0};
ll tree[4*NUMBER]={0};

//start: 시작 인덱스, end: 끝 인덱스
ll init(int start, int end, int node)
{
    if (start==end)
        return tree[node]=a[start];
    
    int mid=(start+end)/2;

    //재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 함
    //return tree[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
    return tree[node]=((init(start,mid,node*2)%MOD)*(init(mid+1, end ,node*2+1))%MOD);
}

//start:시작 인덱스, end: 끝 인덱스
//index: 구간 합을 수정하고자 하는 노드
//val:수정할 값 
ll update(int node, int start, int end, int index, ll val)
{
    if (index<start || index > end)
        return tree[node];

    if (start==end)
    {
        return tree[node]=val;
    }

    int mid=(start+end)/2;

    return tree[node]=((update(node*2,start,mid,index,val)%MOD)*(update(node*2+1,mid+1,end,index,val)%MOD));
}

//start: 시작 인덱스, end: 끝 인덱스
//left, right: 구간 합을 구하고자 하는 범위
ll Calculate(int node, int start, int end, int left, int right)
{
    if (right<start || end<left)
        return 1;
    
    if (left<=start && end<=right)
        return tree[node];
    
    int mid=(start+end)/2;
    ll left_child=Calculate(node*2,start,mid,left,right);
    ll right_child=Calculate(node*2+1,mid+1,end,left,right);

    return ((left_child*right_child))%MOD;
}

void Print(int t)
{
    printf("tree\n");
    for(int i=1; i<t; i++)
    {
        printf("tree[%d]:%lld\n",i,tree[i]);
    }
}

int main(void)
{
    //구간 합 트리 생성
    int n=0; int m=0; int k=0; char ch=' ';
    ll s=0; ll b=0; ll c=0;
    ll result=0;

    scanf("%d %d %d%c",&n, &m, &k, &ch);

    for(int i=1;i<=n; i++)
    {
        scanf("%lld%c", &a[i], &ch);
    }

    //구간합 트리 생성
    init(1,n,1);
    //Print(t);

    for(int i=0; i<m+k; i++)
    {
        scanf("%lld %lld %lld%c",&s, &b, &c, &ch);

        if (s==1)
        {
            a[b]=c;
            update(1,1,n,b,c);
        }
        else if (s==2)
        {
            result=Calculate(1,1,n,b,c);
            printf("%lld\n",result);
        }
    }

    return 0;
}