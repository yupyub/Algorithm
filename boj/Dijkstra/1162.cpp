#include <stdio.h>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
int N, M, K;
vector <vector<pair<int, ll> > > g;
priority_queue<pair<ll, pair<int, int> > >pq;
ll dp[21][10002];
void dijkstra_KK(){
	dp[0][1] = 0;
	pq.push(make_pair(0, make_pair(0, 1)));
	while (!pq.empty()){
		int k = pq.top().second.first;
		int u = pq.top().second.second;
		ll w = -pq.top().first;
		pq.pop();
		if (dp[k][u] < w)
			continue;
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i].first;
			ll cost = g[u][i].second;
			if (dp[k][v] > dp[k][u] + cost){
				dp[k][v] = dp[k][u] + cost;
				pq.push(make_pair(-dp[k][v], make_pair(k, v)));
			}
			if (k<K && dp[k + 1][v]>dp[k][u]){
				dp[k + 1][v] = dp[k][u];
				pq.push(make_pair(-dp[k + 1][v], make_pair(k + 1, v)));
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	int u, v, w;
	g.resize(N + 1);
	for (int i = 0; i < M; i++){
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(make_pair(v, (ll)w));
		g[v].push_back(make_pair(u, (ll)w));
	}
	for (int i = 1; i < N + 1; i++)
		for (int j = 0; j < K + 1; j++)
			dp[j][i] = LLONG_MAX;
	dijkstra_KK();
	ll ans = LLONG_MAX;
	for (int i = 0; i <= K; i++)
		ans = min(ans, dp[i][N]);
	printf("%lld\n", ans);
	return 0;
}