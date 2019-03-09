#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 987654321987654321;
typedef long long ll;
ll dist[2005][2005];
int cost[2005][2005][4];
vector<tuple<int,int,int,int,int> >rec;
vector<int> X,Y;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int sx,sy,ex,ey;
void update(int x,int y,int dir,int c){
    cost[x][y][dir] = c;
    cost[x+dx[dir]][y+dy[dir]][dir+2] = c;
}
ll A_Star(){
    priority_queue<tuple<ll,int,int,char> >pq;
    dist[sx][sy] = 0;
    pq.push(make_tuple(0,sx,sy,-1));
    int x,y,dir,nx,ny;
    ll len;
    while(!pq.empty()){
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        dir = get<3>(pq.top());
        pq.pop();
        if(x == ex && y == ey) return dist[x][y];
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=X.size()||ny>=Y.size()) continue;
            len = abs(X[nx]-X[x]) + abs(Y[ny] - Y[y]);
            if(dist[nx][ny] > dist[x][y] + cost[x][y][i] *len){
                dist[nx][ny] = dist[x][y] + cost[x][y][i] * len;
                /*
                // h(n) >= 10
                // Beyond this value, Consistency is lost.
                // It means that optimal solution cannot be found.
                */
                pq.push(make_tuple(-(dist[nx][ny] + 10*(abs(X[ex] - X[nx]) + abs(Y[ex] - Y[ny]))),nx,ny,(i+2)%4));
            }
        }
    }
}

int main(){
    int rsx,rsy,rex,rey;
    scanf("%d%d%d%d",&rsx,&rsy,&rex,&rey);
    X.push_back(rsx);
    X.push_back(rex);
    Y.push_back(rsy);
    Y.push_back(rey);
    int n,a,b,c,d,e;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        rec.push_back(make_tuple(a,b,c,d,e));
        X.push_back(a);
        X.push_back(c);
        Y.push_back(b);
        Y.push_back(d);
    }
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sx = lower_bound(X.begin(),X.end(),rsx)-X.begin();
    sy = lower_bound(Y.begin(),Y.end(),rsy)-Y.begin();
    ex = lower_bound(X.begin(),X.end(),rex)-X.begin();
    ey = lower_bound(Y.begin(),Y.end(),rey)-Y.begin();
    for(int i = 0;i<2005;i++){
        for(int j = 0;j<2005;j++){
            dist[i][j] = INF;
            for(int k = 0;k<4;k++)
                cost[i][j][k] = 10;
        }
    }
    for(int i = 0;i<rec.size();i++){
        a = get<0>(rec[i]);
        b = get<1>(rec[i]);
        c = get<2>(rec[i]);
        d = get<3>(rec[i]);
        e = get<4>(rec[i]);
        a = lower_bound(X.begin(),X.end(),a) - X.begin();
        b = lower_bound(Y.begin(),Y.end(),b) - Y.begin();
        c = lower_bound(X.begin(),X.end(),c) - X.begin();
        d = lower_bound(Y.begin(),Y.end(),d) - Y.begin();
        for(int y = b+1;y<d;y++)
            update(a,y,1,e);
        for(int x = a+1;x<c;x++)
            update(x,b,0,e);
        for(int x = a+1;x<c;x++){
            for(int y = b+1;y<d;y++){
                update(x,y,0,e);
                update(x,y,1,e);
            }
        }
    }
    ll ans = A_Star();
    printf("%lld",ans);
}
