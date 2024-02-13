#include <cstdio>
#include <queue>
#include <utility>
using namespace std;


int main(){
    int s, e;
    scanf("%d %d", &s, &e);
    int visit[100001];
    for(int i = 0; i<100001; i++){
        visit[i] = 987654321;
    }
    priority_queue<pair<int, int> > q;
    visit[s] = 0;
    q.push(make_pair(0, s));
    int n, d, nx;
    while(!q.empty()){
        d = -q.top().first;
        n = q.top().second;
        q.pop();
        nx = n * 2;
        if(0 <= nx && nx < 100001 && visit[nx] > d){
            visit[nx] = d;
            q.push(make_pair(-d, nx));
        }
        nx = n + 1;
        if(0 <= nx && nx < 100001 && visit[nx] > d+1){
            visit[nx] = d+1;
            q.push(make_pair(-d-1, nx));
        }
        nx = n - 1;
        if(0 <= nx && nx < 100001 && visit[nx] > d+1){
            visit[nx] = d+1;
            q.push(make_pair(-d-1, nx));
        }
    }
    printf("%d\n", visit[e]);
    return 0;
}