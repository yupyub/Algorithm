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
const int INF = 987654321;
const int MOD = 987654321;
ll dp[10001];
ll f(int n){
    ll &ret = dp[n];
    if(ret != 0)
        return ret;
    if(n <= 2)
        return ret = 1;
    for(int i = 0;i<=n-2;i+=2){
        ret += (f(i)*f(n-2-i))%MOD;
        ret %= MOD;
    }
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld\n",f(n));
}
//656444295