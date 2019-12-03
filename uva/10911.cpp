#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
double dp[1<<18];
int visit[18];
double x[18],y[18];
int n;
int cnt = 0;
double f(int bit){
	if(dp[bit] != 0) return dp[bit];
	double &ret = dp[bit];
	for(int i = 0;i<2*n-1;i++){
		for(int j = i+1;j<2*n;j++){
			int nxt = (bit|(1<<i))|(1<<j);	
			if(visit[i] == 0 && visit[j] == 0){
				visit[i] = visit[j] = 1;
				ret = min(ret,sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))+f(nxt));
				visit[i] = visit[j] = 0;
			}
		}
	}
	return ret;
}
int main(){
	int ca = 1;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		for(int i = 0;i<2*n;i++)
			scanf("%*s %lf %lf",&x[i],&y[i]);
		memset(dp,0,sizeof dp);
		printf("Case %d: ",ca++);
		double ans = 9654321;
		for(int i = 0;i<(1<<2*n);i++)
			if(dp[i] != 0) ans = min(ans,dp[i]);
		printf("%lf\n",ans);
	}
}