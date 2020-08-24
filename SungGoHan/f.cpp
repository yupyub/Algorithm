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
const ll INF = 987654321987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int vis[100000];
vector<pair<int,int> > g[100000];
ll dist[100000];
ll dijk(int s){
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,s));
    dist[s] = 0;
    while(!pq.empty()){
        int d = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        for(auto i : g[n]){
            int nx = i.first;
            int c = i.second;
            if(dist[nx]>dist[n] + c){
                dist[nx] = dist[n] + c;
                pq.push(make_pair(dist[nx],nx));
            }
        }
    }
    return dist[N-1] == INF ? -1 : dist[N-1];
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++){
        scanf("%d",&vis[i]);
        dist[i] = INF;
    }
    vis[N-1] = 0;
    int u,v,c;
    for(int i = 0;i<M;i++){
        scanf("%d %d %d",&u,&v,&c);
        if(!vis[u])
            g[v].push_back(make_pair(u,c));
        if(!vis[v])
            g[u].push_back(make_pair(v,c));
    }
    printf("%lld\n",dijk(0));
}