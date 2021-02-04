#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <functional>
#include <tuple>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll dp[200001];
int arr[200001];
int n;
ll dfs(int x) {
	if (x >= n)
		return 0;
	if (dp[x] != 0)
		return dp[x];
	return dp[x] = dfs(x + arr[x]) + arr[x];
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			dp[i] = 0;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dfs(i));
		}
		printf("%lld\n", ans);
	}
}
