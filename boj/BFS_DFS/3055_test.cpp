#include <cstdio>
#include <queue>
#include <tuple>
#include <cstdlib>
#include <ctime>
using namespace std;	
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs2(char map[][50],int row_num,int col_num,int start_x,int start_y){
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
void flow(char map[][50],int row_num,int col_num){
	int visit[50][50] = {0,};
	for(int i = 0;i<row_num;i++){
		for(int j = 0;j<col_num;j++){
			if(map[i][j] == '*' && visit[i][j] == 0){
				for(int k = 0;k<4;k++){
					int next_x = i+dx[k];
					int next_y = j+dy[k];
					if(next_x<0||next_y<0||next_x>=row_num||next_y>=col_num)
						continue;
					if(map[next_x][next_y] == '.'){
						visit[next_x][next_y] = 1;
						map[next_x][next_y]='*';
					}
				}
			}
		}
	}
}
int bfs1(char map[][50],int row_num,int col_num,int start_x,int start_y){
	int time_check = -1;
	int visit[50][50]={0,};
	queue<tuple<int,int,int> >que;
	que.push(make_tuple(start_x,start_y,0));
	//flow(map,row_num,col_num);
	while(!que.empty()){
		int now_x = get<0>(que.front());
		int now_y = get<1>(que.front());
		int now_time = get<2>(que.front());
		que.pop();
		if(now_time>time_check){
			time_check = now_time;
			flow(map,row_num,col_num);
		}
		/*
		printf("-- %d %d %d\n",now_x,now_y,now_time);
		for(int i = 0;i<row_num;i++){
			for(int j = 0;j<col_num;j++){
				printf("%c",map[i][j]);
			}
			printf("\n");
		}
		*/
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
	int row_num = 4,col_num = 4;
	int start_x,start_y;
	char map[50][50],map1[50][50],map2[50][50];
	int S_x,S_y,D_x,D_y;
	while(1){
		while(1){
			S_x = rand()%row_num;
			S_y = rand()%col_num;
			D_x = rand()%row_num;
			D_y = rand()%col_num;
			if(S_x != D_x || S_y != D_y) break;
		}
		char c;
		for(int i = 0;i<row_num;i++){
			for(int j = 0;j<col_num;j++){
				c = '.';
				if(rand()%100<5) c = '*';
				else if(rand() %100<5) c = 'X';
				map[i][j] = map1[i][j] = map2[i][j] = c;
			}
		}
		map[S_x][S_y] = map1[S_x][S_y] = map2[S_x][S_y] = 'S';
		map[D_x][D_y] = map1[D_x][D_y] = map2[D_x][D_y] = 'D';
		start_x = S_x;
		start_y = S_y;
		int ans1 = bfs1(map1,row_num,col_num,start_x,start_y);
		int ans2 = bfs2(map2,row_num,col_num,start_x,start_y);
		printf(">> %d %d\n",ans1,ans2);
		if(ans1 != ans2){
			for(int i = 0;i<row_num;i++){
				for(int j = 0;j<col_num;j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
			break;
		}
	}
}	