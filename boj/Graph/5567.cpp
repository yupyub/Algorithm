#include <cstdio>
int fr[501][501];
int visit[501];
int dfs(int s,int c){
	if(c == 2) return 1;
	int ret = 0;
	for(int i = 1;i<501;i++){
		if(fr[s][i] && !visit[i]){
			visit[i] = 1;
			ret += dfs(i,c+1) + 1;
		}
	}
	return ret;
}
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		fr[a][b] = fr[b][a] = 1;
	}
	visit[1] = 1;
	printf("%d\n",dfs(1,0));
}

