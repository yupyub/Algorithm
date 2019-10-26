#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define INF 987654321
int n,m,sx,sy;
char arr[1000][1000];
int visit[1000][1000];
int fire[1000][1000];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&m,&n);
		for(int i = 0;i<n;i++){
			scanf("%s",arr[i]);
		}
		queue <tuple<int,int,int> >fi;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				fire[i][j] = INF;
				visit[i][j] = 0;
				if(arr[i][j] == '*'){
					fi.push(make_tuple(i,j,0));
					fire[i][j] = 0;
				}
				else if(arr[i][j] == '@'){
					sx = i;
					sy = j;
				}
			}
		}
		while(!fi.empty()){
			int x = get<0>(fi.front());
			int y = get<1>(fi.front());
			int t = get<2>(fi.front());
			fi.pop();
			for(int i = 0;i<4;i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
				if(arr[nx][ny] != '#' && fire[nx][ny]==INF){
					fire[nx][ny] = t+1;
					fi.push(make_tuple(nx,ny,t+1));
				}
			}
		}
		queue<tuple<int,int,int> > q;
		q.push(make_tuple(sx,sy,0));
		visit[sx][sy] = 1;
		int ans = INF;
		while(!q.empty() && ans == INF){
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int t = get<2>(q.front());
			q.pop();
			for(int i = 0;i<4;i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<0 || ny<0 || nx>=n || ny>=m){
					ans = t+1;
					break;
				}
				if(arr[nx][ny] != '#' && visit[nx][ny]==0 &&fire[nx][ny]>t+1){
					visit[nx][ny] = 1;
					q.push(make_tuple(nx,ny,t+1));
				}
			}
		}
		if(ans == INF) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
}

		