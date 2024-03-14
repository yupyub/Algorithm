#include <cstdio>
#include <set>
using namespace std;

int parent[1000000];
int Find(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    parent[a] = Find(parent[b]);
}
int dx(char c){
    if(c == 'U')
        return -1;
    else if(c == 'D')
        return 1;
    return 0;
}
int dy(char c){
    if(c == 'L')
        return -1;
    else if(c == 'R')
        return 1;
    return 0;
}
void dfs(int n, int m, char arr[][1001], int visit[][1000], int x, int y){
    visit[x][y] = 1;
    int nx = x + dx(arr[x][y]);
    int ny = y + dy(arr[x][y]);
    Union(x * m + y, nx * m + ny); // a -> b
    if(!visit[nx][ny])
        dfs(n, m, arr, visit, nx, ny);
}
int main(){
    int n, m;
    char arr[1000][1001];
    int visit[1000][1000] = {0, };
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        scanf("%s", arr[i]);
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            parent[i * m + j] = i * m + j;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visit[i][j])
                dfs(n, m, arr, visit, i, j);
        }
    }
    set<int> ans;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans.insert(Find(i * m + j));
        }
    }
    printf("%d\n", (int)ans.size());
    return 0;
}