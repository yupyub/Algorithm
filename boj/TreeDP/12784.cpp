#include <cstdio>
#include <vector>
using namespace std;
vector<vector<pair<int,int> > > g;
int visit[1001];
int dfs(int n, int my_w){
	visit[n] = 1;
	int is_leaf = 1;
	int ret = 0;
	for(auto nn : g[n]){
		int nxt = nn.first;
		int w = nn.second;
		if(!visit[nxt]){
			is_leaf = 0;
			ret += dfs(nxt, w);
		}
	}
	if(is_leaf){
		return g[n][0].second;
	}
	return min(ret, my_w);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n, m, u, v, w, d;
		scanf("%d %d",&n,&m);
		g.clear();
		g.resize(n+1);
		for(int i = 1;i<=n;i++)
			visit[i] = 0;
		for(int i = 0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}
		if(m == 0)
			printf("%d\n", 0);
		else
			printf("%d\n", dfs(1, 987654321));
	}
	return 0;
}
