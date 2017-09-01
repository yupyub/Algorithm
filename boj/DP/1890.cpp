#include <stdio.h>
int arr[100][100];
int dp[100][100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &arr[i][j]);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j])
				continue;
			int ii = i + arr[i][j];
			int jj = j + arr[i][j];
			if (ii < n) 
				dp[ii][j] += dp[i][j];
			if (jj < n)
				dp[i][jj] += dp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", dp[n - 1][n - 1]);
}