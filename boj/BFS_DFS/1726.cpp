#include <cstdio>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(int map[][100],int row_size,int col_size,int start_x,int start_y,int start_dir,int end_x,int end_y,int end_dir){
	int visit[100][100][4] = {0,};
	queue<tuple<int,int,int,int> > q;
	q.push(make_tuple(start_x,start_y,start_dir,0));
	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int dir = get<2>(q.front());
		int dist = get<3>(q.front());
		//printf(">> %d %d %d %d\n",x,y,dir,dist);
		if(x == end_x && y == end_y && dir == end_dir)
			return dist;
		q.pop();
		if(dir == 0 || dir == 1){
			if(visit[x][y][2] == 0){
				visit[x][y][2] = 1;
				q.push(make_tuple(x,y,2,dist+1));	
			}
			if(visit[x][y][3] == 0){
				visit[x][y][3] = 1;
				q.push(make_tuple(x,y,3,dist+1));
			}
		}
		else{
			if(visit[x][y][0] == 0){
				visit[x][y][0] = 1;
				q.push(make_tuple(x,y,0,dist+1));
			}
			if(visit[x][y][1] == 0){
				visit[x][y][1] = 1;
				q.push(make_tuple(x,y,1,dist+1));
			}
		}
		for(int i = 1;i<=3;i++){
			int nx = x+dx[dir]*i;
			int ny = y+dy[dir]*i;
			if(nx<0||ny<0||nx>=row_size||ny>=col_size)
				break;
			if(map[nx][ny] == 1)
				break;
			if(visit[nx][ny][dir] == 0)
				q.push(make_tuple(nx,ny,dir,dist+1));
		}
	}
	return 0;
}
int main(){
	int map[100][100];
	int row_size,col_size;
	scanf("%d %d",&row_size,&col_size);
	for(int i = 0;i<row_size;i++)
		for(int j = 0;j<col_size;j++)
			scanf("%1d",&map[i][j]);
	int start_x,start_y,start_dir,end_x,end_y,end_dir;
	scanf("%d %d %d",&start_x,&start_y,&start_dir);
	scanf("%d %d %d",&end_x,&end_y,&end_dir);
	int ans = bfs(map,row_size,col_size,start_x-1,start_y-1,start_dir-1,end_x-1,end_y-1,end_dir-1);
	printf("%d\n",ans);
}