#include <cstdio>
#include <algorithm>
using namespace std;
int arr[300];
int dp[300][100001];
int back[300];
int main(){
	int n,tot = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		tot += arr[i];
	}
	dp[0][arr[0]] = arr[0];
	for(int i = 1;i<n;i++){
		for(int j = 0;j<100001;j++) dp[i][j] = dp[i-1][j];
		for(int j = arr[i];j<100001;j++){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]);
		}
	}
	int ans = 0;
	for(int i = tot;i<100001;i++){
		ans = max(dp[n-1][i],ans);
	}
	printf("%d\n",ans);
}