#include <cstdio> // 12865와 같은 knapsack 문제
#include <algorithm>
using namespace std;
int mem[100];
int cost[100];
int dp[10001];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%d",&mem[i]);
	for(int i = 0;i<n;i++)
		scanf("%d",&cost[i]);
	for(int i = 0;i<10001;i++)
		dp[i] = -1;
	dp[0] = 0;
	for(int i = 0;i<n;i++){
		for(int c = 10000;c>=0;c--){
			if(c-cost[i]>=0 && dp[c-cost[i]] != -1)
				dp[c] = max(dp[c-cost[i]]+mem[i],dp[c]);
		}
	}
	int ans = 0;
	for(int i = 0;i<10001;i++){
		if(dp[i]>=m){
			ans = i;
			break;
		}
	}
	printf("%d\n",ans);
}