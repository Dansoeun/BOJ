#include <stdio.h>
typedef long long int ll;
ll a[1000000];
ll tree[4000000];

ll init(int s, int e, int node) { //트리 초기화
	if(s==e) return tree[node] = a[s];
	int mid = (s+e)/2;
	return tree[node] = init(s, mid, node*2) + init(mid+1, e, node*2+1);
} 

ll sum(int s, int e, int node, int l, int r) { //구간합 구하기
	if(s > r || e < l) return 0;
	if(l<=s && e <= r) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void update(int s, int e, int node, int index, ll dif) { //요소 바꾸기
	if(index < s || index > e) return;
	tree[node] += dif;
	if(s==e) return;
	int mid = (s+e)/2;
	update(s, mid, node*2, index, dif);
	update(mid+1, e, node*2+1, index, dif);
} 

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++) scanf("%lld", &a[i]);
	init(0, n-1, 1); //트리 초기화
	int cnt = m+k;
	while(cnt--) {
		ll b, c, d;
		scanf("%lld %lld %lld", &b, &c, &d);
		if(b==1) { //요소 초기화
			update(0, n-1, 1, c-1, d-a[c-1]); //관련된 트리의 값을 다 바꾼다
			a[c-1] = d; //요소가 바뀌었으니 a도 바꾸어 준다.
		}
		else {
			printf("%lld\n", sum(0, n-1, 1, c-1, d-1)); //구간합을 출력한다.
		}
	}
}