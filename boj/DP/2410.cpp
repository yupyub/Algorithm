#include <cstdio>
#include <vector>
using namespace std;
int tw[20];
int dp[1000001][20];
int main(){
	int n,a = 0,b = 1;
	scanf("%d",&n);
	while(a<20){
		tw[a] = b;
		a++;
		b*=2;
	}
	for(int i = 0;i<=n;i++){
		dp[i][0] = 1;
		for(int j = 1;j<20;j++){
			if(i>=tw[j]) dp[i][j] = (dp[i][j-1] + dp[i-tw[j]][j])%1000000000;
			else dp[i][j] = dp[i][j-1];
		}
	}
	printf("%d",dp[n][19]);
}