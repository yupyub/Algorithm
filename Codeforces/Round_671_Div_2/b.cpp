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
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int ans = 0;
		ll tmp = 0;
		ll n = 1;
		ll x;
		scanf("%lld",&x);
		while(tmp<x){
			tmp += (n*(n+1))/2;
			if(tmp > x)
				break;
			ans++;
			n = 2*n+1;
		}
		printf("%d\n",ans);
	}
}