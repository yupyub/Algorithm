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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int cost[101][101];
int main(){
    int V,E;
    scanf("%d %d",&V,&E);
    for(int i = 1;i<=V;i++)
        for(int j = 1;j<=V;j++)
            cost[i][j] = INF;
    int u,v,c;
    for(int i = 0;i<E;i++){
        scanf("%d %d %d",&u,&v,&c);
        cost[u][v] = min(cost[u][v],c);
        cost[v][u] = min(cost[v][u],c);
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for(int k = 1;k<=V;k++)
        for(int i = 1;i<=V;i++)
            for(int j = 1;j<=V;j++)
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
    int mini = INF;
    for(int i = 1;i<=V;i++){
        if(i == x || i == y)
            continue;
        mini = min(mini, cost[x][i]+cost[i][y]);
    }
    vector<int> cand;
    for(int i = 1;i<=V;i++){
        if(i == x || i == y)
            continue;
        if(mini<cost[x][i]+cost[i][y])
            continue;
        if(cost[x][i] <= cost[i][y])
            cand.push_back(i);
    }
    sort(cand.begin(),cand.end());
    mini = INF;
    for(int i : cand){
        mini = min(mini,cost[x][i]);
    }
    int ans = 0;
    for(int i : cand){
        if(mini == cost[x][i]){
            ans = i;
            break;
        }
    }
    printf("%d\n",ans == 0 ? -1 : ans);
}