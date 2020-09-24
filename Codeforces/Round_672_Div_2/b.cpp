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
ll arr[100000];
ll cnt[35];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int j = 0;j<31;j++)
			cnt[j] = 0;
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%lld",&arr[i]);
			for(int j = 0;j<31;j++){
				if(arr[i] < (1<<j)){
					cnt[j]++;
					break;
				}
			}
		}
		ll ans = 0;
		for(int j = 0;j<31;j++)
			ans += (cnt[j]*(cnt[j]-1)) / 2;
		printf("%lld\n",ans);
	}
}