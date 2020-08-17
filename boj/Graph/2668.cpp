#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 987654321;
vector<int> inst;
vector<int> ans;
int g[101];
int visit[101];
void dfs(int n){
    int flag = 0;
    for(int i = 0;i<inst.size();i++){
        if(inst[i] == g[n])
            flag = 1;
        if(flag)
            ans.push_back(inst[i]);
    }
    if(visit[g[n]])
        return;
    inst.push_back(g[n]);
    visit[g[n]] = 1;
    dfs(g[n]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%d",&g[i]);
    for(int i = 1;i<=n;i++){
        if(!visit[i]){
            inst.clear();
            visit[i] = 1;
            inst.push_back(i);
            dfs(i);
        }
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i : ans)
        printf("%d\n",i);
}