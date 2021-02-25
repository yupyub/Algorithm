#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int arr[200002];
int dp[200002];
int inv[200002];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			dp[i+1] = 0;
			inv[i + 1] = 0;
		}
		for (int i = 1; i < n; i++) {
			if (arr[i] != arr[i - 1])
				dp[arr[i]]++;
		}
		int ans = 987654321;
		for (int i = 1; i <= n; i++) {
			if (dp[i] == 0)
				continue;
			int flag = 0;
			if (arr[n - 1] != i)
				flag = 1;
			if (dp[i] + flag < ans)
				ans = dp[i] + flag;
		}
		for (int i = n-1; i > 0; i--) {
			if (arr[i-1] != arr[i])
				inv[arr[i-1]]++;
		}
		int invans = 987654321;
		for (int i = 1; i <= n; i++) {
			if (inv[i] == 0)
				continue;
			int flag = 0;
			if (arr[0] != i)
				flag = 1;
			if (inv[i] + flag < ans)
				invans = inv[i] + flag;
		}
		if (invans != 987654321) {
			ans = min(invans, ans);
		}
		printf("%d\n", ans == 987654321 ? 0 : ans);
	}
}