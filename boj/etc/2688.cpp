#include <cstdio>
long long dp[65][10];
int main(){
	for(int i = 0;i<10;i++)
		dp[1][i] = 1;
	for(int i = 2;i<65;i++)
		for(int j = 0;j<10;j++)
			for(int k = 0;k<=j;k++)
				dp[i][j] += dp[i-1][k];
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		long long ans = 0;
		scanf("%d",&n);
		for(int i = 0;i<10;i++)
			ans += dp[n][i];
		printf("%lld\n",ans);
	}
}