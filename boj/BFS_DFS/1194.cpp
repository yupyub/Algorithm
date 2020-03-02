#include <cstdio>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int N,M;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
char map[51][51];
int visit[51][51][1<<7];
int key_val(int x,int y){
	if(map[x][y]>='a' && map[x][y]<='f')
		return map[x][y] - 'a' + 1;
	return 0;
}
int door_val(int x,int y){
	if(map[x][y]>='A' && map[x][y]<='F')
		return map[x][y] - 'A' + 1;
	return 0;
}
int bfs(int sx,int sy){
	queue<tuple<int,int,int,int> > q;
	visit[sx][sy][0] = 1;
	q.push(make_tuple(sx,sy,0,0));
	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int count = get<2>(q.front());
		int state = get<3>(q.front());
		q.pop();
		if(map[x][y] == '1')
			return count;
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0 || ny<0 || nx>=N || ny>=M)
				continue;
			if(map[nx][ny] == '#')
				continue;
			int nxt_state = state|(1<<key_val(nx,ny));
			if(visit[nx][ny][nxt_state])
				continue;
			if(door_val(nx,ny) != 0 && (nxt_state&(1<<door_val(nx,ny))) != 0){
				visit[nx][ny][nxt_state] = 1;
				q.push(make_tuple(nx,ny,count+1,nxt_state));
			}
			else if(door_val(nx,ny) == 0){
				visit[nx][ny][nxt_state] = 1;
				q.push(make_tuple(nx,ny,count+1,nxt_state));
			}
		}
	}
	return -1;
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i = 0;i<N;i++)
		scanf("%s",map[i]);
	int sx,sy;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(map[i][j] == '0'){
				sx = i;
				sy = j;
				map[i][j] = '0';
			}
		}
	}
	printf("%d\n",bfs(sx,sy));
	return 0;
}