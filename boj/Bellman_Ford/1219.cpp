#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
static const ll NEG_INF = -98654321987654321;
vector<pair<pair<int, int>, ll> >g;
ll dist[100];
ll city[100];
int cycle[100];
int ch[100];
int V,E;
void bellman_ford(int start){
	dist[start] = city[start];
	for (int i = 1; i <= V; i++){
		for (int j = 0; j < E; j++){
			int n = g[j].first.first;
			int nx = g[j].first.second;
			if (dist[n] != NEG_INF && dist[nx]<dist[n] + g[j].second){
				dist[nx] = dist[n] + g[j].second;
				if(i == V){
					cycle[nx] = 1;
				}
			}
		}
	}
}
int dfs(int n){
	ch[n] = 1;
	if(cycle[n])
		return 1;
	for(int i = 0;i<E;i++){
		if(g[i].first.second != n)
			continue;
		int nx = g[i].first.first;
		if(!ch[nx]){
			if(dfs(nx))
				return 1;
		}
	}
	return 0;
}
int main(){
	int s,e,u,v;
	ll c;
	scanf("%d %d %d %d", &V,&s,&e,&E);
	for(int i = 0;i<E;i++){
		scanf("%d %d %lld",&u,&v,&c);
		g.push_back(make_pair(make_pair(u,v),c));
	}
	for(int i = 0;i<V;i++)
		scanf("%lld",&city[i]);
	for(int i = 0;i<E;i++)
		g[i].second = -g[i].second + city[g[i].first.second];
	for(int i = 0;i<V;i++)
		dist[i] = NEG_INF;
	bellman_ford(s);
	if(dist[e] == NEG_INF){
		printf("gg\n");
		return 0;
	}
	if(dfs(e))
		printf("Gee\n");
	else
		printf("%lld\n",dist[e]);
    return 0;
}