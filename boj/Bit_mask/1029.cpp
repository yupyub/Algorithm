#include <stdio.h>
#include <algorithm>
using namespace std;
int cost[15][15];
int dp[16][10][1 << 16];
int INF = 987654321;
int n;
int sol(int s, int c, int bit) {
	if (dp[s][c][bit] > 1)
		return dp[s][c][bit];
	for (int i = 0; i < n; i++) {
		if (!(bit&(1<<i))) {
			if (c <= cost[s][i]) {
				dp[s][c][bit] = max(dp[s][c][bit],1+sol(i, cost[s][i], bit | (1 << i)));
			}
		}
	}
	if (dp[s][c][bit] == -1)
		dp[s][c][bit] = 1;
	return dp[s][c][bit];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &cost[i][j]);
		}
	}
	for (int i = 0; i <n ; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1 << 16; k++)
				dp[i][j][k] = -1;
		}
	}
	dp[0][0][1 << 0] = 1;
	printf("%d\n",sol(0, 0, 1 << 0));
}