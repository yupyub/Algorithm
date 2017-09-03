#include <stdio.h>
#include <string.h>

int dp[10001][101];
int cost[100];
int num[100];
int t, k;
int sol(int c, int n) {
	//printf(">> %d %d\n", c, n);
	if (c == t)
		return 1;
	else if (c > t)
		return 0;
	else if (n >= k)
		return 0;
	if (dp[c][n] != -1)
		return dp[c][n];
	dp[c][n] = 0;
	for (int i = 0; i <= num[n]; i++) {
		dp[c][n] += sol(c + cost[n] * i, n + 1);
	}
	return dp[c][n];
}

int main() {
	scanf("%d %d", &t, &k);
	for (int i = 0; i < k; i++)
		scanf("%d %d", &cost[i], &num[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n",sol(0, 0));
}