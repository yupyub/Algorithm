#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;
vector<pair<int, int> >g[1001];
int parent[1001];
int dist[1001];

void dijk(int s) {
	priority_queue<pair<int, int> >pq;
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (int i = 0; i < g[x].size(); i++) {
			if (dist[g[x][i].first]>dist[x] + g[x][i].second) {
				dist[g[x][i].first] = dist[x] + g[x][i].second;
				parent[g[x][i].first] = x;
				pq.push(make_pair(-dist[g[x][i].first], g[x][i].first));
			}
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	int a, b,c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	dijk(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i])
			ans++;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (parent[i])
			printf("%d %d\n", i, parent[i]);
	}
}