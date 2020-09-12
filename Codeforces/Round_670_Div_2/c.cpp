#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n;
vector<vector<int> > g;
vector<int>cent;
int trSize[100001];
int dfs(int nn){
	trSize[nn] = 1;
	int flag = 0;
	for(int nxt : g[nn]){
		if(trSize[nxt])
			continue;
		int siz = dfs(nxt);
		if(siz>n/2)
			flag = 1;
		trSize[nn] += siz;
	}
	if(n-trSize[nn]>n/2) 
		flag = 1;
	if(flag == 0)
		cent.push_back(nn);
	return trSize[nn];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		g.clear();
		g.resize(n+1);
		int a,b;
		for(int i = 0;i<n-1;i++){
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cent.clear();
		for(int i = 0;i<=n;i++)
			trSize[i] = 0;
		dfs(1);
		if(cent.size()>1){
			if(g[cent[0]][0] == cent[1]){
				printf("%d %d\n",cent[0],g[cent[0]][1]);
				printf("%d %d\n",cent[1],g[cent[0]][1]);
			}
			else{
				printf("%d %d\n",cent[0],g[cent[0]][0]);
				printf("%d %d\n",cent[1],g[cent[0]][0]);
			}
		}
		else{
			printf("%d %d\n",1,g[1][0]);
			printf("%d %d\n",1,g[1][0]);
		}
	}
}