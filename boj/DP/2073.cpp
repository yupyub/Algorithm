#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
int main() {
	int D, P;
	scanf("%d %d", &D, &P);
	ll length[350];
	ll capacity[350];
	for (int i = 0; i < P; i++)
		scanf("%lld %lld", &length[i], &capacity[i]);
	ll dp[100001] = { 0, };
	dp[0] = LLONG_MAX;
	for (int i = 0; i < P; i++)
		for (int j = D; j >= length[i]; j--)
			dp[j] = max(dp[j], min(dp[j - length[i]], capacity[i]));
	printf("%lld", dp[D]);
	return 0;
}