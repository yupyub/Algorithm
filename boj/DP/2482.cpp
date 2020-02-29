#include <cstdio>
int dp[1001][1001];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i<=n;i++){
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 2;j<=i;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-2][j-1])%1000000003;
		}
	}
	printf("%d\n",(dp[n-3][k-1]+dp[n-1][k])%1000000003);
}