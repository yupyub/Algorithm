#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;	
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(char map[][50],int row_num,int col_num,int start_x,int start_y){\
	int visit[50][50] = {0,};
	queue<tuple<int,int,int> >que;
	visit[start_x][start_y] = 1;
	for(int i = 0;i<row_num;i++)
		for(int j = 0;j<col_num;j++)
			if(map[i][j] == '*')
				que.push(make_tuple(i,j,0));
	que.push(make_tuple(start_x,start_y,1));
	while(!que.empty()){
		int now_x = get<0>(que.front());
		int now_y = get<1>(que.front());
		int now_type = get<2>(que.front());
		que.pop();
		for(int i = 0;i<4;i++){
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if(next_x<0||next_y<0||next_x>=row_num||next_y>=col_num)
				continue;
			if(map[next_x][next_y] == 'D' && now_type == 1)
				return visit[now_x][now_y];
			if(map[next_x][next_y] == '.' && now_type == 0){
				map[next_x][next_y] = '*';
				que.push(make_tuple(next_x,next_y,now_type));
			}
			else if(map[next_x][next_y] == '.' && now_type == 1 &&visit[next_x][next_y] == 0){
				visit[next_x][next_y] = visit[now_x][now_y]+1;
				que.push(make_tuple(next_x,next_y,now_type));
			}
		}
	}
	return -1;
}
int main(){
	int row_num,col_num;
	int start_x,start_y;
	char map[50][50];
	scanf("%d %d",&row_num,&col_num);
	for(int i = 0;i<row_num;i++){
		for(int j = 0;j<col_num;j++){
			scanf(" %c",&map[i][j]);
			if(map[i][j] == 'S'){
				start_x = i,start_y = j;
				map[i][j] = '.';
			}
		}
	}
	int ans = bfs(map,row_num,col_num,start_x,start_y);
	if(ans == -1)
		printf("KAKTUS\n");
	else printf("%d\n",ans);
}	