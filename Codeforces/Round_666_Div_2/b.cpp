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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
ll arr[100000];
int main(){
	scanf("%d",&N);
	for(int i = 0;i<N;i++)
		scanf("%lld",&arr[i]);
	sort(arr,arr+N);
	ll C = 1;
	ll ans = 987654321987654321;
	while(1){
		int flag = 0;
		ll tmp = 1;
		ll tot = 0;
		for(int i = 0;i<N;i++){
			if(tmp>(100000000000000)){
				flag = 1;
				break;
			}
			tot += abs(arr[i]-tmp);
			tmp *= C;
		}
		//printf("%lld %lld %lld %d\n",C,tot,tmp,flag);
		if(flag)
			break;
		ans = min(ans,tot);
		C++;
	}
	printf("%lld\n",ans);
}