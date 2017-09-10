#include <stdio.h>
#include <algorithm>
using namespace std;
int cost[16][16];
int dp[17][1 << 17];
int INF = 987654321;
void sol(int cnt,int bit,int n,int p) {
	for (int i = cnt; i < n; i++) {
		int jj = 1 << (n+1);
		for (int j = 0; j < jj; j++) {
			if (dp[i][j] == INF)
				continue;
			for (int k = 0; k < n; k++) {
				if (!(j&(1 << k))) {
					for (int t = 0; t < n; t++) {
						if (j&(1 << t))
							dp[i + 1][j | (1 << k)] = min(dp[i+1][j|(1<<k)],dp[i][j] + cost[t][k]);
					}
				}
			}
		}
	}
}
int find_ans(int n, int p) {
	int jj = 1 << (n + 1);
	int ans = INF;
	for (int i = p; i <= n; i++) {
		for (int j = 0; j < jj; j++)
			ans = min(ans, dp[i][j]);
	}
	if (ans == INF)
		return -1;
	else
		return ans;
}
int main() {
	int n,p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	int bit = 0;
	int cnt = 0;
	char c;
	for (int i = 0; i < n; i++) {
		scanf("\n%c", &c);
		if (c == 'Y') {
			bit = bit | (1 << i);
			cnt++;
		}
	}
	scanf("%d", &p);
	for (int i = 0; i <= n; i++) {
		int jj = 1 << (n+1);
		for (int j = 0; j < jj; j++)
			dp[i][j] = INF;
	}
	dp[cnt][bit] = 0;
	sol(cnt, bit, n, p);
	printf("%d\n",find_ans(n,p));
}