#include <cstdio>
#include <cmath>
using namespace std;
int N, L, R;
int arr[50][50];
int ch[50][50];
int vi[50][50];
int gvi[50][50];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void simul1(int x, int y, int *total, int *cnt){
    *total += arr[x][y];
    *cnt += 1;
    vi[x][y] = 1;
    gvi[x][y] = 1;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if(gvi[nx][ny])
            continue;
        if(vi[nx][ny])
            continue;
        int v = abs(arr[nx][ny] - arr[x][y]);
        if(L <= v && v <= R){
            simul1(nx, ny, total, cnt);
        }
    }

}
void simul2(int x, int y, int val){
    arr[x][y] = val;
    vi[x][y] = 0;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if(!vi[nx][ny])
            continue;
        simul2(nx, ny, val);
    }
}


int main(){
    scanf("%d %d %d", &N, &L, &R);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int ans = 0;
    int flag = 0;
    while(1){
        flag = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(!gvi[i][j]){
                    int total = 0;
                    int cnt = 0;
                    simul1(i, j, &total, &cnt);
                    if(cnt > 1)
                        flag = 1;
                    simul2(i, j, total / cnt);
                }
            }
        }
        if(!flag)
            break;
        ans++;
        for(int i = 0; i<N; i++)
            for(int j = 0; j<N; j++)
                gvi[i][j] = 0;
    }
    printf("%d\n", ans);
    return 0;
}