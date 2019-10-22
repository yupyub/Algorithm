#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> >v;
vector<int>dp;
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	dp.resize(n+1);
	for(int i = 0;i<n;i++){
		dp[i] = 1;
		for(int j = 0;j<i;j++){
			if(v[i].second >v[j].second)
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int ans =0;
	for(int i = 0;i<n;i++){
		ans = max(ans,dp[i]);
	}
	printf("%d",n-ans);
}