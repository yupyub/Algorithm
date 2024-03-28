#include <cstdio>
#include <algorithm>
using namespace std;

int num[100000];
int dp[100000][2];

int main(){
    int N;    
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &num[i]);
    }
    dp[0][0] = num[0];
    dp[0][1] = 0;
    int ans = num[0];
    for(int i = 1; i<N; i++){
        dp[i][0] = max(num[i], dp[i-1][0] + num[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + num[i]);
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    printf("%d\n", ans);
    return 0;
}