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
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int ans;
vector<vector<char> > arr;
void dfs(int d,int flop,char flag,int ret){
    if(d == N){
        ans = min(ans,ret);
        return;
    }
    if(flop){
        int r1 = 0; // 1010
        int r2 = 0; // 0101
        for(int j = 0;j<M;j++){
            if(arr[d][j] == flag){
                r1 += (j+1)%2;
                r2 += (j)%2;
            }
            else{
                r1 += (j)%2;
                r2 += (j+1)%2;
            }
        }
        ret += min(r1,r2);
    }
    else{
        for(int j = 0;j<M;j++){
            if(arr[d][j] != flag)
                ret++;
        }
    }
    dfs(d+1,(flop+1)%2,flag,ret);
}
int main(){
    scanf("%d %d",&N,&M);
    arr.resize(N);
    for(int i = 0;i<N;i++)
        arr[i].resize(M+1);
    char str[1000001];
    for(int i = 0;i<N;i++){
        scanf("%s",str);
        for(int j = 0;j<M;j++)
            arr[i][j] = str[j];
    }
    if(N>=4 && M>=4){
        printf("-1\n");
        return 0;
    }
    if(N<2 || M<2){
        printf("0\n");
        return 0;
    }
    ans = INF;
    dfs(0,0,'1',0);
    dfs(0,1,'1',0);
    dfs(0,0,'0',0);
    dfs(0,1,'0',0);
    printf("%d\n",ans);
}