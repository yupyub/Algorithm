#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll INF = 987654321987654321;
int N,M,L;
int up[3000];
int down[3000];
ll dp[3000][3000][2];
ll dist(int i,int j){
	ll d = up[i]-down[j];
	d *= d;
	d += L*L;
	return d;
}
ll count(int i,int j,int flag){
	if(flag == 0)
		return (ll)(N+M-1);
	else
		return (ll)(i+j+1)*(N+M-i-j-1);
}
int main(){
	scanf("%d %d %d",&N,&M,&L);
	for(int i = 0;i<N;i++)
		scanf("%d",&up[i]);
	for(int j = 0;j<M;j++)
		scanf("%d",&down[j]);
	for(int i = 0;i<N;i++)
		for(int j = 0;j<M;j++)
			dp[i][j][0] = dp[i][j][1] = INF;

	dp[0][0][0] = dp[0][0][1] = dist(0,0) * count(0,0,0);
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			if(i>0){
				dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]+dist(i,j)*count(i,j,0));
				dp[i][j][1] = min(dp[i][j][1],dp[i-1][j][0]+dist(i,j)*count(i,j,1));	
			}
			if(j>0){
				dp[i][j][0] = min(dp[i][j][0],dp[i][j-1][1]+dist(i,j)*count(i,j,1));
				dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][1]+dist(i,j)*count(i,j,0));
			}
		}
	}
	printf("%lld\n",min(dp[N-1][M-1][0],dp[N-1][M-1][1]));
}