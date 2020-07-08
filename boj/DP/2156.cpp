#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10000];
int dp[10001][3];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = arr[0];
	for(int i = 1;i<=n;i++){
		dp[i][0] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		dp[i][1] = dp[i-1][0]+arr[i];
		dp[i][2] = dp[i-1][1]+arr[i];
	}
	printf("%d\n",dp[n][0]);
}