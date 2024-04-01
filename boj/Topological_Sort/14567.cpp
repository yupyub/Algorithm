#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
int in_degree[1001];
int visited[1001];
int finish[1001];

void dfs(int x){
    visited[x] = 1;
    for(int nx : graph[x]){
        in_degree[nx]--;
        finish[nx] = max(finish[nx], finish[x] + 1);
        if(in_degree[nx] == 0){
            dfs(nx);
        }
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int u, v;
    
    for(int i = 0; i<M; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        in_degree[v] += 1;
    }
    for(int i = 1; i<=N; i++){
        if(in_degree[i] == 0 && !visited[i]){
            finish[i] = 1;
            dfs(i);
        }

    }
    for(int i = 1; i<=N; i++){
        printf("%d ", finish[i]);
    }
    return 0;
}