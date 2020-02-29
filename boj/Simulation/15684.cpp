#include <cstdio>
int map[32][12];
int visit[32][12];
int count,count2;
int n,m,h,a,b;
int dfs(int x,int y){
	if(x == h+1)
		return y;
	int ret;
	if(map[x][y] == 0)
		ret = dfs(x+1,y);
	else if(map[x][y] == 1)
		ret = dfs(x+1,y-1);
	else
		ret = dfs(x+1,y+1);
	return ret;
}
int map_change(int x,int y,int cnt){
	if(cnt == 0){
		for(int i = 1;i<=n;i++){
			if(dfs(1,i) != i)
				return 0;
		}
		return 1;
	}
	int ret = 0;
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<n;j++){
			if(map[i][j] == 0 && map[i][j+1] == 0){
				map[i][j] = 2;
				map[i][j+1] = 1;
				if(j == n-1)
					ret = map_change(i+1,1,cnt-1);
				else
					ret = map_change(i,j+1,cnt-1);
				map[i][j] = 0;
				map[i][j+1] = 0;
			}
			if(ret != 0) 
				return ret;
		}
	}
	return ret;
}
int main(){
	scanf("%d %d %d",&n,&m,&h);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		map[a][b] = 2;
		map[a][b+1] = 1;
	}
	int ans = -1;
	for(int i = 0;i<4;i++){
		if(map_change(1,1,i)){
			ans = i;
			break;
		}
	}
	printf("%d\n",ans);
}