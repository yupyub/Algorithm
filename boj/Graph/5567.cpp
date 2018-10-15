#include <cstdio>
#include <queue>
using namespace std;
int fr[501][501];
int visit[501];
int bfs(int s){
	queue<pair<int,int> >q;
	q.push(make_pair(s,0));
	int ans = 0;
	while(!q.empty()){
		int n = q.front().first;
		int c = q.front().second;
		if(c == 2) break;
		q.pop();
		for(int i = 1;i<501;i++){
			if(fr[n][i] && !visit[i]){
				visit[i] = 1;
				q.push(make_pair(i,c+1));
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a,&b);
		fr[a][b] = fr[b][a] = 1;
	}
	visit[1] = 1;
	printf("%d\n",bfs(1));
}

