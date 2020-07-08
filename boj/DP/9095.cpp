#include <cstdio>
#include <algorithm>
using namespace std;
int dp[11];
int main(){
	int t,n;
	scanf("%d",&t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i<11;i++)
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	while(t--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}