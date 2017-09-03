#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[40000];
	int dp[40000];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
}