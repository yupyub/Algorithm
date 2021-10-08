#include <cstdio>
#define MOD 1000000007
typedef long long ll;
ll prob1[100001];
ll prob2[100001];
ll dp[100001][2];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &prob1[i]);
	for (int i = 1; i < N; i++)
		scanf("%lld", &prob2[i]);
	dp[1][0] = prob1[1];
	dp[1][1] = prob2[1];
	for (int i = 1; i < N; i++) {
		dp[i + 1][0] = (prob1[i + 1] * (dp[i][0] + dp[i][1]) + (prob2[i] == 0 ? 0 : prob2[i] - 1) * dp[i][1] + prob2[i] * dp[i][0]) % MOD;
		dp[i + 1][1] = (prob2[i + 1] * (dp[i][0] + dp[i][1])) % MOD;
	}
	printf("%lld", dp[N][0] + dp[N][1]);
	return 0;
}