#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1000][1000];
int main() {
	while (1) {
		int N, M, a;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
				dp[i][j] = 0;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &a);
				if (a) {
					if (i <= 0 || j <= 0)
						dp[i][j] = 1;
					else
						dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}