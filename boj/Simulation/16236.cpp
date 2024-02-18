#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int map[20][20];
tuple<int, int, int, int> shark;

int bfs(){
    int sx = get<0>(shark);
    int sy = get<1>(shark);
    int _size = get<2>(shark);
    int eat = get<3>(shark);

    int visit[20][20] = {0, };
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    queue<tuple<int, int, int> > q;
    vector<tuple<int, int, int> > can_eat;
    visit[sx][sy] = 1;
    q.push(make_tuple(sx, sy, 0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        if(map[x][y] != 0 && map[x][y] < _size){
            if(can_eat.empty() || d == get<2>(can_eat[0]))
                can_eat.push_back(make_tuple(x, y, d));
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if(map[nx][ny] > _size)
                continue;
            if(visit[nx][ny] == 0){
                visit[nx][ny] = 1;
                q.push(make_tuple(nx, ny, d+1));
            }
        }
    }
    if(can_eat.empty())
        return 0;
    sort(can_eat.begin(), can_eat.end());
    int x = get<0>(can_eat[0]);
    int y = get<1>(can_eat[0]);
    int d = get<2>(can_eat[0]);
    map[x][y] = 0;
    get<0>(shark) = x;
    get<1>(shark) = y;
    get<3>(shark) += 1;
    if(get<2>(shark) == get<3>(shark)){
        get<2>(shark) += 1;
        get<3>(shark) = 0;
    }
    return d;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 9){
                shark = make_tuple(i, j, 2, 0);
                map[i][j] = 0;
            }
        }
    }
    int t = 0;
    while(true){
        int d = bfs();
        if(d == 0)
            break;
        t += d;
    }
    printf("%d\n", t);
    

    return 0;
}