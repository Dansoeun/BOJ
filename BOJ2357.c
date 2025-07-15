#include <stdio.h>
#define MAX_NUM 1000000005
#define MIN_NUM -1
typedef long long int ll;

ll a[100005];
ll min_tree[4000000];
ll max_tree[4000000];

ll Min(ll t, ll u)
{
	if (t<u)
		return t;
	else 
		return u;
}

ll Max(ll t, ll u)
{
	if (t<u)
		return u;
	else 
		return t;
}

//트리 초기화
ll Min_init(int s, int e, int node)
{
	if (s==e)
		return min_tree[node]=a[s];
	int mid=(s+e)/2;

	return min_tree[node]=Min(Min_init(s,mid,node*2),Min_init(mid+1,e,node*2+1));
}

ll Max_init(int s, int e, int node)
{
	if (s==e)
		return max_tree[node]=a[s];
	
	int mid=(s+e)/2;

	return max_tree[node]=Max(Max_init(s,mid,node*2), Max_init(mid+1,e,node*2+1));

}

//최솟값 구하기
ll QueryMin(int s, int e, int node, int l, int r)
{
	if (s>r || e<l)
		return MAX_NUM;
	if (l<=s && e<=r)
		return min_tree[node];
	
	int mid=(s+e)/2;

	return Min(QueryMin(s,mid,node*2,l,r), QueryMin(mid+1,e,node*2+1,l,r));
}

ll QueryMax(int s, int e, int node, int l, int r)
{
	if (s>r || e<l)
		return MIN_NUM;
	if (l<=s && e<=r)
		return max_tree[node];

	int mid=(s+e)/2; 

	return Max(QueryMax(s,mid,node*2,l,r), QueryMax(mid+1,e,node*2+1,l,r));
}



int main(void)
{
	int n=0; int m=0; int k=0; char ch=' ';
	ll b=0; ll c=0;
	scanf("%d %d %c", &n, &m, &ch);
	ll min_n=0;
	ll max_n=0;

	for(int i=0; i<n; i++)
	{
		scanf("%lld%c", &a[i], &ch);
	}
	Min_init(0,n-1,1);
	Max_init(0,n-1,1);

	for(int i=0; i<m; i++)
	{
		scanf("%lld %lld%c", &b, &c, &ch);
		min_n=QueryMin(0,n-1,1,b-1,c-1);
		max_n=QueryMax(0,n-1,1,b-1,c-1);

		printf("%lld %lld\n", min_n, max_n);
	}

	return 0;


}


