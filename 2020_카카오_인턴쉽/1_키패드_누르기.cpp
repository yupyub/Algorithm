#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int arr[4][3] = {0,};
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int dist(int sx,int sy,int target){
    queue<tuple<int,int,int> > q;
    q.push(make_tuple(sx,sy,0));
    while(!q.empty()){
        int x = get<0> (q.front());
        int y = get<1> (q.front());
        int d = get<2> (q.front());
        q.pop();
        if(arr[x][y] == target)
            return d;
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >=4 || ny < 0 || ny >=3)
                continue;
            q.push(make_tuple(nx,ny,d+1));
        }
    }
    return 0;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> L = make_pair(3,0);
    pair<int,int> R = make_pair(3,2);
    arr[3][0] = 1;
    arr[3][2] = 2;
    int flag = hand.compare("left") == 0 ? 1 : 2;
    for(int i : numbers){
        if(i == 0)
            i = 10;
        if(i == 1 || i == 4 || i == 7){
            answer.push_back('L');
            arr[L.first][L.second] = 0;
            arr[i/3][0] = 1;
            L = make_pair(i/3,0);
        }
        else if(i == 3 || i == 6 || i == 9){
            answer.push_back('R');
            arr[R.first][R.second] = 0;
            arr[i/3-1][2] = 2;
            R = make_pair(i/3-1,2);
        }
        else{
            int dL = dist(i/3,1,1);
            int dR = dist(i/3,1,2);
            int hand;
            if(dL < dR)
                hand = 1;
            else if(dL > dR)
                hand = 2;
            else
                hand = flag;
            if(hand == 1){
                answer.push_back('L');
                arr[L.first][L.second] = 0;
                arr[i/3][1] = 1;
                L = make_pair(i/3,1);
            }
            else{
                answer.push_back('R');
                arr[R.first][R.second] = 0;
                arr[i/3][1] = 2;
                R = make_pair(i/3,1);
            }
        }
    }
    return answer;
}