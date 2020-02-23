#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <functional>
#define INF 10000000;
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dijk(char map[][101],int dist[][100],pair<int,int> start_pos,int row_size,int col_size){
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int> >,greater<tuple<int,int,int> > > pq;
	if(start_pos.first == -1){
		for(int i = 0;i<row_size;i++){
			if(map[i][0] == '.')
				dist[i][0] = 0;
			else if(map[i][0] == '#')
				dist[i][0] = 1;
			else
				continue;
			pq.push(make_tuple(dist[i][0],i,0));
		}
		for(int i = 0;i<row_size;i++){
			if(map[i][col_size-1] == '.')
				dist[i][col_size-1] = 0;
			else if(map[i][col_size-1] == '#')
				dist[i][col_size-1] = 1;
			else
				continue;
			pq.push(make_tuple(dist[i][col_size-1],i,col_size-1));
		}
		for(int j = 0;j<col_size;j++){
			if(map[0][j] == '.')
				dist[0][j] = 0;
			else if(map[0][j] == '#')
				dist[0][j] = 1;
			else
				continue;
			pq.push(make_tuple(dist[0][j],0,j));
		}
		for(int j = 0;j<col_size;j++){
			if(map[row_size-1][j] == '.')
				dist[row_size-1][j] = 0;
			else if(map[row_size-1][j] == '#')
				dist[row_size-1][j] = 1;
			else
				continue;
			pq.push(make_tuple(dist[row_size-1][j],row_size-1,j));
		}
	}
	else{
		dist[start_pos.first][start_pos.second] = 0;
		pq.push(make_tuple(0,start_pos.first,start_pos.second));
	}
	while(!pq.empty()){
		int now_dist = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int d = 0;
			if(nx<0||ny<0||nx>=row_size||ny>=col_size)
				continue;
			if(map[nx][ny] == '#')
				d = 1;
			if(map[nx][ny] != '*' && dist[nx][ny] > dist[x][y] + d){
				dist[nx][ny] = dist[x][y] + d;
				pq.push(make_tuple(dist[nx][ny],nx,ny));
			}
		}
	}
}
int main(){
	int TC;
	char map[101][101];
	int rev_dist[100][100];
	int A_dist[100][100];
	int B_dist[100][100];
	scanf("%d",&TC);
	while(TC--){
		int row_size,col_size;
		pair<int,int>A_pos,B_pos;
		scanf("%d %d",&row_size,&col_size);
		for(int i = 0;i<row_size;i++)
			scanf("%s",map[i]);
		int find_A = 0;
		for(int i = 0;i<row_size;i++){
			for(int j = 0;j<col_size;j++){
				if(map[i][j] == '$'){
					if(find_A == 0){
						A_pos = make_pair(i,j);
						find_A = 1;
					}
					else
						B_pos = make_pair(i,j);
					map[i][j] = '.';
				}
			}
		}
		for(int i = 0;i<row_size;i++)
			for(int j = 0;j<col_size;j++)
				rev_dist[i][j] = A_dist[i][j] = B_dist[i][j] = INF;
		dijk(map,rev_dist,make_pair(-1,-1),row_size,col_size);
		dijk(map,A_dist,A_pos,row_size,col_size);
		dijk(map,B_dist,B_pos,row_size,col_size);
		int ans = INF;
		for(int i = 0;i<row_size;i++){
			for(int j = 0;j<col_size;j++){
				if(map[i][j] == '.')
					ans = min(ans,A_dist[i][j]+B_dist[i][j]+rev_dist[i][j]);
				else if(map[i][j] == '#')
					ans = min(ans,A_dist[i][j]+B_dist[i][j]+rev_dist[i][j]-2);
			}
		}
		ans = min(ans,rev_dist[A_pos.first][A_pos.second] + rev_dist[B_pos.first][B_pos.second]);
		printf("%d\n",ans);
	}
}