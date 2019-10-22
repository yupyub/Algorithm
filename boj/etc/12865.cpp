#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int,int> > item;
int dp[100001];
int main(){
	int n,k,w,v;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&w,&v);
		item.push_back(make_pair(w,v));
	}
	for(int i = 0;i<100001;i++){
		dp[i] = -1;
	}
	dp[0] = 0;
	/*
	for(int i = 0;i<n;i++){
		for(int j = k;j>=0;j--){
			if(j-item[i].first<0 || dp[j-item[i].first] == -1) continue;
			dp[j] = max(dp[j-item[i].first]+item[i].second,dp[j]);
		}
	}
	*/
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=k;j++){
			if(j+item[i].first>k || dp[j] == -1) continue;
			dp[j+item[i].first] = max(dp[j+item[i].first],dp[j]+item[i].second);
		}
	}
	int ans = 0;
	for(int i = 0;i<=k;i++){
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
}