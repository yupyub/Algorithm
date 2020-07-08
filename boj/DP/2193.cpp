#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[100][2];
int main(){
	int n;
	scanf("%d",&n);
	dp[0][1] = 1;
	for(int i = 1;i<n;i++){
		dp[i][1] = dp[i-1][0];
		dp[i][0] = dp[i-1][1]+dp[i-1][0];
	}
	printf("%lld\n",dp[n-1][0]+dp[n-1][1]);
}