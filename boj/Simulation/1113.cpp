#include <cstdio>
#include <queue>
using namespace std;
int N,M;
int map[52][52];
int visit[52][52];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int BFS(int h){
	queue<pair<int,int> >q;
	for(int i = 0;i<=N;i++){
		q.push(make_pair(0,i));
		q.push(make_pair(N,i));
		visit[0][i] = visit[N][i] = h;
	}
	for(int j = 0;j<=M;j++){
		q.push(make_pair(j,0));
		q.push(make_pair(j,M));
		visit[j][0] = visit[j][M] = h;
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||ny<0||nx>N||ny>M)
				continue;
			if(visit[nx][ny]<h){
				visit[nx][ny] = h;
				if(map[nx][ny] < h)
					q.push(make_pair(nx,ny));
			}
		}
	}
	int ret = 0;
	for(int i = 0;i<=N;i++)
		for(int j = 0;j<=M;j++)
			if(visit[i][j]<h && map[i][j]<h)
				ret++;
	return ret;
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i = 1;i<=N;i++)
		for(int j = 1;j<=M;j++)
			scanf("%1d",&map[i][j]);
	// 0~(N+1) * 0~(M+1) 사이즈 맵을 만든다.
	N++;
	M++;
	int ans = 0;
	for(int i = 1;i<10;i++)
		ans += BFS(i);
	printf("%d\n",ans);
}