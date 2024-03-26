#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int R, C, M;
vector<tuple<int, int, int, int, int> > shark;
int pool1[100][100];
int pool2[100][100];
int dead[10000];
int dir_change(int x){
    if(x == 0 || x == 1)
        return (x+1)%2;
    else if(x == 2)
        return 3;
    else
        return 2;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void shark_move(int idx){
    int z = get<0>(shark[idx]);
    int r = get<1>(shark[idx]);
    int c = get<2>(shark[idx]);
    int s = get<3>(shark[idx]);
    int d = get<4>(shark[idx]);
    int remain = s;
    if(d == 0 || d == 1){
        remain = s % ((R-1) * 2);
    }
    else{
        remain = s % ((C-1) * 2);
    }
    int nr, nc;
    while(remain--){
        nr = r + dx[d];
        nc = c + dy[d];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C){
            d = dir_change(d);
            nr = r + dx[d];
            nc = c + dy[d];
        }
        r = nr;
        c = nc;
    }
    shark[idx] = make_tuple(z, r, c, s, d);
    if(pool2[r][c]){
        dead[pool2[r][c] - 1] = 1;
    }
    pool2[r][c] = idx + 1;
}
int shark_catch(int y){
    for(int x = 0; x < R; x++){
        if(pool1[x][y]){
            dead[pool1[x][y] - 1] = 1;
            return get<0>(shark[pool1[x][y]-1]);
        }
    }
    return 0;
}

int main(){
    scanf("%d %d %d", &R, &C, &M);
    int r, c, s, d, z;
    for(int i = 0; i<M; i++){
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        r--;
        c--;
        d--;
        shark.push_back(make_tuple(z, r, c, s, d));
    }
    sort(shark.begin(), shark.end());
    for(int i = 0; i<M; i++){
        int r = get<1>(shark[i]);
        int c = get<2>(shark[i]);
        pool1[r][c] = i+1;
    }
    int ans = 0;
    for(int y = 0; y<C; y++){
        ans += shark_catch(y);
        for(int i = 0; i<M; i++){
            if(!dead[i]){
                shark_move(i);
            }
        }
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                pool1[i][j] = pool2[i][j];
                pool2[i][j] = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}