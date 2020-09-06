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
int n,a,b,da,db;
int dist = 0;
int dist_ab = 0;
int visit[100001];
vector<vector<int> > g;
int dfs(int s,int d){
	if(s == b)
		dist_ab = d;
	int maxi = 0;
	int moved = 0;
	for(int nx : g[s]){
		if(visit[nx])
			continue;
		visit[nx] = 1;
		int dd = dfs(nx,d+1)+1;
		moved = 1;
		dist = max(dist,maxi+dd+1);
		if(maxi<dd) maxi = dd;
	}
	if(!moved)
		return 0;
	else 
		return maxi;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
		g.clear();
		g.resize(n+1);
		int u,v;
		for(int i = 1;i<n;i++){
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(da>=db){
			printf("Alice\n");
			continue;
		}
		///////////////////////////
		dist = 0;
		dist_ab = 0;
		for(int i = 1;i<=n;i++)
			visit[i] = 0;
		visit[a] = 1;
		dfs(a,0);
		if(dist_ab<=da){
			printf("Alice\n");
			continue;
		}
		if(da>=dist/2){
			printf("Alice\n");
			continue;
		}
		if(db>2*da){
			printf("Bob\n");
			continue;
		}
		printf("Alice\n");
	}


}