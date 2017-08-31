#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[2001][2001];
int A[2001];
int B[2001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1)
				continue;
			if (A[i] > B[j])
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + B[j]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, dp[i][n]);
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
}