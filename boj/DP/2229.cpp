#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	int point[1000];
	for (int i = 0; i < N; i++)
		scanf("%d", &point[i]);
	int dp[1000] = { 0, };
	for (int i = 1; i < N; i++) {
		int mini = 10001;
		int maxi = 0;
		for (int j = 0; j < i; j++) {
			mini = min(mini, point[i - j]);
			maxi = max(maxi, point[i - j]);
			dp[i] = max(dp[i], dp[i - j - 1] + maxi - mini);
		}
		mini = min(mini, point[0]);
		maxi = max(maxi, point[0]);
		dp[i] = max(dp[i], maxi - mini);
	}
	printf("%d\n", dp[N - 1]);
	return 0;
}