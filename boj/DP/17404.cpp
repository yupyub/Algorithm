#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int cost[1000][3];
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        for(int j = 0; j<3; j++)
            scanf("%d", &cost[i][j]);
    int dp[1000][3][3];
    dp[0][0][0] = cost[0][0];
    dp[0][0][1] = dp[0][0][2] = 1000001;
    dp[0][1][1] = cost[0][1];
    dp[0][1][0] = dp[0][1][2] = 1000001;
    dp[0][2][2] = cost[0][2];
    dp[0][2][0] = dp[0][2][1] = 1000001;
    for(int i = 1; i<N; i++){
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                dp[i][j][k] = min(dp[i-1][(j+1)%3][k], dp[i-1][(j+2)%3][k]) + cost[i][j];
            }
        }
    }
    int ans = 1000001;
    for(int j = 0; j<3; j++){
        for(int k = 0; k<3; k++){
            if(j == k)
                continue;
            ans = min(ans, dp[N-1][j][k]);
        }
    }
    printf("%d\n", ans);
    return 0;
}