#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int arr[2][100000];
		int dp[3][100000] = {0,};
		scanf("%d",&n);
		for(int i = 0;i<2;i++)
			for(int j = 0;j<n;j++)
				scanf("%d",&arr[i][j]);
		dp[1][0] = arr[0][0];
		dp[2][0] = arr[1][0];
		for(int i = 1;i<n;i++){
			dp[0][i] = max(dp[1][i-1],dp[2][i-1]);
			dp[1][i] = max(dp[0][i-1],dp[2][i-1])+arr[0][i];
			dp[2][i] = max(dp[0][i-1],dp[1][i-1])+arr[1][i];
		}
		printf("%d\n",max(dp[1][n-1],dp[2][n-1]));
	}
}
