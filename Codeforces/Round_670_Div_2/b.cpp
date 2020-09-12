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
ll arr[100000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		sort(arr,arr+n);
		ll ans = -987654321987654321;
		for(int i = 0;i<6;i++){
			ll tmp = 1;
			for(int j = 0;j<i;j++){
				tmp *= arr[j];
			}
			for(int j = 0;j<5-i;j++){
				tmp *= arr[n-1-j];
			}
			ans = max(ans,tmp);
		}
		printf("%lld\n",ans);
	}
}