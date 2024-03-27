#include <cstdio>

int main(){
    long long MOD = 1000000007;
    long long dp[5001] = {0, };
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    // 첫 번째 여는 괄호를 닫는 괄호가 들어가는 위치에 대한 경우를 다 센다.
    for(int i = 6; i<5001; i+=2){
        for(int j = 2; j<=i; j+=2){
            dp[i] = (dp[i] + (dp[j-2]) * (dp[i-j])) % MOD;
        }
    }
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}