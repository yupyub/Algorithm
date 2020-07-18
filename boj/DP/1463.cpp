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
int dp[1000001];
int main(){
    for(int i = 0;i<1000001;i++)
        dp[i] = INF;
    dp[1] = 0;
    for(int i = 1;i<1000000;i++){
        if(i*3<1000001)
            dp[i*3] = min(dp[i*3],dp[i]+1);
        if(i*2<1000001)
            dp[i*2] = min(dp[i*2],dp[i]+1);
        dp[i+1] = min(dp[i+1],dp[i]+1);
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",dp[n]);
}