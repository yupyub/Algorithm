#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>g[2][100];
int chk[2][100][100];
int dfs(int t,int n,int s){
	chk[t][n][s] = 1;
	int ret = 1;
	for(int nx : g[t][n])
		if(chk[t][nx][s] == 0)	ret += dfs(t,nx,s);
	return ret;
}
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		g[0][a-1].push_back(b-1);
		g[1][b-1].push_back(a-1);
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(dfs(0,i,i)-1 > n/2) ans++;
		else if(dfs(1,i,i)-1 > n/2) ans++;
	}
	printf("%d\n",ans);
}