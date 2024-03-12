#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool check_key(int x, int y, char map[][102], set<char> *keys){
    if('A' <= map[x][y] && map[x][y] <= 'Z'){
        char k = map[x][y] - 'A' + 'a';
        if((*keys).find(k) != (*keys).end()){
            map[x][y] = '.';
            return true;
        }
    }
    else if('a' <= map[x][y] && map[x][y] <= 'z'){
        (*keys).insert(map[x][y]);
        map[x][y] = '.';
    }
    return false;
}

int dfs(int h, int w, int x, int y, char map[][102], int visit[][102], set<char> *keys){
    int ret = 0;
    visit[x][y] = 1;
    check_key(x, y, map, keys);
    if(map[x][y] == '$'){
        map[x][y] = '.';
        ret += 1;
    }
    else if(map[x][y] != '.')
        return ret;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= h || nx < 0 || ny >= w || ny < 0)
            continue;
        if(map[nx][ny] == '*')
            continue;
        if(visit[nx][ny] && !check_key(nx, ny, map, keys))
            continue;
        ret += dfs(h, w, nx, ny, map, visit, keys);
    }
    return ret;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int h, w;
        char map[102][102];
        int visit[102][102];
        set<char> keys;
        scanf("%d %d", &h, &w);
        for(int i = 0; i<h; i++){
            scanf("%s", &map[i+1][1]);
        }
        for(int i = 0; i<h+2; i++){
            if(i == 0 || i == h+1){
                for(int j = 0; j<w+2; j++)
                    map[i][j] = '.';
            }
            map[i][0] = '.';
            map[i][w+1] = '.';
        }
        char tmp[27];
        scanf("%s", tmp);
        if(tmp[0] != '0'){
            int l = strlen(tmp);
            for(int i = 0; i<l; i++){
                keys.insert(tmp[i]);
            }
        }
        int iter = 60;
        int ans = 0;
        while(iter--){
            for(int i = 0; i < h+2; i++)
                for(int j = 0; j < w+2; j++)
                    visit[i][j] = 0;
            ans += dfs(h+2, w+2, 0, 0, map, visit, &keys);
        }
        printf("%d\n", ans);
    }
    return 0;
}