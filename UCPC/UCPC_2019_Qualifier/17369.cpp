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
const int INF = 3'000'000;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
vector<tuple<int,int,int> >g[4];
// x,y,0 : 창문
// x,t,1 : / 방향 거울
// x,t,2 : \ 방향 거울
// x,t,3 : 유령
map<tuple<int,int,int>, pair<int,int> >sol;
int detect(int x1,int x2,int y1,int y2,int dir,int idx){
	int x = get<0> (g[dir][idx]);
	int y = get<1> (g[dir][idx]);
	if(x<x1)
		return -1;
	if(x>x2)
		return 1;
	if(y<y1)
		return -1;
	if(y>y2)
		return 1;
	return 0;
}
int findNext(int x1,int x2,int y1,int y2,int dir){
	int st = 0;
	int ed = g[dir].size();
	int mid;
	int ret = -1;
	while(st<=ed){
		mid = (st+ed)/2;
		int det = detect(x1,x2,y1,y2,dir,mid);
		if(det == -1)
			st = mid+1;
		else if(det == 1)
			ed = mid-1;
		else{
			ed = mid-1;
			ret = mid;
		}
	}
	return ret;
}
void simul(int sx,int sy,int sdir){
	auto it = sol.find(make_tuple(sx,sy,sdir));
	if(it != sol.end()){
		printf("%d %d\n",(it->second).first,(it->second).second);
		return;
	}
	int dir = sdir;
	int x = sx;
	int y = sy;
	int idx,nx,ny,nc;
	int ghost = 0;
	int dist = 0;
	int tot = 0;
	while(1){
		nx = x + dx[dir];
		ny = y + dy[dir];
		if(nx == 0 || nx == N+1)
			break;
		if(ny == 0 || ny == M+1)
			break;
		//printf("(%d %d) (%d %d) %d",x,y,nx,ny,dir);
		if(dir == 0)
			idx = findNext(-ny,-ny,-nx,0,dir);
		else if(dir == 1)
			idx = findNext(nx,nx,ny,INF,dir);
		else if(dir == 2)
			idx = findNext(ny,ny,nx,INF,dir);
		else
			idx = findNext(-nx,-nx,-ny,0,dir);
		nx = get<0>(g[dir][idx]);
		ny = get<1>(g[dir][idx]);
		if(dir == 0||dir == 3)
			nx = -nx, ny = -ny;
		if(dir == 2||dir == 0)
			swap(nx,ny);
		nc = get<2>(g[dir][idx]);
		//printf("--> %d (%d %d %d)\n",idx,nx,ny,nc);
		dist += abs(nx-x)+abs(ny-y);
		x = nx, y = ny;
		if(nc == 0)
			break;
		if(nc == 3){ // 유령
			ghost++;
			tot += dist;
		}
		if(nc == 1){ // '/'거울
			if(dir%2)
				dir--;
			else
				dir++;
		}
		if(nc == 2){ // '\' 거울
			if(dir == 0)
				dir = 3;
			else if(dir == 1)
				dir = 2;
			else if(dir == 2)
				dir = 1;
			else dir = 0;
		}
	}
	printf("%d %d\n",ghost,tot);
	sol[make_tuple(sx,sy,sdir)] = make_pair(ghost,tot);
}
int main(){
	int k,q;
	scanf("%d %d %d %d",&N,&M,&k,&q);
	for(int i = 1;i<=N;i++){
		g[1].push_back(make_tuple(i,0,0));
		g[3].push_back(make_tuple(-i,0,0));
		g[1].push_back(make_tuple(i,M+1,0));
		g[3].push_back(make_tuple(-i,-(M+1),0));
	}
	for(int i = 1;i<=M;i++){
		g[2].push_back(make_tuple(i,0,0));
		g[0].push_back(make_tuple(-i,0,0));
		g[2].push_back(make_tuple(i,N+1,0));
		g[0].push_back(make_tuple(-i,-(N+1),0));
	}
	int x,y,z;
	char c;
	for(int i = 0;i<k;i++){
		scanf("%d %d %c\n",&x,&y,&c);
		switch (c){
			case '/':
				z = 1;
				break;
			case '\\':
				z = 2;
				break;
			case '!':
				z = 3;
				break;
		}
		g[1].push_back(make_tuple(x,y,z));
		g[3].push_back(make_tuple(-x,-y,z));
		g[2].push_back(make_tuple(y,x,z));
		g[0].push_back(make_tuple(-y,-x,z));
	}
	for(int i = 0;i<4;i++)
		sort(g[i].begin(),g[i].end());
	int dir,nxt;
	int sx,sy;
	for(int i = 0;i<q;i++){
		scanf("\n%c%d",&c,&x);
		switch(c){
			case 'U':
				dir = 2;
				sx = 0;
				sy = x;
				break;
			case 'L':
				dir = 1;
				sx = x;
				sy = 0;
				break;
			case 'R':
				dir = 3;
				sx = x;
				sy = M+1;
				break;
			case 'D':
				dir = 0;
				sx = N+1;
				sy = x;
				break;
		}
		simul(sx,sy,dir);
	}
}