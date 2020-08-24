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
int dp[1001][201][11];
int arr[1001];
int cost(int a,int b){
    if(a<=b)
        return 0;
    return (a-b)*(a-b);
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int i = 0;i<N;i++)
        for(int j = 0;j<=M;j++)
            for(int k = 0;k<=10;k++)
                dp[i][j][k] = INF;
    dp[0][0][arr[0]] = 0;
    for(int i = 0;i<N-1;i++){
        for(int j = 0;j<=M;j++){
            for(int k = 0;k<=10;k++){
                if(dp[i][j][k] == INF)
                    continue;
                int addr = 0;
                while(1){
                    if(j+addr>M || arr[i+1] + addr > 10)
                        break;
                    dp[i+1][j+addr][arr[i+1]+addr] = min(dp[i+1][j+addr][arr[i+1]+addr],dp[i][j][k]+cost(k,arr[i+1]+addr));
                    addr++;
                }
            }
        }
    }
    int ans = INF;
    for(int j = 0;j<=M;j++){
        for(int k = 0;k<=10;k++){
            ans = min(ans,dp[N-1][j][k]);
        }
    }
    printf("%d\n",ans);
}