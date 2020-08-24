#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int arr[300][300];
int visit[300][300];
int BFS(){
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(0,0,1));
	visit[0][0] = 1;
	while(!q.empty()){
		int x = get<0> (q.front());
		int y = get<1> (q.front());
		int d = get<2> (q.front());
		q.pop();
		if(x == N-1 && y == M-1)
			return d;
		for(int i = 1;i<=arr[x][y];i++){
			int nx = x;
			int ny = y+i;
			if(nx >= N || ny >= M)
				continue;
			if(!visit[nx][ny]){
				visit[nx][ny] = 1;
				q.push(make_tuple(nx,ny,d+1));
			}
		}
		for(int i = 1;i<=arr[x][y];i++){
			int nx = x+i;
			int ny = y;
			if(nx >= N || ny >= M)
				continue;
			if(!visit[nx][ny]){
				visit[nx][ny] = 1;
				q.push(make_tuple(nx,ny,d+1));
			}
		}
	}

}
int main(){
	scanf("%d %d",&N,&M);
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("%d\n",BFS()-1);
}