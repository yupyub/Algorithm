
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 987654321987654321;
vector<pair<pair<int, int>, int> >g;
ll dist[502];
int V;
ll chdist[502];
void bellman_ford(){
	for (int i = 1; i < V; ++i)	{
		for (int j = 0; j < g.size(); ++j)		{
			if(dist[g[j].first.first] == INF)
				continue;
			if (dist[g[j].first.second]>dist[g[j].first.first] + g[j].second)
				dist[g[j].first.second] = dist[g[j].first.first] + g[j].second;
		}
	}
}
int main(){
	int E, i = 0, cost, u, v;
	scanf("%d %d", &V, &E);
	for (i = 1; i < V + 1; ++i)
		dist[i] = INF;
	for (i = 0; i < E; i++)	{
		scanf("%d %d %d", &u, &v, &cost);
		g.push_back(make_pair(make_pair(u, v), cost));
	}
	dist[1] = 0;
	bellman_ford();
	for (i = 1; i < V + 1; ++i)
		chdist[i] = dist[i];
	bellman_ford();
	for (i = 1; i < V + 1; ++i)	{
		if (chdist[i] != dist[i]){
			printf("-1\n");
			return 0;
		}
	}
	for (i = 2; i < V + 1; ++i)	
		printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
    return 0;
}