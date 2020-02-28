#include <cstdio>
int dx[] = {1,0,0};
int dy[] = {0,-1,1};
int map[11][31];
int n,m,h,a,b;
int dfs(int sx,int sy){
	if(sx == n)
		return sy;
	int nx = sx+dx[map[sx][sy]];
	int ny = sy+dy[map[sx][sy]];
	return dfs(nx,ny);
}
int map_change(int x,int y,int cnt){
	if(cnt == 0){
		for(int i = 1;i<=n;i++)
			if(dfs(1,i) != i)
				return 0;
		return 1;
	}
	for(int i = 0;i<cnt;i++){
		
}
int main(){
	scanf("%d %d %d",&h,&m,&n);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		map[a][b] = 2;
		map[a][b+1] = 1;
	}
	int ans = -1;
	