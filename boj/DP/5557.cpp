#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[101][21];
int arr[101];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0][arr[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			int np = j + arr[i];
			int nm = j - arr[i];
			if (0 <= np && np <= 20)
				if (dp[i - 1][j] != 0)
					dp[i][np] += dp[i - 1][j];
			if (0 <= nm && nm <= 20)
				if (dp[i - 1][j] != 0)
					dp[i][nm] += dp[i - 1][j];
		}
	}
	printf("%lld\n", dp[n - 2][arr[n - 1]]);
}