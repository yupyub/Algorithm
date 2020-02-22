#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;	
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void flow(char map[][51],int row_num,int col_num){
	int visit[51][51] = {0,};
	for(int i = 0;i<row_num;i++)
		for(int j = 0;j<col_num;j++)
			if(map[i][j] == '*' && visit[i][j] == 0)
				for(int k = 0;k<4;k++)
					if(map[i+dx[k]][j+dy[k]] == '.'){
						visit[i+dx[k]][j+dy[k]] = 1;
						map[i+dx[k]][j+dy[k]]='*';
					}
}
int bfs(char map[][51],int row_num,int col_num,int start_x,int start_y){
	int time_check = -1;
	int visit[51][51];
	queue<tuple<int,int,int> >que;
	que.push(make_tuple(start_x,start_y,0));
	while(!que.empty()){
		int now_x = get<0>(que.front());
		int now_y = get<1>(que.front());
		int now_time = get<2>(que.front());
		//printf(">> %d %d %d\n",now_x,now_y,now_time);
		que.pop();
		if(now_time>time_check){
			time_check = now_time;
			flow(map,row_num,col_num);
			/*
			for(int i = 0;i<row_num;i++){
				for(int j = 0;j<col_num;j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
			*/
		}
		for(int i = 0;i<4;i++){
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if(next_x<0||next_y<0||next_x>=row_num||next_y>=col_num)
				continue;
			if(map[next_x][next_y] == 'D')
				return now_time+1;
			if(map[next_x][next_y] == '.' && visit[next_x][next_y] == 0){
				visit[next_x][next_y] = now_time+1;
				que.push(make_tuple(next_x,next_y,now_time+1));
			}
		}
	}
	return -1;
}
int main(){
	int row_num,col_num;
	int start_x,start_y;
	char map[51][51];
	scanf("%d %d",&row_num,&col_num);
	for(int i = 0;i<row_num;i++){
		for(int j = 0;j<col_num;j++){
			scanf("\n%c",&map[i][j]);
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