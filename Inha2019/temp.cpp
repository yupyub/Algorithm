#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
//구간업데이트 아님, min이나 max쓸땐 주석을 참고하자.
const int MAXN = 100001;
long long a[MAXN * 4]; // 4*MAXN

void update(long long idx, long long v, long long a[]){
	a[idx]=v;
	while(idx!=1){
		idx/=2;
		a[idx]=a[idx*2]+a[idx*2+1];
		// a[idx] = min( a[idx*2], a[idx*2+1] );
	}
}

long long sum(long long l, long long r, long long a[]){
	long long ret=0; // ret = -INF
	while(l<=r){
		if(l%2==0) l/=2;
		else{
			ret+=a[l]; // ret = min( ret, a[l] );
			l=l/2+1;
		}
		if(r%2==0){
			ret+=a[r]; // ret = min( ret, a[r] );
			r=r/2-1;
		} else r/=2;
	}
	return ret;
}

int main(){
	long long n, q, t=1, x, y, b, c, i;
	scanf("%lld %lld", &n, &q);
	while(n>t)
		t*=2;
	for(i=t; i<n+t; i++)
		scanf("%lld", a+i);

	for(i=t; i<2*t; i++)
		update(i, a[i], a);

	for(i=0; i<q; i++){
		scanf("%lld %lld %lld %lld", &x, &y, &b, &c);
		if(x>y)swap(x, y);
		if(x<1)x=1;if(y<1)y=1;
		if(y>n)y=n;if(x>n)x=n;
		printf("%lld\n", sum(t+x-1, t+y-1, a));
		update(t+b-1, c, a);
	}
}
