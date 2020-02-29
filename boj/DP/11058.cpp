#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[101];
int main(){
	int n;
	scanf("%d",&n);
	dp[1] =1;
	for(int i = 1;i<n;i++){
		dp[i+1] = max(dp[i+1],dp[i]+1);
		for(int j = 3;j<=n;j++){
			dp[i+j] = max(dp[i+j],dp[i]*(j-1));	
		}
	}
	printf("%lld\n",dp[n]);
}