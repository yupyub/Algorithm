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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,r;
		scanf("%lld %lld",&n,&r);
		ll ans;
		if(n<=r){
			n--;
			ans = (n*(n+1))/2+1;
		}
		else
			ans = (r*(r+1))/2;
		printf("%lld\n",ans);
	}
}