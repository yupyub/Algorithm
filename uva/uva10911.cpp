#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
double dp[1<<16];
double x[16],y[16];
double dist[16][16];
int n;
double f(int bit){
	if(dp[bit] > -0.5) return dp[bit];
	if(bit == (1<<(2*n))-1) return dp[bit] = 0;
	double ret = 98765432.0;
	int p1,p2;
	for(p1 = 0;p1<2*n-1;p1++)
		if((bit&(1<<p1)) == 0) break;
	
	for(p2 = p1+1;p2<2*n;p2++)
		if((bit&(1<<p2)) == 0)
			ret = min(ret,dist[p1][p2]+f(bit|(1<<p1)|(1<<p2)));
	return dp[bit] = ret;
}
int main(){
	int ca = 1;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		for(int i = 0;i<2*n;i++)
			scanf("%*s %lf %lf",&x[i],&y[i]);
		for(int i = 0;i<2*n-1;i++)
			for(int j = i+1;j<2*n;j++)
				dist[i][j] = dist[j][i] = hypot(x[i]-x[j],y[i]-y[j]);
		for(int i = 0;i<(1<<16);i++) 
			dp[i] = -1.0;
		printf("Case %d: %.2lf\n",ca++,f(0));
	}
}