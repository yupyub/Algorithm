#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > g[100001];
int visit[100001];
int pos,maxi;
void dfs(int n,int d){
	for(auto nxt : g[n]){
		int nx = nxt.first;
		int nd = nxt.second;
		if(visit[nx] == 0){
			visit[nx] = 1;
			dfs(nx,d+nd);
		}
	}
	if(d>maxi){
		maxi = d;
		pos = n;
	}
}
int main(){
	int V;
	scanf("%d",&V);
	for(int i = 0;i<V;i++){
		int a;
		scanf("%d",&a);
		int b,c;
		while(1){
			scanf("%d",&b);
			if(b == -1)
				break;
			scanf("%d",&c);
			g[a].push_back(make_pair(b,c));
		}
	}
	visit[1] = 1;
	dfs(1,0);
	for(int i = 1;i<=V;i++)
		visit[i] = 0;
	visit[pos] = 1;
	dfs(pos,0);
	printf("%d\n",maxi);
}