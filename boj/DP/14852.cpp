#include <cstdio>
#include <algorithm>
using namespace std;
#define MOD 1000000007

long long dp[1000002];
long long a[1000002];
long long b[1000002];

int main(){
    int N;
    scanf("%d", &N);
    dp[1] = 1;
    for(int i = 2; i<N+2; i++){
        dp[i] = (2*dp[i-1] + dp[i-2] + a[i-1] + b[i-1])%MOD;
        a[i] = (dp[i-1] + a[i-1])%MOD;
        b[i] = (dp[i-1] + b[i-1])%MOD;
    }
    printf("%lld\n", dp[N+1]);
    return 0;
}