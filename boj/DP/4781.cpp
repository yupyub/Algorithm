#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int cal[5000];
    int cost[5000];
    int dp[10001];
    while(1){
        int n, m;
        float mf;
        scanf("%d %f", &n, &mf);
        m = (int)(mf * 100 + 0.1);
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i<n; i++){
            scanf("%d %f", &cal[i], &mf);
            cost[i] = (int)(mf * 100 + 0.1);
        }
        dp[0] = 0;
        for(int i = 1; i<=m; i++){
            dp[i] = 0;
            for(int j = 0; j<n; j++){
                if(cost[j] <= i){
                    dp[i] = max(dp[i], dp[i-cost[j]] + cal[j]);
                }
                dp[i] = max(dp[i], dp[i-1]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}