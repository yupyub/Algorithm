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
int arr[5001][5001];
int dist[5001][5001];
int N,M,U,V,W,L;
int retDir(int x1, int y1,int x2,int y2){
    if(x1<x2)
        return 2;
    else if(x1>x2)
        return 0;
    else if(y1<y2)
        return 1;
    else   
        return 3;
}
void Dijk(int sx,int sy){
    priority_queue<tuple<int,int,int,int,int>,vector<tuple<int,int,int,int,int> >, greater<tuple<int,int,int,int,int> > > pq;
    pq.push(make_tuple(0,0,0,sx,sy));
    dist[sx][sy] = 0;
    while(!pq.empty()){
        int d = get<0>(pq.top());
        int ax = get<1>(pq.top());
        int ay = get<2>(pq.top());
        int x = get<3>(pq.top());
        int y = get<4>(pq.top());
        //printf("(%d, %d) <%d, %d> %d\n",x,y,ax,ay,d);
        pq.pop();
        for(int i = 0;i<4;i++){ 
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nax = ax;
            int nay = ay;
            int nd = d-(nax*nax+nay*nay);
            if(nx<0 || ny<0 || nx>=N || ny>=M)
                continue;
            if(!(arr[nx][ny] == arr[x][y] && arr[nx][ny] != 0)){
                nax += (i+1)%2;
                nay += (i)%2;
            }
            if(nax*nax + nay*nay>L)
                continue;
            nd += nax*nax + nay*nay;
            if(arr[nx][ny] != arr[x][y]){
                if(arr[nx][ny] != 0)
                    nax = nay = 0;
            }
            else if(arr[nx][ny] != 0){
                nax = nay = 0;
            }
            if(dist[nx][ny]>nd){
                dist[nx][ny] = nd;
                pq.push(make_tuple(nd,nax,nay,nx,ny));
            }
        }
    }
}
int main(){
    scanf("%d %d",&M,&N);
    scanf("%d %d %d %d",&U,&V,&W,&L);
    int sx,sy;
    int x,y;  
    int prevx,prevy; 
    scanf("%d %d",&sy,&sx);
    prevx = sx;
    prevy = sy;
    for(int i = 1;i<U;i++){ 
        scanf("%d %d",&y,&x);
        int dir = retDir(prevx,prevy,x,y);
        while(prevx != x || prevy != y){
            arr[prevx][prevy] = 1;
            prevx += dx[dir];
            prevy += dy[dir];
        }
    }
    arr[x][y] = 1;
    scanf("%d %d",&prevy,&prevx);
    for(int i = 1;i<V;i++){
        scanf("%d %d",&y,&x);
        int dir = retDir(prevx,prevy,x,y);
        while(prevx != x || prevy != y){
            arr[prevx][prevy] = 2;
            prevx += dx[dir];
            prevy += dy[dir];
        }
    }
    arr[x][y] = 2;
    int x1,x2,y1,y2;
    for(int i = 0;i<W;i++){
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        int dir = retDir(x1,y1,x2,y2);
        while(x1 != x2 || y1 != y2){
            arr[x1][y1] = i+3;
            x1 += dx[dir];
            y1 += dy[dir];
        }
        arr[x1][y1] = i+3;
    }
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            dist[i][j] = INF;
    Dijk(sx,sy);
    printf("%d\n",dist[x][y] == INF ? -1:dist[x][y]);
}