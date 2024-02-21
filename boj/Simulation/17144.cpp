#include <cstdio>
#include <utility>
using namespace std;


void diffusion(int dust1[][50], int dust2[][50], int r, int c){
    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};
    for(int x = 0; x<r; x++)
        for(int y = 0; y<c; y++)
            dust2[x][y] = 0;
    for(int x = 0; x<r; x++){
        for(int y = 0; y<c; y++){
            if(dust1[x][y] < 0)
                continue;
            int s = dust1[x][y]/5;
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >=r || ny < 0 || ny >= c)
                    continue;
                if(dust1[nx][ny] == -1)
                    continue;
                dust2[nx][ny] += s;
                dust2[x][y] -= s;
            }
        }
    }
    for(int x = 0; x<r; x++)
        for(int y = 0; y<c; y++)
            dust1[x][y] += dust2[x][y];
    
}

void clean(int dust[][50], pair<int, int> cleaner, int r, int c, int cycle){
    int dx[2][4] = {{0, -1, 0, 1}, {0, 1, 0, -1}};
    int dy[2][4] = {{1, 0, -1, 0}, {1, 0, -1, 0}};
    int dir = 0;
    int x = cleaner.first;
    int y = cleaner.second;
    int nx = x + dx[cycle][dir];
    int ny = y + dy[cycle][dir];
    int prev = 0;
    while(dust[nx][ny] != -1){
        int temp = dust[nx][ny];
        dust[nx][ny] = prev;
        prev = temp;
        x = nx;
        y = ny;
        nx = x + dx[cycle][dir];
        ny = y + dy[cycle][dir];
        if(nx < 0 || nx >=r || ny < 0 || ny >= c){
            dir += 1;
            nx = x + dx[cycle][dir];
            ny = y + dy[cycle][dir];
        }
    }
}


int main(){
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    pair<int, int> cleaner1;
    pair<int, int> cleaner2;
    int dust1[50][50];
    int dust2[50][50];
    int flag = 0;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d", &dust1[i][j]);
            if(dust1[i][j] == -1){
                if(flag)
                    cleaner2 = make_pair(i, j);
                else{
                    cleaner1 = make_pair(i, j);
                    flag = 1;
                }
            }
        }
    }
    while(t--){
        diffusion(dust1, dust2, r, c);
        clean(dust1, cleaner1, r, c, 0);
        clean(dust1, cleaner2, r, c, 1);
    }
    int ans = 0;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(dust1[i][j] == -1)
                continue;
            ans += dust1[i][j];
        }
    }
    printf("%d\n", ans);

    return 0;
}