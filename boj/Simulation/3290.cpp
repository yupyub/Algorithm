#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int N, K;
int arr[100][100];
int visits[100][100];
queue<pair<int, int> >q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int moving(int* x, int* y, int dir){
    int nx = *x + dx[dir];
    int ny = *y + dy[dir];
    if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        return 0;
    if(visits[nx][ny])
        return 0;
    if(arr[nx][ny]){  // apple
        arr[nx][ny] = 0;
        visits[nx][ny] = 1;
        q.push(make_pair(nx, ny));
    }
    else{
        visits[nx][ny] = 1;
        q.push(make_pair(nx, ny));
        visits[q.front().first][q.front().second] = 0;
        q.pop();
    }
    *x = nx;
    *y = ny;
    return 1;
}


int main(){
    scanf("%d", &N);
    scanf("%d", &K);
    int a, b;
    for(int i = 0; i<K; i++){
        scanf("%d %d", &a, &b);
        arr[a-1][b-1] = 1;
    }
    int L;
    char c;
    scanf("%d", &L);
    queue<pair<int, char> > g;
    for(int i = 0; i<L; i++){
        scanf("%d %c", &a, &c);
        g.push(make_pair(a, c));
    }
    int ans = 0;
    q.push(make_pair(0,0));
    visits[0][0] = 1;
    int dir = 1;
    int x = 0, y = 0;
    while(1){
        ans++;
        if(!moving(&x, &y, dir))
            break;
        if(g.front().first == ans){
            if(g.front().second == 'D'){
                dir = (dir + 1)%4;
            }
            else{
                dir = dir - 1;
                if(dir == -1)
                    dir = 3;
            }
            g.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}