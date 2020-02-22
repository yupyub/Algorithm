#include <cstdio>
#include <utility>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
pair<int,int> dfs(char map[][260],int visit[][260],int x,int y,int row_size,int col_size){
	pair<int,int> ret,tmp;
	if(map[x][y] == 'o')
		ret.first++;
	else if(map[x][y] == 'v')
		ret.second++;
	for(int i = 0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=row_size||ny>=col_size)
			continue;
		if(map[nx][ny] != '#' && visit[nx][ny] == 0){
			visit[nx][ny] = 1;
			tmp = dfs(map,visit,nx,ny,row_size,col_size);
			ret.first += tmp.first;
			ret.second += tmp.second;
		}
	}
	return ret;
}
int main(){
	int row_size,col_size,sheep_num=0,wolf_num=0;
	pair<int,int> num;
	char map[260][260];
	int visit[260][260];
	scanf("%d %d",&row_size,&col_size);
	for(int i = 0;i<row_size;i++)
		for(int j = 0;j<col_size;j++)
			scanf(" %c",&map[i][j]);
	for(int i = 0;i<row_size;i++){
		for(int j = 0;j<col_size;j++){
			if(map[i][j] != '#' && visit[i][j] == 0){
				visit[i][j] = 1;
				num = dfs(map,visit,i,j,row_size,col_size);
				if(num.first>num.second)
					sheep_num += num.first;
				else
					wolf_num += num.second;
			}
		}
	}
	printf("%d %d\n",sheep_num,wolf_num);
}