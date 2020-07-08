#include <cstdio>
#include <algorithm>
using namespace std;
int arr[300];
int dp[300][2];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	dp[0][0] = arr[0];
	dp[1][0] = arr[1];
	dp[1][1] = arr[0]+arr[1];
	for(int i = 2;i<n;i++){
		dp[i][0] = max(dp[i-2][0],dp[i-2][1])+arr[i];
		dp[i][1] = dp[i-1][0]+arr[i];
	}
	printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
}
	
	