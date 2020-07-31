#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > g[100001];
int maxi[100001];
int dp[100001];
int visit[100001];
void dfs(int n){
	int max1 = 0;
	int max2 = 0;
	for(auto nxt : g[n]){
		int nx = nxt.first;
		int nd = nxt.second;
		if(visit[nx] != 0)
			continue;
		visit[nx] = 1;
		dfs(nx);
		if(max1<maxi[nx] + nd){
			max2 = max1;
			max1 = maxi[nx] + nd;
		}
		else if(max2<maxi[nx]+nd)
			max2 = maxi[nx]+nd;
		dp[n] = max(dp[n],max(dp[nx],max1+max2));
		maxi[n] = max(maxi[n],max1);
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
			g[b].push_back(make_pair(a,c));
		}
	}
	visit[1] = 1;
	dfs(1);
	printf("%d\n",dp[1]);
}