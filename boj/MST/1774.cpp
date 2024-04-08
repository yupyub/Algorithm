#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
pair<int, int> pos[1000];
bool visits[1000];
bool gexist[1000][1000];
priority_queue<pair<ll, int> >pq;
vector<pair<ll,int> >g[1000];
ll dist(int a, int b) {
	ll x = (ll)(pos[a].first - pos[b].first);
	ll y = (ll)(pos[a].second - pos[b].second);
	return x*x + y*y;
}
long double sol() {
	long double ans = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int n = pq.top().second;
		ll ddd = pq.top().first;
		pq.pop();
		if (visits[n])
			continue;
		ans += sqrtl((long double)-ddd);
		visits[n] = 1;
		for (int i = 0; i < g[n].size(); i++) {
			int nn = g[n][i].second;
			if(visits[nn])
				continue;
			ll dd = g[n][i].first;
			pq.push(make_pair(-dd, nn));
		}
	}
	return ans;
}
int main() {
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		pos[i] = make_pair(a, b);
	}
	for (int j = 0; j < m; j++) {
		scanf("%d %d", &a, &b);
		gexist[a-1][b-1] = 1;
		gexist[b-1][a-1] = 1;
	}
	int prev_sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (gexist[i][j]) {
				g[i].push_back(make_pair(0, j));
				g[j].push_back(make_pair(0, i));
			}
			else {
				ll dd = dist(i, j);
				g[i].push_back(make_pair(dd, j));
				g[j].push_back(make_pair(dd, i));
			}
		}
	}
	printf("%.2Lf\n", sol());
}