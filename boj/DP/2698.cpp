#include <cstdio>
int dp[101][101][2];
int main(){
	dp[1][0][1] = dp[1][0][0] = 1;
	for(int i = 2;i<101;i++){
		for(int j = 0;j<101;j++){
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%d\n",dp[n][m][0]+dp[n][m][1]);
	}
}
	