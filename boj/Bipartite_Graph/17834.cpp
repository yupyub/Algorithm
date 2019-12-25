// Search Bipartite Graph
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int> g[50001];
long long cnt[2];
int visit[50001];
bool dfs(int n,int c){
	if(visit[n] == -1){
		visit[n] = c;
		cnt[c]++;
	}
	else if(visit[n] != c) return false;
	else return true;
	for(int i = 0;i<g[n].size();i++){
		if(dfs(g[n][i],(c+1)%2) == false) return false;
	}
	return true;
}
int main(){
	int n,m;
	int a,b;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(visit,-1,sizeof visit);
	if(dfs(1,0) == false) printf("0\n");
	else printf("%lld\n",cnt[0]*cnt[1]*2);
}