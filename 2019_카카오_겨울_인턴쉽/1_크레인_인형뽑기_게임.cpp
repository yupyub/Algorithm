#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int highst[30];
    int H = board.size();
    int W = board[0].size();
    for(int i = 0;i<moves.size();i++)
        moves[i]--;
    for(int i = 0;i<W;i++)
        highst[i] = 100;
    for(int i = 0;i<H;i++)
        for(int j = 0;j<W;j++)
            if(board[i][j] != 0)
                if(highst[j] > i)
                    highst[j] = i;
    stack<int> st;
    for(int mv : moves){
        if(highst[mv] >= H)
            continue;
        int doll = board[highst[mv]][mv];
        highst[mv]++;
        if(st.empty()){
            st.push(doll);
            continue;
        }
        if(st.top() == doll){
            st.pop();
            answer+=2;
        }
        else{
            st.push(doll);
        }
    }
    return answer;
}