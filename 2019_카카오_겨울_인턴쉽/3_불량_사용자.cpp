#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int check[8];
set<int> s;
int binary(){
    int ret = 0;
    for(int i = 0;i<8;i++){
        ret *=2;
        ret += check[i];
    }
    return ret;
}
void dfs(vector<string>& user_id, vector<string>& banned_id,int idx){
    
    if(idx == banned_id.size()){
        s.insert(binary());
        return;
    }
    for(int i = 0;i<user_id.size();i++){
        if(check[i])
            continue;
        if(user_id[i].length() != banned_id[idx].length())
            continue;
        int flag = 0;
        for(int j = 0;j<banned_id[idx].length();j++){
            if(banned_id[idx][j] == '*')
                continue;
            if(user_id[i][j] != banned_id[idx][j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            check[i] = 1;
            dfs(user_id, banned_id,idx+1);
            check[i] = 0;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id,banned_id,0);
    answer = (int)s.size();
    return answer;
}