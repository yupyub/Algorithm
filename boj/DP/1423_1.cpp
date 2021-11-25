#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int characters[50];
int powers[50];
int dp[101][51][101];
int solve(int N, int x, int y, int z) {
	if (y == N - 1)
		return 0;
	int& ret = dp[x][y][z];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= z + characters[y] && i <= x; i++)
		ret = max(ret, solve(N, x - i, y + 1, i) + (powers[y + 1] - powers[y]) * i);
	return ret;
}
int main() {
	int N, D;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &characters[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &powers[i]);
	scanf("%d", &D);
	long long tot = 0;
	for (int i = 0; i < N; i++)
		tot += (long long)characters[i] * powers[i];
	memset(dp, -1, sizeof(dp));
	printf("%lld", tot + (long long)solve(N, D, 0, 0));
	return 0;
}