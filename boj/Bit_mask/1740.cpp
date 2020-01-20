#include <cstdio>
int main(){
	long long n,ans = 0,a = 1;
	scanf("%lld",&n);
	for(long long i = 1;i<=n;(i<<=1),a*=3)
		ans += ( (n&i)==0? 0:1 )*a;
	printf("%lld\n",ans);
}