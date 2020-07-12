#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
int ch[100][100];
int dx[2][3] = {{-1,-1,1},{1,1,-1}};
int dy[2][3] = {{-1,1,0},{1,-1,0}};
int dfs(int x,int y,int n,int dir){
	int ret = 0;
	for(int i = 0;i<3;i++){
		int nx = x+dx[x%2][i];
		int ny = y+dy[x%2][i];
		if(i == dir)
			continue;
		if(n > 0 && ch[nx][ny] == 0){
			ch[nx][ny] = 1;
			ret += dfs(nx,ny,n-1,i);
			ch[nx][ny] = 0;
		}
		else if(n == 0){
			if(ch[nx][ny] == 1)
				ret++;
		}
	}
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	ch[50][50] = 1;
	ch[51][50] = 1;
	printf("%d\n",dfs(51,50,n-1,2));
}