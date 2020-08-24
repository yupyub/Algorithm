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
int N,M,Q;
pair<int,int> arr[100000];
int already[100001];
int quary[100001];
int parent[100001];
int Count[100001];
int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}
int Union(int x,int y){
    x = Find(x);
    y = Find(y);
    int ret = Count[x] * Count[y];
    Count[x] += Count[y];
    parent[y] = x;
    return ret;
}
int main(){
    scanf("%d %d %d",&N,&M,&Q);
    for(int i = 1;i<=N;i++)
        parent[i] = i, Count[i] = 1;
    for(int i = 1;i<=M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        arr[i] = make_pair(u,v);
    }
    for(int i = 0;i<Q;i++){
        scanf("%d",&quary[i]);
        already[quary[i]] = 1;
    }
    for(int i = 1;i<=M;i++){
        if(!already[i]){
            int u = arr[i].first;
            int v = arr[i].second;
            if(Find(u) != Find(v))
                Union(u,v);
        }
    }
    ll ans = 0;
    for(int i = Q-1;i>=0;i--){
        int ii = quary[i];
        int u = arr[ii].first;
        int v = arr[ii].second;
        if(Find(u) != Find(v))
            ans += (ll)Union(u,v);
    }
    printf("%lld\n",ans);
}