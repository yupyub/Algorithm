#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[40000];
	int dp[40000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 987654321;
	}
	for (int i = 0; i < n; i++)
		(*lower_bound(dp, dp + n, arr[i])) = arr[i];
	printf("%d\n", (int)(lower_bound(dp, dp + n, 987654321) - dp));
}