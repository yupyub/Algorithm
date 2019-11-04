#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R,C;
pair<int,int> st1,st2;
pair<int,int> pos;
int blk[8][5] = {{0,0,0,0,0},{0,2,0,0,3},{0,0,0,2,1},{0,0,1,4,0},{0,4,3,0,0},{0,1,0,3,0},{0,0,2,0,4},{0,1,2,3,4}};
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
char map[26][26];
int arr[26][26];
int blkdir,blkcnt;
pair<int,int> findpos(int sx,int sy){
	queue<pair<pair<int,int>,int> >q;
	for(int i = 1;i<=4;i++){
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
		q.push(make_pair(make_pair(sx+dx[i],sy+dy[i]),i));
	}
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		int ndir = blk[arr[x][y]][dir];
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];
		if(ndir == 0 || nx<0 || ny<0 || nx>=R || ny>=C) continue;
		if(arr[nx][ny] == 0) {
			blkdir = ndir;
			return make_pair(nx,ny);
		}
		else
			q.push(make_pair(make_pair(nx,ny),ndir));
	}
	return make_pair(-1,-1);
}
int findans(int sx,int sy){
	queue<pair<pair<int,int>,pair<int,int> > >q;
	for(int i = 1;i<=4;i++){
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
		q.push(make_pair(make_pair(sx+dx[i],sy+dy[i]),make_pair(i,2)));
	}
	int cnt = 2;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		int ndir = blk[arr[x][y]][dir];
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];
		//printf("(%d %d) %d %d (%d %d)\n",x,y,dir,ndir,nx,ny);
		if(ndir == 0 || nx<0 || ny<0 || nx>=R || ny>=C) continue;
		//if(arr[nx][ny] == -1) printf("%d %d\n",cnt,blkcnt);
		if(arr[nx][ny] == -1 && blkcnt <= cnt) {
			return 1;
		}
		else{
			q.push(make_pair(make_pair(nx,ny),make_pair(ndir,cnt+1)));
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&R,&C);
	for(int i = 0;i<R;i++){
		scanf("%s",map[i]);
	}
	blkcnt = C*R;
	for(int i = 0;i<R;i++){
		for(int j = 0;j<C;j++){
			switch(map[i][j]){
				case '.' : arr[i][j] = 0; blkcnt--; break;
				case '|' : arr[i][j] = 5; break;
				case '-' : arr[i][j] = 6; break;
				case '+' : arr[i][j] = 7; blkcnt++; break;
				case '1' : arr[i][j] = 1; break;
				case '2' : arr[i][j] = 2; break;
				case '3' : arr[i][j] = 3; break;
				case '4' : arr[i][j] = 4; break;
				case 'M' : arr[i][j] = -1; st1 = make_pair(i,j); break;
				case 'Z' : arr[i][j] = -1; st2 = make_pair(i,j); break;
			}
		}
	}
	pos = findpos(st1.first,st1.second);
	if(pos.first == -1) pos = findpos(st2.first,st2.second);
	if(pos.first == -1){
		int cj = 0;
		for(int i = 1;i<5;i++){
			int nx = st1.first+dx[i];
			int ny = st1.second+dy[i];
			for(int j = 7;j<8;j++){
				arr[nx][ny] = j;
				if(findans(st1.first,st1.second)){
					printf("%d %d ",nx+1,ny+1);
					switch(j){
						case 5 : printf("|\n"); break;
						case 6 : printf("-\n"); break;
						case 7 : printf("+\n"); break;
						default : printf("%d\n",j); break;
					}
				cj = 1;
				break;
				}
			}
			arr[nx][ny] = 0;
			if(cj) break;
		}
		return 0;	
	}
	for(int i = 1;i<8;i++){
		arr[pos.first][pos.second] = i;
		if(findans(st1.first,st1.second)){
			printf("%d %d ",pos.first+1,pos.second+1);
			switch(i){
				case 5 : printf("|\n"); break;
				case 6 : printf("-\n"); break;
				case 7 : printf("+\n"); break;
				default : printf("%d\n",i); break;
			}
			break;
		}
	}
}