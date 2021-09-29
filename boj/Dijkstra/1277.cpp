#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#define INF 987654321
using namespace std;
vector<pair<int, double> > g[1000];
vector<pair<double, double> > pos;
double dist[1000];
int main() {
	int N, W;
	scanf("%d %d", &N, &W);
	double M;
	scanf("%lf", &M);
	double x, y, d;
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &x, &y);
		pos.push_back(make_pair(x, y));
		dist[i] = INF;
	}
	int a, b;
	for (int i = 0; i < W; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		g[a].push_back(make_pair(b, 0.0));
		g[b].push_back(make_pair(a, 0.0));
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			x = pos[i].first - pos[j].first;
			y = pos[i].second - pos[j].second;
			d = sqrt(x * x + y * y);
			if (d <= M) {
				g[i].push_back(make_pair(j, d));
				g[j].push_back(make_pair(i, d));
			}
		}
	}
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
	pq.push(make_pair(0, 0));
	dist[0] = 0;
	while (!pq.empty()) {
		double d = pq.top().first;
		int n = pq.top().second;
		pq.pop();
		for (auto edge : g[n]) {
			int nxt = edge.first;
			double cost = edge.second;
			if (dist[nxt] > dist[n] + cost) {
				dist[nxt] = dist[n] + cost;
				pq.push(make_pair(dist[nxt], nxt));
			}
		}
	}
	printf("%d", (int)(dist[N - 1] * 1000));
}