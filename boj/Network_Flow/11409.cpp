// MCMF_SPFA_by_Dijkstra & List
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 803;
const int INF = 987654321;
int source = 0;
int mid = 401;
int sink = 802;
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
int parent[MAXN];
int dist[MAXN];
vector<int> g[MAXN];
bool dijkstra(int s,int e) {
	priority_queue<pair<int, int> >pq;
	parent[s] = 0;
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int n = pq.top().second;
		pq.pop();
		for (int i : g[n]) {
			if (flow[n][i] > 0) {
				if (dist[i] > dist[n] + cost[n][i]) {
					dist[i] = dist[n] + cost[n][i];
					parent[i] = n;
					pq.push(make_pair(-dist[i], i));
				}
			}
		}
	}
	if (dist[e] == INF)
		return 0;
	else
		return 1;
}
int update(int source, int sink, int* ansc) {
	int amt = INF, s = sink;
	while (s > 0) {
		amt = min(amt, flow[parent[s]][s]);
		s = parent[s];
	}
	s = sink;
	while (s > 0) {
		(*ansc) += amt*cost[parent[s]][s];
		flow[parent[s]][s] -= amt;
		flow[s][parent[s]] += amt;
		s = parent[s];
	}
	return amt;
}
int main() {
	int n, m;
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		flow[source][i] = 1;
		g[source].push_back(i);
		g[i].push_back(source);
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d %d", &b, &c);
			g[i].push_back(mid+b);
			g[mid+b].push_back(i);
			flow[i][mid + b] = 1;
			cost[i][mid + b] = -c;
			cost[mid + b][i] = c;
		}
	}
	for (int i = 1; i <= m; i++) {
		g[sink].push_back(mid+i);
		g[mid+i].push_back(sink);
		flow[mid + i][sink] = 1;
	}

	int ansf = 0;
	int ansc = 0;
	while (1) {
		fill(dist, dist + MAXN, INF);
		fill(parent, parent + MAXN, -1);
		if (dijkstra(source, sink)) 
			ansf += update(source, sink,&ansc);
		else 
			break;
	}
	printf("%d\n%d\n", ansf, -ansc);
}