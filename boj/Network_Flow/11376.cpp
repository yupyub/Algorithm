#include <stdio.h>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int INF = 98765321;
int f[2003][2003];
int parent[2003];
int source = 0;
int mid = 1001;
int sink = 2002;
bool dfs(int s, int sink) {
	if (s == sink)
		return 1;
	for (int i = 1; i <= sink; i++) {
		if (f[s][i] > 0 && parent[i] == -1) {
			parent[i] = s;
			if (dfs(i, sink)) return 1;
		}
	}
	return 0;
}
int update(int source, int sink) {
	int amt = INF, s = sink;
	while (s > source) {
		amt = min(f[parent[s]][s], amt);
		s = parent[s];
	}
	s = sink;
	while (s > source) {
		f[parent[s]][s] -= amt;
		f[s][parent[s]] += amt;
		s = parent[s];
	}
	return amt;
}
int main() {
	int n, m;
	int a, b;
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		f[source][i] = 2;
	for (int j = 1; j <= m; j++)
		f[mid + j][sink] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			f[i][mid + b] = 1;
		}
	}
	while (1) {
		fill(parent, parent + sink + 1, -1);
		if (dfs(source, sink))
			ans += update(source, sink);
		else break;
	}
	printf("%d\n", ans);
}