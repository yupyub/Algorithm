#include <cstdio>
#include <cmath>
int n,m;
int arr[200][200];
int dist[200][200];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int calc(int a1,int a2,int b1,int b2){
	return abs(a1-b1)+abs(a2-b2);
}
void dfs(int x,int y,int sx,int sy){
	for(int i = 0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 ||ny<0 || nx>=n || ny>=m)
			continue;
		int c = calc(nx,ny,sx,sy);
		if(arr[nx][ny] == 0 && dist[nx][ny] > c){
			dist[nx][ny] = c;
			dfs(nx,ny,sx,sy);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			scanf("%1d",&arr[i][j]);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			dist[i][j] = 987654321;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 1){
				dist[i][j] = 0;
				dfs(i,j,i,j);
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
}