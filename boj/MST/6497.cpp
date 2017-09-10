#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int> > >g;
bool visit[200000];
int prim(int n) {
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, 0));
	int ans = 0;
	while (!pq.empty()) {
		int nn = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (!visit[nn]) {
			visit[nn] = 1;
			ans -= dist;
			for (int i = 0; i < g[nn].size(); i++) {
				pq.push(make_pair(-g[nn][i].second, g[nn][i].first));
			}
		}
	}
	return ans;
}
int main() {
	while (1) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (!n && !m)
			break;
		g.clear();
		g.resize(n);
		int a, b, c,ans = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			ans += c;
			g[a].push_back(make_pair(b, c));
			g[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < n; i++)
			visit[i] = 0;
		printf("%d\n",ans - prim(n));
	}
}