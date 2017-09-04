#include <stdio.h>
#include <algorithm>
using namespace std;
long long MOD = 1000000007;
long long dp[102][102][102];
int main() {
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	dp[1][1][1] = 1;
	dp[2][1][2] = 1;
	dp[2][2][1] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= min(i, l); j++) {
			for (int k = 1; k <= min(i, r); k++) {
				dp[i][j][k] += dp[i - 1][j - 1][k];
				dp[i][j][k] += dp[i - 1][j][k - 1];
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
				dp[i][j][k] %= MOD;
			}
		}
	}
	printf("%lld\n", dp[n][l][r] % MOD);
}