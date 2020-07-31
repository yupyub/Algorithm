#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
vector<pair<int,int> > g[1001];
int dist[1001];
int dp[1001];
void dijk(int s){
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
	pq.push(make_pair(0,s));
	dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().first;
		int n = pq.top().second;
		pq.pop();
		for(auto nxt : g[n]){
			int nx = nxt.first;
			int nd = nxt.second;
			if(dist[nx]>d+nd){
				dist[nx] = d + nd;
				pq.push(make_pair(dist[nx],nx));
			}
		}
	}
}
int dfs(int n){
	if(n == 1)
		return 1;
	if(dp[n] != -1)
		return dp[n];
	dp[n] = 0;
	for(auto nxt : g[n]){
		int nx = nxt.first;
		if(dist[nx]<=dist[n])
			continue;
		dp[n] += dfs(nx);
	}
	return dp[n];
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a,b,c;
	for(int i = 1;i<=n;i++)
		dist[i] = INF,dp[i] = -1;
	for(int i = 0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	dijk(2);
	printf("%d\n",dfs(2));
}