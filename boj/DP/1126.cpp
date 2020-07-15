#include <cstdio>
#include <algorithm>
using namespace std;
int blk[500001];
int dp[51][500001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&blk[i]);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<=250000;j++)
			dp[i][j] = -1;
	dp[0][0] = 0;
	dp[0][blk[0]] = blk[0];
	for(int i = 1;i<n;i++){
		for(int k = 0;k<=250000;k++){
			if(dp[i-1][k] == -1) continue; 
			dp[i][k] = max(dp[i][k],dp[i-1][k]);
			dp[i][k+blk[i]] = max(dp[i][k+blk[i]],dp[i-1][k]+blk[i]);
			if(k<blk[i])
				dp[i][blk[i]-k] = max(dp[i][blk[i]-k],dp[i-1][k]+blk[i]-k);
			else
				dp[i][k-blk[i]] = max(dp[i][k-blk[i]],dp[i-1][k]);
		}
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
		ans = max(ans,dp[i][0]);
	if(!ans)
		printf("-1\n");
	else
		printf("%d\n",ans);
}