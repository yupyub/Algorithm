#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int N;
    scanf("%d", &N);
    int map[17][17];
    for(int i = 1; i<=N;i++){
        for(int j = 1; j<=N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int dp[17][17][3] = {0, };
    /*
    dir = 0 : ==
    dir = 1 : ||
    dir = 2 : \\
    */
    dp[1][2][0] = 1;
    for(int i = 1; i<=N;i++){
        for(int j = 1; j<=N; j++){
            if(map[i][j] == 1)
                continue;
            dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];
            dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
            if(map[i][j] == 1 || map[i][j-1] == 1 || map[i-1][j] == 1)
                continue;
            dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }
    printf("%d\n", dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);
    return 0;
}