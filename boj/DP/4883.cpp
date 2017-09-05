#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[100000][3];
int main() {
	int t = 1;
	while (1) {
		int n, a;
		scanf("%d", &n);
		if (n == 0)
			break;
		dp[0][0] = 987654321;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a);
			if (j == 1) {
				dp[0][1] = a;
				dp[0][2] = a;
			}
			else if (j == 2) {
				dp[0][2] += a;
			}
		}
		for (int i = 1; i < n; i++) {
			scanf("%d", &dp[i][0]);
			dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
			scanf("%d", &dp[i][1]);
			dp[i][1] += min(min(dp[i][0], dp[i - 1][2]), min(dp[i - 1][0], dp[i - 1][1]));
			scanf("%d", &dp[i][2]);
			dp[i][2] += min(dp[i][1], min(dp[i - 1][2], dp[i - 1][1]));
		}
		printf("%d. %d\n", t, dp[n - 1][1]);
		t++;
	}
}