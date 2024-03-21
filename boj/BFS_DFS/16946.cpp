#include <cstdio>
#include <set>
using namespace std;

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};
int N, M;
int arr[1000][1000];
int visited[1000][1000];
int counter[1000000];

void dfs(int x, int y, int cnt){
    visited[x][y] = cnt;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if(!visited[nx][ny] && arr[nx][ny] != 1){
            dfs(nx, ny, cnt);
        }
    }
}

int main(){
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    int cnt = 1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(!visited[i][j] && arr[i][j] != 1)
                dfs(i, j, cnt++);
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            counter[visited[i][j]]++;
        }
    }
    int pr, nx, ny;
    for(int x = 0; x<N; x++){
        for(int y = 0; y<M; y++){
            pr = 0;
            set<int> s;
            if(arr[x][y] == 1){
                for(int i = 0; i<4; i++){
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if(arr[nx][ny] == 1)
                        continue;
                    s.insert(visited[nx][ny]);
                }
                for(int a: s){
                    pr += counter[a];
                }
                pr++;
            }
            printf("%d", pr%10);
        }
        printf("\n");
    }
}