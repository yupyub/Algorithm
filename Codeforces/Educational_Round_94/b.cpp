#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
ll f(ll P,ll F,ll cntS,ll cntW,ll S,ll W){
	ll ans = 0;
	for(int i = 0;i<=cntS;i++){
		ll cnt = i;
		ll tmpP = P;
		ll tmpF = F;
		if(i*S<=tmpP){
			tmpP -= i*S;
			ll tmp = tmpP/W > cntW ? cntW : tmpP/W;
			cnt += tmp;
			ll tmp1 = tmpF/S > (cntS-i) ? (cntS-i) : tmpF/S;
			tmpF -= tmp1*S;
			cnt += tmp1;
			ll tmp2 = tmpF/W > (cntW-tmp) ? (cntW-tmp) : tmpF/W;
			cnt += tmp2;
		}
		else cnt = -1;
		//printf(">> %d %d\n",i,cnt);
		ans = max(ans,cnt);
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll P,F,cntS,cntW,S,W;
		scanf("%lld %lld %lld %lld %lld %lld",&P,&F,&cntS,&cntW,&S,&W);
		ll ans1,ans2;
		if(S<W)
			ans1 = f(P,F,cntS,cntW,S,W);
		else
			ans1 = f(P,F,cntW,cntS,W,S);
		if(S<W)
			ans2 = f(F,P,cntS,cntW,S,W);
		else
			ans2 = f(F,P,cntW,cntS,W,S);
		printf("%lld\n",max(ans1,ans2));
	}
}