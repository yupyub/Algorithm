#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <functional>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
using namespace std;
#define CINOUT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF INT_MAX/2-1
typedef long long ll;
int dp[5001][5001];
int pos[5001][5001];
int main() {
	int N;
	int X, Y;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	int Xi[51];
	int Yi[51];
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &Xi[i], &Yi[i]);
	}
	for (int i = 0; i <= 5000; i++)
		for (int j = 0; j <= 5000; j++) {
			dp[i][j] = 64;
			pos[i][j] = 64;
		}
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int x = 500; x >= Xi[i]; x--) {
			for (int y = 500; y >= Yi[i]; y--) {
				if (dp[x][y] > dp[x - Xi[i]][y - Yi[i]] + 1)
					pos[x][y] = i;
				dp[x][y] = min(dp[x][y], dp[x - Xi[i]][y - Yi[i]] + 1);
			}
		}
	}
	int ans = INF;
	int last = 0;
	for (int i = X; i <= 5000; i++) {
		for (int j = Y; j <= 5000; j++) {
			if (dp[i][j] < ans) {
				ans = dp[i][j];
				last = pos[i][j];
			}
			else if (dp[i][j] == ans)
				last = min(last, pos[i][j]);
		}
	}
	if(ans > 50)
		printf("-1");
	else
		printf("%d\n%d", ans, last);
	return 0;
}