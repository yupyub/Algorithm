#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[501];
vector<int> start;
int build_time[501];
int in_degree[501];
int total[501];

void dfs(int x){
    for(int nx : graph[x]){
        in_degree[nx]--;
        total[nx] = max(total[nx], total[x] + build_time[nx]);
        if(in_degree[nx] == 0){
            dfs(nx);
        }
    }
}

int main(){
    int N, a;
    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        scanf("%d", &build_time[i]);
        while(1){
            scanf("%d", &a);
            if(a == -1)
                break;
            graph[a].push_back(i);
            in_degree[i]++;
        }
        if(in_degree[i] == 0)
            start.push_back(i);
    }
    for(int x : start){
        total[x] = build_time[x];
        dfs(x);
    }
    for(int i = 1; i<=N; i++){
        printf("%d\n", total[i]);
    }
    return 0;
}