#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int> >v[1001];
queue<int>q;
int dist[1001];
int tstart[1001][1001];
int tend[1001][1001];
int INF = 987654321;

int dijk(int s, int e, int st) {
	priority_queue<pair<int, int> >pq;
	dist[s] = st;
	pq.push(make_pair(-dist[s], s));
	while (!pq.empty()) {
		int n = pq.top().second;
		//printf("%d %d\n", n,-pq.top().first);
		pq.pop();
		for (int i = 0; i < v[n].size(); i++) {
			int nn = v[n][i].first;
			int nw = v[n][i].second;
			if (tstart[n][nn] <= dist[n] && dist[n] <= tend[n][nn]) {
				if (dist[nn] > tend[n][nn] + 1 + nw) {
					dist[nn] = tend[n][nn] + 1 + nw;
					pq.push(make_pair(-dist[nn], nn));
				}
			}
			else {
				if (dist[nn] > dist[n] + nw) {
					dist[nn] = dist[n] + nw;
					pq.push(make_pair(-dist[nn], nn));
				}
			}
		}
	}
	return dist[e];
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b, k, g;
	scanf("%d %d %d %d", &a, &b, &k, &g);
	int x;
	for (int i = 0; i < g; i++) {
		scanf("%d", &x);
		q.push(x);
	}
	int y, z;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			tend[i][j] = -1;

	int total = 0;
	int befo = q.front();
	q.pop();
	while (!q.empty()) {
		tstart[befo][q.front()] = total;
		tstart[q.front()][befo] = total;
		for (int i = 0; i < v[befo].size(); i++) {
			if (v[befo][i].first == q.front()) {
				tend[befo][q.front()] = total + (v[befo][i].second) - 1;
				tend[q.front()][befo] = total + (v[befo][i].second) - 1;
				total = total + v[befo][i].second;
				if (!q.empty()) {
					befo = q.front();
					q.pop();
				}
				break;
			}
		}
	}
	/*
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++) {
	printf("<%d, %d> :  (%d %d)\n", i, j, tstart[i][j], tend[i][j]);
	}
	*/
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	printf("%d\n", dijk(a, b, k) - k);
}