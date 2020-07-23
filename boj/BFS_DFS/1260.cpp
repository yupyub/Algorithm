#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int visit1[1001];
int visit2[1001];
vector<vector<int> > v;
void DFS(int x){
    visit1[x] = 1;
    printf("%d ",x);
    for(auto nx : v[x]){
        if(!visit1[nx])
            DFS(nx);
    }
}
void BFS(int sx){
    queue<int> q;
    q.push(sx);
    visit2[sx] = 1;
    while(!q.empty()){
        int x = q.front();
        printf("%d ",x);
        q.pop();
        for(auto nx : v[x]){
            if(!visit2[nx]){
                visit2[nx] = 1;
                q.push(nx);
            }
        }
    }
}
int main(){
    int n,m,st;
    int a,b;
    scanf("%d %d %d",&n,&m,&st);
    v.resize(n+1);
    for(int i = 0;i<m;i++){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    DFS(st);
    printf("\n");
    BFS(st);
    return 0;
}