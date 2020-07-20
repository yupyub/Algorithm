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
int arr[1000][1000];
char dir[1000][1000];
int visit[1000][1000];
int finish[1000][1000];
int cy[1000][1000];
int n;
int cycle;
int prevx,prevy;
int nowx,nowy;
int ans;
int tot;
int retDir(int x,int y){
    switch(dir[x][y]){
        case 'U':
            return 0;
        case 'D':
            return 2;
        case 'L':
            return 3;
        case 'R':
            return 1;
    }
}
int cysx,cysy;
int dfs(int x,int y){
    //printf(">> %d %d\n",x,y);
    int nx = x+dx[retDir(x,y)]*arr[x][y];
    int ny = y+dy[retDir(x,y)]*arr[x][y];
    //printf(">> %d %d\n",nx,ny);
    if(finish[nx][ny]){ // prev DFS graph
        if(prevx != nx || prevy != ny)
            if(!cy[nx][ny])
                ans = 2;
        return 0;
    }
    if(visit[nx][ny]){ //cycle
        cysx = nx;
        cysy = ny;
        if(nx == nowx && ny == nowy){
            if(!tot){
                tot = 1;
                ans = 1;
            }
        }
        cycle++;  
        return 1;
    }
    visit[nx][ny] = 1;
    int ret = dfs(nx,ny);
    finish[nx][ny] = 1;
    if(nx != cysx || ny != cysy){
        cy[nx][ny] = ret;
        return ret;
    }
    else{
        cysx = cysy = -1;
        return 0;
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d%c",&arr[i][j],&dir[i][j]);
    prevx = prevy = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cysx = cysy = -1;
            if(ans == 2)
                break;
            if(!visit[i][j]){
                if(ans == 1)
                    ans = 0;
                nowx = i;
                nowy = j;
                visit[i][j] = 1;
                cy[i][j] = dfs(i,j);
                finish[i][j] = 1;
                prevx = i;
                prevy = j;
            }
        }
    }
    if(ans == 2 || cycle>1)
        printf("TOO SAFE\n");
    else if(ans == 1)
        printf("THIEF LOVE IT!\n");
    else   
        printf("%d %d\n",nowx+1,nowy+1);
}