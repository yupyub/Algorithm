#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int> > >v;
vector<int> ans;
int dist[2001];
int parent[2001];
int INF = 987654321;

void dijk(int s, int g, int h) {
	priority_queue<pair<pair<int, int>, int> >pq;
	dist[s] = 0;
	parent[s] = -1;
	pq.push(make_pair(make_pair(-dist[s], 0), s));
	while (!pq.empty()) {
		int n = pq.top().second;
		int nc = pq.top().first.second;
		//printf("%d ", n);
		pq.pop();
		for (int i = 0; i < v[n].size(); i++) {
			int nn = v[n][i].first;
			int nw = v[n][i].second;
			//printf(">> %d %d\n", n, nn);
			if (dist[nn] >= dist[n] + nw && ((n == g && nn == h) || (n == h && nn == g))) {
				dist[nn] = dist[n] + nw;
				parent[nn] = n;
				pq.push(make_pair(make_pair(-dist[nn], 1), nn));
			}
			if (dist[nn] > dist[n] + nw) {
				dist[nn] = dist[n] + nw;
				parent[nn] = n;
				pq.push(make_pair(make_pair(-dist[nn], nc), nn));
			}
		}
	}
}

int check(int s, int g, int h) {
	int tmp = parent[s];
	while (tmp != -1) {
		//printf(">> %d %d %d %d\n",g,h, tmp, s);
		if ((tmp == g && s == h) || (tmp == h && s == g))
			return 1;
		s = tmp;
		tmp = parent[s];
	}
	return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, t;
		scanf("%d %d %d", &n, &m, &t);
		int s, g, h;
		scanf("%d %d %d", &s, &g, &h);
		v.resize(n + 1);
		int a, b, d;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			v[a].push_back(make_pair(b, d));
			v[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i <= n; i++) {
			dist[i] = INF;
			parent[i] = -1;
		}
		dijk(s, g, h);
		/*
		for (int i = 1; i <= n; i++) {
		printf("%d:: %d, %d\n", i, parent[i], dist[i]);
		}
		*/
		int c;
		for (int i = 0; i < t; i++) {
			scanf("%d", &c);
			if (check(c, g, h))
				ans.push_back(c);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");

		ans.clear();
		v.clear();
	}
}