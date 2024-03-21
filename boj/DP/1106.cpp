#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int C, N;
    scanf("%d %d", &C, &N);
    int cost[20];
    int customer[20];
    for(int i = 0; i<N; i++){
        scanf("%d %d", &cost[i], &customer[i]);
    }
    int dp[1101];
    int ans = 99999999;
    dp[0] = 0;
    for(int i = 1; i<1101; i++){
        dp[i] = 99999999;
        for(int j = 0; j<N; j++){
            if(i >= customer[j])
                dp[i] = min(dp[i], dp[i-customer[j]] + cost[j]);
        }
        if(i >= C)
            ans = min(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}