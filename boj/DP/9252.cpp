#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];
char s1[1001];
char s2[1001];
stack<char> ans;
int main() {
	scanf("%s %s", s1, s2);
	int n = strlen(s1);
	int m = strlen(s2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				arr[i + 1][j + 1] = 1;
			}
			else if (dp[i][j+1] < dp[i+1][j]) {
				dp[i + 1][j + 1] = dp[i + 1][j];
				arr[i + 1][j + 1] = 2;
			}
			else {
				dp[i + 1][j + 1] = dp[i][j + 1];
				arr[i + 1][j + 1] = 3;
			}
		}
	}
	printf("%d\n", dp[n][m]);
	int x = n, y = m;
	while (x > 0 && y > 0) {
		if (arr[x][y] == 1) {
			x--;
			y--;
			ans.push(s1[x]);
		}
		else if (arr[x][y] == 2)
			y--;
		else if (arr[x][y] == 3)
			x--;
	}
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");
}