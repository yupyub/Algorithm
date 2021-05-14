#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > g;
vector<vector<int> > rule;
int indegree[200001] = {0,};
int visit[200001] = {0,};
int count = 0;
void dfs(int n){
    count++;
    for(int nxt : g[n]){
        indegree[nxt]--;
        if(indegree[nxt] == 0)
            dfs(nxt);
    }
    for(int nxt : rule[n]){
        indegree[nxt]--;
        if(indegree[nxt] == 0)
            dfs(nxt);
    }
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    g.resize(n);
    for(int i = 0;i<path.size();i++){
        g[path[i][0]].push_back(path[i][1]);
        g[path[i][1]].push_back(path[i][0]);
    }
    for(int i = 1;i<n;i++)
        indegree[i] = 1;
    rule.resize(n);
    for(int i = 0;i<order.size();i++){
        rule[order[i][0]].push_back(order[i][1]);
        indegree[order[i][1]]++;
    }
    if(indegree[0] != 0)
        answer = false;
    else{
        dfs(0);
        if(count != n)
            answer = false;
    }
    return answer;
}