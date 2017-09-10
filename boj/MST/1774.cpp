#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
pair<ll, ll> pos[1000];
bool visit[1000];
bool gexist[1000][1000];
priority_queue<pair<double, int> >pq;
vector<pair<double,int> >g[1000];
double INF = 7654321;
double dist(int a, int b) {
	ll x = pos[a].first - pos[b].first;
	ll y = pos[a].second - pos[b].second;
	return sqrt(x*x + y*y);
}
double sol() {
	double ans = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int n = pq.top().second;
		double ddd = pq.top().first;
		pq.pop();
		if (visit[n])
			continue;
		ans -= ddd;
		visit[n] = 1;
		for (int i = 0; i < g[n].size(); i++) {
			int nn = g[n][i].second;
			double dd = g[n][i].first;
			pq.push(make_pair(-dd, nn));
		}
	}
	return ans;
}
int main() {
	int n, m;
	ll a, b;
	int c, d;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		pos[i] = make_pair(a, b);
	}
	for (int j = 0; j < m; j++) {
		scanf("%d %d", &c, &d);
		gexist[c-1][d-1] = 1;
		gexist[d-1][c-1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (gexist[i][j]) {
				g[i].push_back(make_pair(0, j));
				g[j].push_back(make_pair(0, i));
			}
			else {
				double dd = dist(i, j);
				g[i].push_back(make_pair(dd, j));
				g[j].push_back(make_pair(dd, i));
			}
		}
	}
	printf("%.2lf\n", sol());
}