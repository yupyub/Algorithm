#include <cstdio>
#include <algorithm>
using namespace std;
int dp[10001][502];
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int dist[10001];
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dist[i]);
	}
	for (int i = 1; i <= N; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j < i; j++)
			dp[i][0] = max(dp[i][0], dp[i - j][j]);
		for (int j = 1; j <= min(i, M); j++)
			dp[i][j] = dp[i - 1][j - 1] + dist[i];
	}
	printf("%d", dp[N][0]);
	return 0;
}