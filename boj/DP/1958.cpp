#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[101];
char s2[101];
char s3[101];
int dp[101][101][101];
int main() {
	scanf("%s %s %s", s1, s2, s3);
	int n = strlen(s1);
	int m = strlen(s2);
	int p = strlen(s3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < p; k++) {
				if (s1[i] == s2[j] && s2[j] == s3[k])
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else
					dp[i + 1][j + 1][k + 1] = max(max(dp[i + 1][j][k], max(dp[i][j + 1][k], dp[i][j][k + 1])), max(dp[i + 1][j][k+1], max(dp[i+1][j + 1][k], dp[i][j+1][k + 1])));
			}
		}
	}
	printf("%d\n", dp[n][m][p]);
}