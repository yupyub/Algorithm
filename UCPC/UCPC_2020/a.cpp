#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<int> g[100001];
int depth[100001];
int dist[100001];
int N,S,D;

int findD(int n,int d){
	depth[n] = 0;
	for(int nx : g[n]){
		if(depth[nx] != -1)
			continue;
		depth[n] = max(depth[n],findD(nx,d+1)-d);
	}
	return depth[n]+d;
}
int dfs(int n){
	dist[n] = 0;
	if(depth[n]==D)
		return 0;
	else if(depth[n]<D)
		return -2;
	int tot = 0;
	for(int nx : g[n]){
		if(dist[nx] != -1)
			continue;
		dist[n] += dfs(nx)+2;
	}
	return dist[n];
}
int main(){
	scanf("%d %d %d",&N,&S,&D);
	int a,b;
	for(int i = 1;i<N;i++){
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i<=N;i++)
		depth[i] = dist[i] = -1;
	findD(S,0);
	// for(int i = 1;i<=N;i++){
	// 	printf(">> %d %d\n",i,depth[i]);
	// }
	int ans = dfs(S);
	printf("%d\n",ans < 0 ? 0:ans);
	// for(int i = 1;i<=N;i++){
	// 	printf(">> %d %d\n",i,dist[i]);
	// }
}
