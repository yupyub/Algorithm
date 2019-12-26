#include <cstdio>
#include <algorithm>
using namespace std;
int wei[20];
int val[20];
int dp[20][100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&wei[i]);
	for(int i = 0;i<n;i++)
		scanf("%d",&val[i]);
	dp[0][wei[0]] = val[0];
	for(int i = 1;i<n;i++){
		for(int j = 0;j<100;j++) dp[i][j] = dp[i-1][j];
		for(int j = wei[i];j<100;j++){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-wei[i]]+val[i]);
		}
	}
	int ans = 0;
	for(int i = 0;i<100;i++)
		ans = max(dp[n-1][i],ans);
	printf("%d",ans);
}