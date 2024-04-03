#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 9876543987654321

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<pair<int, int> > graph[100000];
    ll dist[100000];
    int u, v, t;
    for(int i = 0; i<N; i++){
        scanf("%d", &u);
        dist[i] = INF;
        if(u == 1)
            dist[i] = -1;
    }
    dist[N-1] = INF;
    for(int i = 0; i<M; i++){
        scanf("%d %d %d", &u, &v, &t);
        graph[u].push_back(make_pair(v, t));
        graph[v].push_back(make_pair(u, t));
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    ll d;
    int x;
    while(!pq.empty()){
        d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if(dist[x] < d)
            continue;
        for(auto nx: graph[x]){
            if(dist[nx.first] > d + nx.second){
                dist[nx.first] = d + nx.second;
                pq.push(make_pair(dist[nx.first], nx.first));
            }
        }
    }
    printf("%lld\n", dist[N-1] == INF ? -1 : dist[N-1]);
    return 0;
}