#include <cstdio>
#include <algorithm>
using namespace std;
int arr[3][1001];
int dp[3][1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<3;j++)
			scanf("%d",&arr[j][i]);
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = arr[2][0];
	for(int i = 1;i<n;i++)
		for(int j = 0;j<3;j++)
			dp[j][i] = min(dp[(j+1)%3][i-1],dp[(j+2)%3][i-1]) + arr[j][i];
	printf("%d",min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1])));
}
	