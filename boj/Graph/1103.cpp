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
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char arr[50][51];
int dist[50][50];
int visit[50][50];
int N,M;
int cycle;
int dfs(int x,int y){
    int& ret = dist[x][y];
    for(int i = 0;i<4;i++){
        int nx = x+dx[i]*(arr[x][y]-'0');
        int ny = y+dy[i]*(arr[x][y]-'0');
        if(nx<0 || ny<0 || nx>=N || ny >= M)
            continue;
        else if(arr[nx][ny] == 'H')
            continue;
        if(visit[nx][ny]){
            cycle = 1;
            return ret = 1;
        }
        if(dist[nx][ny] != 0){
            ret = max(ret,1+dist[nx][ny]);
            continue;
        }
        visit[nx][ny] = 1;
        ret = max(ret,1+dfs(nx,ny));
        visit[nx][ny] = 0;
    }
    ret = max(ret,1);
    //printf(">> %d %d %d %d\n",x,y,dist[x][y],visit[x][y]);
    return ret;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++)
        scanf("%s",arr[i]);
    visit[0][0] = 1;
    int ans = dfs(0,0);
    if(cycle)
        ans = -1;
    printf("%d\n", ans);
}