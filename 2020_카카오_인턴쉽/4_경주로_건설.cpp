#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int N = board.size();
    int M = board[0].size();
    int dist[30][30][4];
    for(int i = 0;i<30;i++)
        for(int j = 0;j<30;j++)
            dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = 987654321;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int> >,greater<tuple<int,int,int,int> > >pq;
    pq.push(make_tuple(0,0,0,1));
    pq.push(make_tuple(0,0,0,2));
    dist[0][0][1] = 0;
    dist[0][0][2] = 0;
    
    while(!pq.empty()){
        int cost = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int dir = get<3>(pq.top());
        pq.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int c = 1;
            if(i != dir)
                c = 6;
            if(nx<0 || nx>=N || ny<0 || ny>=M)
                continue;
            if(board[nx][ny] == 1)
                continue;
            if(dist[nx][ny][i] > cost + c){
                dist[nx][ny][i] = cost + c;
                pq.push(make_tuple(dist[nx][ny][i],nx,ny,i));
            }
        }
    }
    for(int i = 0;i<4;i++){
        answer = min(answer,dist[N-1][M-1][i]);
    }
    answer *= 100;
    return answer;
}