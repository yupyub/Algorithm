#include <cstdio>
int main(){
    int w,h;
    scanf("%d %d",&w,&h);
    int dp[101][101][2][2] = {0,};
    for(int i = 1;i<=w;i++)
        dp[i][1][0][0] = 1;
    for(int j = 1;j<=h;j++)
        dp[1][j][1][0] = 1;
    for(int i = 2;i<=w;i++){
        for(int j = 2;j<=h;j++){
            dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1])%100000;
            dp[i][j][0][1] = dp[i-1][j][1][0];
            dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1])%100000;
            dp[i][j][1][1] = dp[i][j-1][0][0];
        }
    }
    printf("%d", (dp[w][h][0][0] + dp[w][h][0][1] +  dp[w][h][1][0]+ dp[w][h][1][1])%100000);
}
