#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int num[10001];
int visit[10001];
int arr[10001][3];
vector<int>g[10001];
void gdfs(int n) {
	if (visit[n])
		return;
	visit[n] = 1;
	if (1 == g[n].size() && visit[g[n][0]]) {
		arr[n][0] = num[n];
		//return;
	}
	else {
		int mindis = 987654321;
		int ch = 0;
		arr[n][0] = num[n];
		for (int i = 0; i < g[n].size(); i++) {
			if (visit[g[n][i]])
				continue;
			gdfs(g[n][i]);
			arr[n][0] += max(arr[g[n][i]][1], arr[g[n][i]][2]);

			if (arr[g[n][i]][0] >= arr[g[n][i]][1]) {
				arr[n][1] += arr[g[n][i]][0];
				ch = 1;
			}
			else {
				arr[n][1] += arr[g[n][i]][1];
				mindis = min(mindis, arr[g[n][i]][1] - arr[g[n][i]][0]);
			}

			arr[n][2] += arr[g[n][i]][1];
		}
		if (!ch)
			arr[n][1] -= mindis;
	}
	//printf("%d: %d %d %d\n",n, arr[n][0], arr[n][1], arr[n][2]);
}


int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	gdfs(1);
	int ans = 0;
	for (int i = 0; i < 3; i++)
		ans = max(ans, arr[1][i]);
	printf("%d\n", ans);
}