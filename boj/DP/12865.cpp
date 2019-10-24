#include <cstdio> // knapsack 문제
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
	for(int i = 0;i<n;i++){
		for(int j = k;j>=0;j--){ 
			// 역순으로 탐색하지 않으면, item[i]에 대해서 dp[j] 값을 갱신 한 후
			// 다시 dp[j+item[i].first]를 item[i]를 중복 사용해서 갱신한다.
			if(j-item[i].first<0 || dp[j-item[i].first] == -1) continue;
			dp[j] = max(dp[j-item[i].first]+item[i].second,dp[j]);
		}
	}
	int ans = 0;
	for(int i = 0;i<=k;i++){
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
}