#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 9876543987654321
using namespace std;
typedef long long ll;
ll f(ll n){
	if(n==1) return 0;
	if(n == 2) return 1;
	if(n<1) return INF;
	ll ret = n-1;
	long double a,b,c;
	ll ci,fl;
	for(int i = 59;i>=2;i--){
		a = powl(n,1/(double)i);
		fl = (ll)floor(a);
		ci = (ll)ceil(a);
		c = powl(fl,i);
		b = powl(ci,i);
		if(c<=n) ret = min(ret,f(fl)-(ll)c+n+1);
		else ret = min(ret,f(fl)-n+(ll)c+1);
		if(b>=n) ret = min(ret,f(ci)-n+(ll)b+1);	
		else ret = min(ret,f(ci)-(ll)b+n+1);
	}
	return ret;
}
int main(){
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",f(n));
}