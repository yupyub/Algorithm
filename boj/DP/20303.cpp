#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int candy[30000];
int visi[30000];
vector<int> rel[30000];
int dp[30001][3000] = {0, };

pair<int, int> dfs(int x){
    visi[x] = 1;
    int cnt_candy = 0;
    int cnt_friend = 0;
    pair<int, int> tmp;
    for(int nx: rel[x]){
        if(!visi[nx]){
            tmp = dfs(nx);
            cnt_candy += tmp.first;
            cnt_friend += tmp.second;
        }
    }
    return make_pair(cnt_candy + candy[x], cnt_friend + 1);
}

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i<N; i++){
        scanf("%d", &candy[i]);
    }
    int u, v;
    for(int i = 0; i<M; i++){
        scanf("%d %d", &u, &v);
        rel[u-1].push_back(v-1);
        rel[v-1].push_back(u-1);
    }
    pair<int, int> tmp;
    vector<pair<int, int> > friends;
    for(int i = 0; i<N; i++){
        if(!visi[i]){
            tmp = dfs(i);
            friends.push_back(tmp);
        }
    }
    int l = friends.size();
    int c, w;
    
    for(int i = 1; i<=l; i++){
        c = friends[i-1].first;
        w = friends[i-1].second;
        for(int j = 0; j<3000; j++){
            if(j-w >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + c);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n", dp[l][K-1]);
    return 0;
}