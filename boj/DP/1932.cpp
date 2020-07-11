#include <cstdio>
#include <algorithm>
using namespace std;
int arr[500][500];
int dp[500][500];
int main(){
	int n;
	scanf("%d",&n);
	int m = 0;
	for(int i = 0;i<n;i++)
		for(int j =0;j<i+1;j++)
			scanf("%d",&arr[i][j]);
	for(int i = 0;i<n-1;i++)
		for(int j =0;j<i+1;j++){
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]+arr[i][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+arr[i][j]);
		}
	int ans =0;
	for(int i = 0;i<n+1;i++)
		ans = max(ans,dp[n-1][i]+arr[n-1][i]);
	printf("%d\n",ans);
}