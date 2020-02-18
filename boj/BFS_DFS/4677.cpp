#include <cstdio>
char arr[100][100];
int visit[100][100];
int n,m;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y){
	for(int i = 0;i<8;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m) 
			continue;
		if(arr[nx][ny] == '@' && visit[nx][ny] == 0){
			visit[nx][ny] = 1;
			dfs(nx,ny);
		}
	}
}
int main(){
	while(1){
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0) break;
		for(int i = 0;i<n;i++)
			scanf("%s",arr[i]);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<m;j++)
				visit[i][j] = 0;
		int ans = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(visit[i][j] == 0 && arr[i][j] == '@'){
					ans++;
					visit[i][j] = 1;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
}