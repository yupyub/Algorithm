#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, double> > >g;
pair<double, double> pos[100];
bool visit[100];
double prim(int n) {
	priority_queue<pair<double, int> >pq;
	pq.push(make_pair(0, 0));
	double ans = 0;
	while (!pq.empty()) {
		int nn = pq.top().second;
		double dist = pq.top().first;
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
double dist(int a, int b) {
	double x = pos[a].first - pos[b].first;
	double y = pos[a].second - pos[b].second;
	return sqrt(x*x + y*y);
}
int main() {
	int n;
	scanf("%d", &n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &pos[i].first, &pos[i].second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double d = dist(i, j);
			g[i].push_back(make_pair(j, d));
			g[j].push_back(make_pair(i, d));
		}
	}
	double ans = prim(n);
	if ((int)(ans * 100 + 0.5) == (int)(ans * 100)) {
		printf("%.2lf\n", ans);
	}
	else {
		ans += 0.005;
		printf("%.2lf", ans);
	}
}